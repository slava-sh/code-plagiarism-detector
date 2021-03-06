#include <iostream>
#include <cstdio>

using namespace std;

int next[100000][26], leaf[100000], sz;

void init () {
    sz = 0;
    for (int i = 0; i < 10; ++i) next[0][i] = -1;
    leaf[sz] = 0;
    ++sz;
}


void add(string s, string t) {
    int v = 0;
    for (int i = 0; i < s.length (); ++i) {
        if (next[v][s[i] - '0'] == -1) {
            next[v][s[i] - '0'] = sz;
            for (int i = 0; i < 10; ++i) next[sz][i] = -1;
            leaf[sz] = 0;
            sz++;
        }
        v = next[v][s[i] - '0'];
    }
    leaf[v] = 1;
    for (int i = 0; i < t.length (); ++i) {
        if (next[v][t[i] - '0'] == -1) {
            next[v][t[i] - '0'] = sz;
            for (int i = 0; i < 10; ++i) next[sz][i] = -1;
            leaf[sz] = 0;
            sz++;
        }
        v = next[v][t[i] - '0'];
    }
    leaf[v] = 2;
}

int main () {
    freopen ("numbers.in", "r", stdin);
    freopen ("numbers.out", "w", stdout);
    int n;
    cin >> n;
    init();
    for (int i = 0; i < n; ++i) {
        string c;
        int m;
        cin >> c >> m;
        for (int j = 0; j < m; ++j) {
            string s;
            cin >> s;
            add (c, s);
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int v = 0;
        int p = -1;
        int c = 0;
        for (int i = 0; i < s.length (); ++i) {
            if (next[v][s[i] - '0'] != -1) v = next[v][s[i] - '0'];
            else break;
            if (leaf[v] == 1) {
                c = i;
            }
            if (leaf[v] == 2) {
                    p = i + 1;
                    break;
            }
        }
        if (p == -1 || s[p] == '0') {
            cout << "Incorrect\n";
            continue;
        }
        else {
            if (s.length () - p - 1 < 3 || s.length () - p - 1 > 7) {
                cout << "Incorrect\n";
                continue;
            }
            cout << '+';
            for (int i = 0; i <= c; ++i) cout << s[i];
            cout << '(';
            for (int i = c + 1; i < p; ++i) cout << s[i];
            cout << ')';
            if (s.length () - p == 3)
                cout << s[p] << s[p + 1] << s[p + 2];
            else if (s.length () - p == 4)
                cout << s[p] << s[p + 1] << "-" << s[p + 2] << s[p + 3];
            else if (s.length () - p == 5)
                cout << s[p] << s[p + 1] << s[p + 2] << "-" << s[p + 3] << s[p + 4];
            else if (s.length () - p == 6)
                cout << s[p] << s[p + 1] << "-" << s[p + 2] << s[p + 3] << "-" << s[p + 4] << s[p + 5];
            else if (s.length () - p == 7)
                cout << s[p] << s[p + 1] << s[p + 2] << "-" << s[p + 3] << s[p + 4] << "-" << s[p + 5] << s[p + 6];
        }
        cout << endl;
    }
}
