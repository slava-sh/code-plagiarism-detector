#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 22222, inf = 1011111111;

int l, f[max_n], a[max_n];
string s;

int main() {
    cin >> l >> s;
    for (int i = 0; i < s.length(); ++i) {
        a[s[i]] = 1;
    }
    for (int len = 1; len <= l && len <= s.length(); ++len) {
        if (s.length() % len == 0) {
            int f = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] != s[i % len]) {
                    f = 1;
                    break;
                }
            }
            if (f == 0) {
                cout << 1 << endl << s.substr(0, len) << endl;
                return 0;
            }
        }
    }
    if (a['a'] == 0) {
        cout << "2\nb\nc\n";
        return 0;
    }
    if (a['b'] == 0) {
        cout << "2\na\nc\n";
        return 0;
    }
    if (a['c'] == 0) {
        cout << "2\na\nb\n";
        return 0;
    }
    return 0;
}
