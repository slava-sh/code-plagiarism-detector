#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
using namespace std;

string read_file(const char *filename) {
    ifstream in(filename, ios::binary);
    ostringstream contents;
    contents << in.rdbuf();
    in.close();
    return contents.str();
}

istream& safeGetline(istream& in, string& s) {
    s.clear();
    auto buf = in.rdbuf();
    for (bool eol = false; !eol;) {
        int c = buf->sbumpc();
        switch (c) {
        case '\n':
            eol = true;
            break;
        case '\r':
            if (buf->sgetc() == '\n') {
                buf->sbumpc();
            }
            eol = true;
            break;
        case EOF:
            if (s.empty()) {
                in.setstate(ios::eofbit);
            }
            eol = true;
            break;
        default:
            s += (char) c;
        }
    }
    return in;
}

string file_extension(const string& filename) {
    auto i = filename.rfind('.');
    if (i == string::npos) {
        return filename;
    }
    return filename.substr(i + 1);
}

string remove_c_comments(const string& s) {
    string result;
    char prev = '\n';
    bool in_line_comment = false;
    bool in_multiline_comment = false;
    for (auto& c : s) {
        if (!in_multiline_comment && !in_line_comment) {
            result += c;
        }
        if (in_multiline_comment) {
            if (prev == '*' && c == '/') {
                in_multiline_comment = false;
            }
        }
        else if (in_line_comment) {
            if (c == '\n') {
                in_line_comment = false;
            }
        }
        else {
            if (prev == '/' && c == '*') {
                in_multiline_comment = true;
                result.resize(result.size() - 2);
            }
            else if (prev == '/' && c == '/') {
                in_line_comment = true;
                result.resize(result.size() - 2);
            }
        }
        prev = c;
    }
    return result;
}

bool ends_with(const string& t, const string& s, int n) {
    if (n < t.size() - 1) {
        return false;
    }
    for (int i = 0; i < t.size(); ++i) {
        if (t[t.size() - 1 - i] != s[n - i]) {
            return false;
        }
    }
    return true;
}

string remove_general(const string& s, const string& begin, const string& end,
        bool nested) {
    string result;
    int depth = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (depth == 0) {
            result += s[i];
        }
        if (ends_with(begin, s, i)) {
            if (depth == 0) {
                result.resize(result.size() - begin.size());
            }
            if (depth == 0 || nested) {
                ++depth;
            }
        }
        else if (depth > 0 && ends_with(end, s, i)) {
            --depth;
        }
    }
    return result;
}

string remove_nested(const string& s, const string& begin, const string& end) {
    return remove_general(s, begin, end, true);
}

string remove_nonnested(const string& s, const string& begin, const string& end) {
    return remove_general(s, begin, end, false);
}

string remove_comments(string code, const string& filename) {
    auto extension = file_extension(filename);
    transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    code = remove_c_comments(code);
    code = remove_nested(code, "#ifdef", "#endif");
    code = remove_nonnested(code, "#", "\n");
    if (extension == "d") {
        code = remove_nonnested(code, "/++", "+/");
    }
    else if (extension == "pas" || extension == "dpr") {
        code = remove_nested(code, "{$ifdef", "{$endif}");
        code = remove_nonnested(code, "{", "}");
    }
    else if (extension == "hs") {
        code = remove_nested(code, "{-", "-}");
        code = remove_nonnested(code, "--", "\n");
    }
    return code;
}

string filter(function< bool(char) > p, const string& s) {
    string result;
    for (auto& c : s) {
        if (p(c)) {
            result += c;
        }
    }
    return result;
}

string normalize_line_endings(string s) {
    for (auto& c : s) {
        if (c == '\r') {
            c = '\n';
        }
    }
    return s;
}

vector< string > tokenize(const string& s) {
    vector< string > result;
    string buf;
    for (auto& c : s) {
        if (isalnum(c)) {
            buf += c;
        }
        else {
            if (!buf.empty()) {
                result.push_back(buf);
            }
            if (!isspace(c)) {
                buf = c;
                result.push_back(buf);
            }
            buf.clear();
        }
    }
    if (!buf.empty()) {
        result.push_back(buf);
    }
    return result;
}

struct Solution {
    string filename;
    string code;
    vector< int > mess;
    bool is_grouped;

    Solution(): is_grouped(false) {}

    void create_mess() {
        transform(code.begin(), code.end(), code.begin(), ::tolower);
        code = normalize_line_endings(code);
        code = remove_comments(code, filename);

        auto tokens = tokenize(code);
        map< string, int > id;
        id["0"] = 0;
        id["a"] = 1;
        for (auto& token : tokens) {
            if (isdigit(token[0])) {
                token = "0";
            }
            else if (isalnum(token[0])) {
                token = "a";
            }
            else if (token == ";" ||
                     token == "{" ||
                     token == "}" ||
                     token == "(" ||
                     token == ")") {
                continue;
            }
            if (id.count(token) == 0) {
                id[token] = id.size();
            }
            mess.push_back(id[token]);
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector< Solution > solutions(n);
    for (auto& solution : solutions) {
        do {
            safeGetline(cin, solution.filename);
        } while (solution.filename.empty());
        solution.code = read_file(solution.filename.c_str());
        solution.create_mess();
        // cout << solution.filename << ":\n";
        // cout << solution.code << "\n";
        // for (auto i : solution.mess) { cout << i << " "; }
        // cout << "\n";
    }

    vector< set< string > > ans;
    for (auto i = solutions.begin(); i != solutions.end(); ++i) {
        if (i->is_grouped) {
            continue;
        }
        set< string > group;
        for (auto j = i + 1; j != solutions.end(); ++j) {
            if (j->mess == i->mess) {
                group.insert(j->filename);
                j->is_grouped = true;
            }
        }
        if (!group.empty()) {
            group.insert(i->filename);
            ans.push_back(group);
        }
    }

    cout << ans.size() << "\n";
    for (auto& group : ans) {
        bool first = true;
        for (auto& filename : group) {
            if (first) {
                first = false;
            }
            else {
                cout << " ";
            }
            cout << filename;
        }
        cout << "\n";
    }
    return 0;
}
