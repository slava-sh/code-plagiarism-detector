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

const int max_n = 22222, p = 39, mod = 1000000009;

int l, L1, L2, f[max_n], a[max_n], b[max_n], H1, H2;
long long pw[max_n], h[max_n];
string s;

int get_hash(int l, int r) {
    if (l == 0) {
        return h[r];
    }
    return ((h[r] - h[l - 1] * pw[r - l + 1]) % mod + mod) % mod;
}

void dfs(int poz, int fin) {
    if (poz < fin || f[fin] == 1 || f[poz] == 1) {
        return;
    }
    f[poz] = 1;
    if (poz >= L1 && H1 == get_hash(poz - L1, poz - 1)) {
        dfs(poz - L1, fin);
    }
    if (poz >= L2 && H2 == get_hash(poz - L2, poz - 1)) {
        dfs(poz - L2, fin);
    }
}

void clrdfs(int poz, int fin) {
    if (poz < fin || f[poz] == 0) {
        return;
    }
    f[poz] = 0;
    if (poz >= L1 && H1 == get_hash(poz - L1, poz - 1)) {
        clrdfs(poz - L1, fin);
    }
    if (poz >= L2 && H2 == get_hash(poz - L2, poz - 1)) {
        clrdfs(poz - L2, fin);
    }
}

int main() {
    pw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = (pw[i - 1] * p) % mod;
    }
    cin >> l >> s;
    for (int i = 0; i < s.length(); ++i) {
        a[s[i]] = 1;
    }
    h[0] = s[0] - 'a' + 1;
    for (int i = 0; i < s.length(); ++i) {
        h[i] = (h[i - 1] * p + s[i] - 'a' + 1) % mod;
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
    memset(a, 0, sizeof(a));
    for (int len = 1; len <= l && len <= s.length(); ++len) {
        int cnt;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != s[i % len]) {
                break;
            }
            cnt = (i + 1) / len;
        }
        H1 = get_hash(0, len - 1);
        L1 = len;
        for (int i = cnt; i <= cnt; ++i) {
            int poz = i * len;
            for (int len2 = 1; len2 <= l && poz + len2 <= s.length(); ++len2) {
                H2 = get_hash(poz, poz + len2 - 1);
                L2 = len2;
                dfs(s.length(), poz);
                if (f[poz] == 1) {
                    cout << 2 << endl;
                    cout << s.substr(0, len) << endl;
                    cout << s.substr(poz, len2) << endl;
                    return 0;
                }
                clrdfs(s.length(), poz);
            }
        }
    }
    cout << "3\na\nb\nc\n";
    return 0;
}
