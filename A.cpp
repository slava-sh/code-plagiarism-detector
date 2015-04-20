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

bool check(double size, double dist) {
    auto ratio = dist / size;
    return ratio < (size < 450 ? 0.228 : 0.35);
}

string read_file(const char *filename) {
    ifstream in(filename, ios::binary);
    ostringstream contents;
    contents << in.rdbuf();
    in.close();
    return contents.str();
}

istream& safe_getline(istream& in, string& s) {
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

string replace_all(string s, const string& a, const string& b) {
    int i = 0;
    while ((i = s.find(a, i)) != string::npos) {
         s.replace(i, a.length(), b);
         i += b.length();
    }
    return s;
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

bool starts_with(const string& t, const string& s) {
    if (t.size() > s.size()) {
        return false;
    }
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] != s[i]) {
            return false;
        }
    }
    return true;
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

bool is_identifier(char c) {
    return ('a' <= c && c <= 'z') ||
           ('A' <= c && c <= 'Z') ||
           ('0' <= c && c <= '9') ||
           c == '_';
}

string expand_ifdefs(const string& s) {
    static const string online_judge = "online_judge";
    static const string ifdef        = "#ifdef";
    static const string ifelse       = "#else";
    static const string endif        = "#endif";
    string result;
    vector< bool > defined;
    defined.push_back(true);
    for (int i = 0, n = s.size(); i < n; ++i) {
        if (defined.back()) {
            result += s[i];
        }
        if (ends_with(ifdef, s, i)) {
            if (defined.back()) {
                result.resize(result.size() - ifdef.size());
            }
            for (++i; i < n && !is_identifier(s[i]); ++i) {
            }
            string buf;
            for (; i < n && is_identifier(s[i]); ++i) {
                buf += s[i];
            }
            // --i; s[i] is a whitespace or )
            if (starts_with(online_judge, buf) && defined.back()) {
                defined.push_back(true);
            }
            else {
                defined.push_back(false);
            }
        }
        else if (defined.size() > 1 && ends_with(ifelse, s, i)) {
            if (defined.back()) {
                result.resize(result.size() - ifelse.size());
            }
            defined.back() = !defined.back();
        }
        else if (defined.size() > 1 && ends_with(endif, s, i)) {
            if (defined.back()) {
                result.resize(result.size() - endif.size());
            }
            defined.pop_back();
        }
    }
    return result;
}

string remove_comments(string code, const string& extension) {
    code = remove_c_comments(code);

    if (extension == "cs") {
        code = replace_all(code, "#if", "#ifdef");
    }
    else if (extension == "pas" || extension == "dpr") {
        code = replace_all(code, "{$", "#");
    }
    code = replace_all(code, "#ifndef local",  "#ifdef online_judge");
    code = replace_all(code, "#ifndef debug",  "#ifdef online_judge");
    code = replace_all(code, "#ifndef xdebug", "#ifdef online_judge");
    code = replace_all(code, "#ifndef",        "#ifdef not_");
    code = replace_all(code, "#elseif",        "#endif\n#ifdef");
    code = replace_all(code, "#elif",          "#endif\n#ifdef");
    code = replace_all(code, "#if defined",    "#ifdef");
    code = replace_all(code, "#ifdef defined", "#ifdef");
    code = expand_ifdefs(code);

    code = remove_nonnested(code, "#", "\n");
    if (extension == "d") {
        code = remove_nonnested(code, "/++", "+/");
    }
    else if (extension == "pas" || extension == "dpr") {
        code = remove_nonnested(code, "{", "}");
        code = remove_nonnested(code, "(*", "*)");
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

typedef vector< string > Tokens;

Tokens remove_java_throws(const Tokens& tokens) {
    Tokens result;
    int n = tokens.size();
    for (int i = 0; i < n; ++i) {
        result.push_back(tokens[i]);
        if (tokens[i] == ")" && i + 1 < n && tokens[i + 1] == "throws") {
            while (i + 1 < n && tokens[i + 1] != "{") {
                ++i;
            }
        }
    }
    return result;
}

Tokens fix_pascal_tokens(const Tokens& tokens) {
    Tokens result;
    for (int i = 0; i < tokens.size(); ++i) {
        auto token = tokens[i];
        if (token == "begin") {
            token = "{";
        }
        else if (token == "end") {
            token = "}";
        }
        else if (token == "=" && i > 0 && tokens[i - 1] == ":") {
            result.pop_back();
        }
        result.push_back(token);
    }
    return result;
}

Tokens tokenize(const string& s) {
    Tokens result;
    string buf;
    for (auto& c : s) {
        if (is_identifier(c)) {
            buf += c;
        }
        else {
            if (!buf.empty()) {
                result.push_back(buf);
            }
            if (!isspace(c) && c != ';') {
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

Tokens tokenize_python(const string& code) {
    Tokens result;
    stringstream ss(code);
    string line;
    int prev_spaces = 0;
    int step = 0;
    while (getline(ss, line)) {
        int spaces = 0;
        while (spaces < line.size() && isspace(line[spaces])) {
            ++spaces;
        }
        if (spaces == line.size()) {
            continue;
        }
        if (spaces > prev_spaces) {
            if (step == 0) {
                step = spaces - prev_spaces;
            }
            result.pop_back();
            result.push_back("{");
        }
        else if (spaces < prev_spaces) {
            for (int i = (prev_spaces - spaces) / step; i > 0; --i) {
                result.push_back("}");
            }
            if (spaces == 0) {
                step = 0;
            }
        }
        auto tokens = tokenize(line);
        result.insert(result.end(), tokens.begin(), tokens.end());
        prev_spaces = spaces;
    }
    if (prev_spaces > 0 && step > 0) {
        for (int i = prev_spaces / step; i > 0; --i) {
            result.push_back("}");
        }
    }
    return result;
}

map< string, int > base_id;

map< string, Tokens > extract_functions(const Tokens& tokens) {
    map< string, Tokens > result;
    int n = tokens.size();
    for (int i = 0; i < n; ++i) {
        auto& token = tokens[i];
        bool is_name = is_identifier(token[0]) && base_id.count(token) == 0;
        if (is_name && i + 1 < n && tokens[i + 1] == "(") {
            // Horrible
            int j = i + 2;
            int depth = 1;
            for (; depth > 0 && j < n; ++j) {
                if (tokens[j] == "(") {
                    ++depth;
                }
                else if (tokens[j] == ")") {
                    --depth;
                }
            }
            if (depth == 0 && j < n && tokens[j] == "{" && result.count(token) == 0) {
                Tokens body;
                int depth = 1;
                for (i = j + 1; depth > 0 && i < n; ++i) {
                    body.push_back(tokens[i]);
                    if (tokens[i] == "{") {
                        ++depth;
                    }
                    else if (tokens[i] == "}") {
                        --depth;
                    }
                }
                if (j < n && !body.empty()) {
                    body.pop_back();
                    result[token] = body;
                }
            }
        }
    }
    return result;
}

struct Solution {
    string filename;
    string code;
    map< string, int > id;
    vector< int > mess;
    bool is_grouped;

    Solution(): is_grouped(false) {}

    void create_mess() {
        static const string main = "main";

        auto extension = file_extension(filename);
        transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

        transform(code.begin(), code.end(), code.begin(), ::tolower);
        code = normalize_line_endings(code);
        code = remove_comments(code, extension);

        auto tokens = tokenize(code);
        if (extension == "py" || extension == "py2" || extension == "py3") {
            tokens = tokenize_python(code);
        }
        else if (extension == "java") {
            tokens = remove_java_throws(tokens);
        }
        else if (extension == "pas" || extension == "dpr") {
            tokens = fix_pascal_tokens(tokens);
        }

        auto functions = extract_functions(tokens);
        if (functions.count(main) != 0) {
            tokens = functions[main];
        }
        id = base_id;
        expand(tokens, functions);
    }

    void expand(const Tokens& tokens, map< string, Tokens >& functions) {
        int n = tokens.size();
        for (int i = 0; i < n; ++i) {
            auto token = tokens[i];
            if (isdigit(token[0])) {
                token = "0";
            }
            if (id.count(token) == 0) {
                if (is_identifier(token[0])) {
                    auto f = functions.find(token);
                    if (f != functions.end() && i + 1 < n && tokens[i + 1] == "(") {
                        // Spaghetti
                        int depth = 1;
                        for (i = i + 2; depth > 0 && i < n; ++i) {
                            if (tokens[i] == "(") {
                                ++depth;
                            }
                            else if (tokens[i] == ")") {
                                --depth;
                            }
                        }
                        if (depth == 0) {
                            auto body = f->second;
                            functions.erase(f);
                            expand(body, functions);
                            continue; // Tough!
                        }
                    }
                    else {
                        token = "0";
                    }
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
    for (auto x = column_start; x <= n2; ++x) {
        column[0] = x;
        auto last_diagonal = x - column_start;
        for (auto y = column_start; y <= n1; ++y) {
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
    Tokens special_tokens = {
        "0",
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
            safe_getline(cin, solution.filename);
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
            if (check(mess_size, dist)) {
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
