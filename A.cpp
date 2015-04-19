#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
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

struct Solution {
    string filename;
    string code;
};

string remove_c_comments(const string& s) {
    string result;
    char prev = '\n';
    bool in_line_comment = false;
    bool in_multiline_comment = false;
    for (auto& c : s) {
        if (!in_multiline_comment && !in_line_comment) {
            result += c;
        }
        if (in_multiline_comment && prev == '*' && c == '/') {
            in_multiline_comment = false;
        }
        if (in_line_comment && c == '\n') {
            in_line_comment = false;
        }
        if (prev == '/' && c == '*' && !in_line_comment) {
            in_multiline_comment = true;
            result.resize(result.size() - 2);
        }
        if (prev == '/' && c == '/' && !in_multiline_comment) {
            in_line_comment = true;
            result.resize(result.size() - 2);
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
        auto c = s[i];
        if (depth == 0) {
            result += c;
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

string filter(function< bool(char) > p, const string& s) {
    string result;
    for (auto& c : s) {
        if (p(c)) {
            result += c;
        }
    }
    return result;
}

string normalize_numbers(const string& s) {
    string result;
    bool prev_digit = false;
    for (auto& c : s) {
        bool cur_digit = isdigit(c);
        if (!cur_digit) {
            result += c;
        }
        else if (!prev_digit) {
            result += '0';
        }
        prev_digit = cur_digit;
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

string normalize_code(string code) {
    code = normalize_line_endings(code);
    code = remove_c_comments(code);
    code = remove_nested(code, "#ifdef", "#endif");
    code = remove_nonnested(code, "#", "\n");
    code = filter([](char c) { return !isspace(c); }, code);
    code = normalize_numbers(code);
    code = filter([](char c) { return c != ';'; }, code);
    return code;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector< Solution > solutions(n);
    cout << n << "\n";
    for (auto& solution : solutions) {
        do {
            safeGetline(cin, solution.filename);
        } while (solution.filename.empty());
        solution.code = read_file(solution.filename.c_str());
        solution.code = normalize_code(solution.code);
        cout << solution.filename << ":\n";
        cout << solution.code << "\n";
        cout << "\n";
    }
    return 0;
}
