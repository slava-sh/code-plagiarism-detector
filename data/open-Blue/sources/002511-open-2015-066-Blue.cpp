#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define prev prev_
#define next next_

const int INF = (int)1e9;

int abs_(int x) {
    return max(x, -x);
}

const int maxN = 1 << 15;

ll MOD[2] = {(ll)1e9 + 9, (ll)1e9 + 7};

struct Str {
    ll H[2][maxN];
    ll p_pow[2][maxN];
    ll p = 997;
    Str (string s) {
        for (int t = 0; t < 2; t++) {
            H[t][0] = 0;
            p_pow[t][0] = 1;
            for (int i = 0; i < s.size(); i++) {
                p_pow[t][i + 1] = (p_pow[t][i] * p) % MOD[t];
                H[t][i + 1] = (H[t][i] * p + s[i]) % MOD[t];
            }
        }
    }
    ll get(int l, int r, int t) {
        return (p_pow[t][r - l + 1] * H[t][l] - H[t][r + 1] + MOD[t]) % MOD[t];
    }
    ll get(int l, int r) {
        return (get(l, r, 0) << 32) | get(l, r, 1);
    }
};

int main() {
    #define task "a"
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int l;
    string s;
    cin >> l>> s;
    int n = sz(s);
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1];
        while (p[i] && s[p[i]] != s[i]) {
            p[i] = p[p[i] - 1];
        }
        if (s[i] == s[p[i]]) {
            p[i]++;
        }
    }
    int len = n - p[n - 1];
    if (n % len != 0) {
        len = n;
    }
    Str s2(s);
    if (len <= l) {
        cout << 1 << endl;
        cout << s.substr(0, len) << endl;
        return 0;
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= l && i + j <= n; j++) {
                vector<int> dp(n + 1);
                int i2 = i - p[i - 1];
                if (i % i2 != 0) {
                    i2 = i;
                }
                if (i2 > l) {
                    continue;
                }
                dp[i + j] = 1;
                ll h1 = s2.get(0, i2 - 1);
                ll h2 = s2.get(i, i + j - 1);
                for (int k = i + j; k < n; k++) {
                    if (j + k <= n && s2.get(k, k + j - 1) == h2) {
                        dp[j + k] |= dp[k];
                    }
                    if (i2 + k <= n && s2.get(k, k + i2 - 1) == h1) {
                        dp[i2 + k] |= dp[k];
                    }
                }
                if (dp[n]) {
                    cout << 2 << endl;
                    cout << s.substr(0, i2) << endl;
                    cout << s.substr(i, j) << endl;
                    return 0;
                }
            }
        }
    }
        cout << 3 << endl;
        cout << "a" << endl;
        cout << "b" << endl;
        cout << "c" << endl;
    return 0;
}
