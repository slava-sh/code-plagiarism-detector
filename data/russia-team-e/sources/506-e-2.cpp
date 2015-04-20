#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <map>

using namespace std;

ifstream fin("numbers.in");
ofstream fout("numbers.out");

void f(string s) {
    if (s.size() == 3) {
        fout << s;
    }
    if (s.size() == 4) {
        fout << s[0] << s[1] << '-';
        fout << s[2] << s[3];
    }
    if (s.size() == 5) {
        fout << s[0] << s[1] << s[2] << '-' << s[3] << s[4];
    }
    if (s.size() == 6) {
        fout << s[0] << s[1] << '-' << s[2] << s[3] << '-' << s[4] << s[5];
    }
    if (s.size() == 7) {
        fout << s[0] << s[1] << s[2] << '-';
        fout << s[3] << s[4] << '-' ;
        fout << s[5] << s[6];
    }

}

int main() {
    int n, m;
    map<string,set<string> > a;
    vector<string> code;
    fin >> n;
    string c, s;
    for (int i = 0; i < n; ++i) {
        fin >> c >> m;
        for (int j = 0; j < m; ++j) {
            fin >> s;
            a[c].insert(s);
        }
    }
    fin >> m;
    string num;
    //*
    for (int i = 0; i < m; ++i) {
        fin >> num;
        bool mark = false;
        for (int l = 1; l <= 3 && !mark; ++l) {
            if (a[num.substr(0, l)].size() == 0) {
                continue;
            }
            for (int l2 = 3; l2 <= 5; ++l2) {
                if (a[num.substr(0, l)].find(num.substr(l, l2)) != a[num.substr(0, l)].end()) {
                    fout << '+';
                    fout << num.substr(0, l) << '(';
                    fout << num.substr(l, l2) << ')';
                    f(num.substr(l + l2, num.size() - l - l2));
                    fout << endl;
                    mark = true;
                    break;
                }
            }
        }
        if (!mark) {
            fout << "Incorrect\n";
        }
    }
    //*/
    return 0;
}
