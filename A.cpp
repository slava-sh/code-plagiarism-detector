#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <functional>
#include <algorithm>
using namespace std;

const int MAX_DIST = 100;
const double MAX_DIST_RATIO = 0.2;

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
    char prev = ' ';
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

map< string, int > base_id;

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
        auto id = base_id;
        for (auto& token : tokens) {
            if (isdigit(token[0])) {
                token = "0";
            }
            if (id.count(token) == 0) {
                if (isalnum(token[0])) {
                    token = "a";
                }
                else {
                    id[token] = id.size();
                }
            }
            mess.push_back(id[token]);
        }
    }
};

int levenshtein_distance(const vector< int >& s1, const vector< int >& s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    int column_start = 1;
    auto column = new int[n1 + 1];
    iota(column + column_start, column + n1 + 1, column_start);
    for (auto x = column_start; x <= n2; x++) {
        column[0] = x;
        auto last_diagonal = x - column_start;
        for (auto y = column_start; y <= n1; y++) {
            auto old_diagonal = column[y];
            auto possibilities = {
                column[y] + 1,
                column[y - 1] + 1,
                last_diagonal + (s1[y - 1] == s2[x - 1]? 0 : 1)
            };
            column[y] = min(possibilities);
            last_diagonal = old_diagonal;
        }
    }
    auto result = column[n1];
    delete[] column;
    return result;
}

int main() {
    vector< string > special_tokens = {
        "0", "a",
        "\"", "'", "!", "#", "$", "%", "&", "(", ")", "*", "+", ",", "-", ".",
        "/", ":", ";", "<", "=", ">", "?", "@", "[", "\\", "]", "^", "_", "`",
        "{", "|", "}", "~", "break", "case", "class", "continue", "def",
        "default", "elif", "else", "enum", "except", "extern", "finally",
        "for", "goto", "if", "lambda", "new", "print", "return", "sizeof",
        "struct", "switch", "try", "typedef", "union", "while", "with", "yield",
    };
    for (auto& token : special_tokens) {
        base_id[token] = base_id.size();
    }
    base_id["'"] = base_id["\""];

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
    }

    vector< set< string > > ans;
    for (auto i = solutions.begin(); i != solutions.end(); ++i) {
        if (i->is_grouped) {
            continue;
        }
        set< string > group;
        for (auto j = i + 1; j != solutions.end(); ++j) {
            if (j->is_grouped) {
                continue;
            }
            auto dist = levenshtein_distance(i->mess, j->mess);
            auto mess_size = (double) (i->mess.size() + j->mess.size()) / 2;
            auto dist_ratio = (double) dist / mess_size;
            if (dist <= MAX_DIST && dist_ratio <= MAX_DIST_RATIO) {
                // cerr << (dist <= MAX_DIST) + 0 << " " << dist << " " << mess_size << " " <<  << endl;
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
