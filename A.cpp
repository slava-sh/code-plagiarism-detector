#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <functional>
#include <algorithm>
using namespace std;

const int    MAX_FINGERPRINT_SIZE = 5000;
const double NORMAL_LO            = 0.228;
const double NORMAL_HI            = 0.35;
const double NORMAL_PEAK          = 580;
const double NORMAL_BOOST         = 0.03;
const double SMALL_THRESHOLD      = 350;
const double SMALL_BOOST          = 0.0228;

struct SigmoidClassifier {
    const double lo;
    const double hi;
    const double peak;
    const double boost;

    SigmoidClassifier(double lo, double hi, double peak, double boost):
        lo(lo), hi(hi), peak(peak), boost(boost) {}

    bool classify(double x, double y) const {
        return (y - lo) * (1 + exp(-boost * (x - peak))) < hi - lo;
    }
};

const SigmoidClassifier normal_classifier(NORMAL_LO, NORMAL_HI, NORMAL_PEAK, NORMAL_BOOST);
const SigmoidClassifier small_classifier(-NORMAL_LO, NORMAL_LO, 0, SMALL_BOOST);

bool classify(double size, double ratio) {
    auto& classifier = size < SMALL_THRESHOLD ? small_classifier : normal_classifier;
    return classifier.classify(size, ratio);
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
            --i;
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
        else if (token == "=" && !result.empty() && result.back() == ":") {
            result.pop_back();
        }
        result.push_back(token);
    }
    return result;
}

Tokens pascal_insert_main(Tokens tokens) {
    static const Tokens main_declaration = { "main", "(", ")" };
    for (int i = tokens.size() - 1; i >= 0; --i) {
        if (tokens[i] == "}") {
            int depth = 1;
            int j = i - 1;
            for (; j >= 0; --j) {
                if (tokens[j] == "}") {
                    ++depth;
                }
                else if (tokens[j] == "{") {
                    --depth;
                    if (depth == 0) {
                        break;
                    }
                }
            }
            if (depth == 0 && j >= 0) {
                tokens.insert(tokens.begin() + j, main_declaration.begin(),
                        main_declaration.end());
            }
            break;
        }
    }
    return tokens;
}

Tokens fix_pascal_functions(const Tokens& tokens) {
    Tokens result;
    int n = tokens.size();
    for (int i = 0; i < n; ++i) {
        auto& token = tokens[i];
        if (token == "function" || token == "procedure") {
            ++i;
            if (i < n) {
                result.push_back(tokens[i]);
                result.push_back("(");
                result.push_back(")");
                while (i + 1 < n && tokens[i + 1] != "{") {
                    ++i;
                }
            }
        }
        else {
            result.push_back(token);
        }
    }
    return pascal_insert_main(result);
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
    int prev_spaces = 0;
    int step = 0;
    stringstream ss(code);
    string line;
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

map< string, int > common_token_id;

map< string, Tokens > extract_functions(const Tokens& tokens) {
    map< string, Tokens > result;
    int n = tokens.size();
    for (int i = 0; i < n; ++i) {
        auto& token = tokens[i];
        bool is_name = is_identifier(token[0]) && common_token_id.count(token) == 0;
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
                for (i = j + 1; i < n; ++i) {
                    body.push_back(tokens[i]);
                    if (tokens[i] == "{") {
                        ++depth;
                    }
                    else if (tokens[i] == "}") {
                        --depth;
                        if (depth == 0) {
                            break;
                        }
                    }
                }
                if (i < n && !body.empty()) {
                    body.pop_back();
                    result[token] = body;
                }
            }
        }
    }
    return result;
}

struct Solution {
    int id;
    string filename;
    string code;
    map< string, int > token_id;
    vector< int > fingerprint;

    void create_fingerprint() {
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
            tokens = fix_pascal_functions(tokens);
        }

        auto functions = extract_functions(tokens);
        if (functions.count(main) != 0) {
            tokens = functions[main];
        }
        token_id = common_token_id;
        expand(tokens, functions);
        if (fingerprint.size() > MAX_FINGERPRINT_SIZE) {
            fingerprint.resize(MAX_FINGERPRINT_SIZE);
        }
    }

    void expand(const Tokens& tokens, map< string, Tokens >& functions) {
        int n = tokens.size();
        for (int i = 0; i < n; ++i) {
            auto token = tokens[i];
            if (isdigit(token[0])) {
                token = "0";
            }
            if (token_id.count(token) == 0) {
                if (is_identifier(token[0])) {
                    auto f = functions.find(token);
                    if (f != functions.end() && i + 1 < n && tokens[i + 1] == "(") {
                        // Spaghetti
                        int depth = 1;
                        for (i = i + 2; i < n; ++i) {
                            if (tokens[i] == "(") {
                                ++depth;
                            }
                            else if (tokens[i] == ")") {
                                --depth;
                                if (depth == 0) {
                                    break;
                                }
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
                    token_id[token] = token_id.size();
                }
            }
            fingerprint.push_back(token_id[token]);
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

struct DSU {
    vector< int > parent;
    vector< int > size;

    DSU(int size): parent(size, -1), size(size, 1) {}

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int find(int x) {
        if (parent[x] == -1) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    vector< vector< int > > groups() {
        map< int, vector< int > > groups;
        for (int i = 0; i < parent.size(); ++i) {
            int x = find(i);
            if (size[x] > 1) {
                groups[x].push_back(i);
            }
        }
        vector< vector< int > > result;
        for (auto& group : groups) {
            result.push_back(group.second);
        }
        return result;
    }
};

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
        common_token_id[token] = common_token_id.size();
    }
    common_token_id["'"] = common_token_id["\""];

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector< Solution > solutions(n);
    for (int i = 0; i < n; ++i) {
        auto& solution = solutions[i];
        solution.id = i;
        do {
            safe_getline(cin, solution.filename);
        } while (solution.filename.empty());
        solution.code = read_file(solution.filename.c_str());
        solution.create_fingerprint();
    }

#ifdef DEBUG
    set< pair< string, string > > right_pairs;
    {
        ifstream ans("../ans.txt");
        int n;
        ans >> n;
        for (int k = 0; k < n; ++k) {
            string line;
            do {
                safe_getline(ans, line);
            } while (line.empty());
            istringstream iss(line);
            vector< string > files {
                istream_iterator< string >{ iss },
                istream_iterator< string >{}
            };
            sort(files.begin(), files.end());
            for (auto i = files.begin(); i != files.end(); ++i) {
                for (auto j = i + 1; j != files.end(); ++j) {
                    right_pairs.insert(make_pair(*i, *j));
                }
            }
        }
        ans.close();
    }

    ofstream data_tsv("../data.tsv");
    data_tsv << "Ans\tGuess\tSize\tDistRatio\tDist\tI\tJ" << endl;
#endif

    DSU ans(solutions.size());
    for (auto i = solutions.begin(); i != solutions.end(); ++i) {
        for (auto j = i + 1; j != solutions.end(); ++j) {
            auto dist = levenshtein_distance(i->fingerprint, j->fingerprint);
            auto size = (double) (i->fingerprint.size() + j->fingerprint.size()) / 2;
            auto ratio = dist / size;
            bool similar = classify(size, ratio);
            if (similar) {
                ans.unite(i->id, j->id);
            }

#ifdef DEBUG
            bool right_ans;
            {
                auto key = make_pair(i->filename, j->filename);
                if (key.first > key.second) {
                    swap(key.first, key.second);
                }
                right_ans = right_pairs.count(key) != 0;
            }
            data_tsv << right_ans + 0 << "\t"
                     << similar + 0 << "\t"
                     << size << "\t"
                     << (double) dist / size << "\t"
                     << dist << "\t"
                     << i->filename << "\t"
                     << j->filename << endl;
#endif
        }
    }

#ifdef DEBUG
    data_tsv.close();
#endif

    auto groups = ans.groups();
    cout << groups.size() << "\n";
    for (auto& group : groups) {
        bool first = true;
        for (auto& id : group) {
            if (first) {
                first = false;
            }
            else {
                cout << " ";
            }
            cout << solutions[id].filename;
        }
        cout << "\n";
    }
    return 0;
}
