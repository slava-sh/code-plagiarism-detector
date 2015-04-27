#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

string s;
long long hash1[1000000];
long long pp1[1000000];
long long hash2[1000000];
long long pp2[1000000];
int n;
const int p1 = 239;
const int MOD1 = 1000000007;
const int p2 = 101;
const int MOD2 = 1000000009;

long long h1(int L, int R) {
    return ((hash1[R] - hash1[L] * pp1[R - L]) % MOD1 + MOD1) % MOD1;
}

long long h2(int L, int R) {
    return ((hash2[R] - hash2[L] * pp2[R - L]) % MOD2 + MOD2) % MOD2;
}

int main() {
    int L;
    cin >> L;
    bool containsC = false;
    cin >> s;
    n = s.length();
    pp1[0] = 1;
    pp2[0] = 1;
    hash1[0] = 0;
    hash2[0] = 0;
    set<char> hs;
    for (int i = 0; i < n; i++) {
        pp1[i + 1] = (pp1[i] * p1) % MOD1;
        pp2[i + 1] = (pp2[i] * p2) % MOD2;
        hash1[i + 1] = (hash1[i] * p1 + ((int) s[i])) % MOD1;
        hash2[i + 1] = (hash2[i] * p2 + ((int) s[i])) % MOD2;
        hs.insert(s[i]);
    }

    for (int i = 1; i <= L; i++) {
        if (n % i == 0) {
            long long hf1 = h1(0, i);
            long long hf2 = h2(0, i);
            bool flag = true;
            for (int j = 0; j < n; j += i) {
                if (h1(j, j + i) != hf1 || h2(j, j + i) != hf2) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << (1) << endl;
                cout << (s.substr(0, i)) << endl;
                return 0;
            }
        }
    }

    if (hs.size() == 2) {
        cout << (2);
        for (char x : hs) {
            cout << (x) << endl;
        }
    } else {
        bool dp[1000000];
        for (int i = 1; i <= L; i++) {
            long long hf1 = h1(0, i);
            long long hf2 = h2(0, i);
            int i1 = 0;
            while (i1 + i <= n && h1(i1, i1 + i) == hf1 && h2(i1, i1 + i) == hf2) {
                i1 += i;
            }
            for (int j = 1; j <= L; j++) {
                if (i1 + j <= n) {
                    long long hs1 = h1(i1, i1 + j);
                    long long hs2 = h2(i1, i1 + j);
                    memset(dp, false, sizeof(dp));
                    dp[0] = true;
                    for (int k = 0; k < n; k++) {
                        if (dp[k]) {
                            if (k + i <= n && h1(k, k + i) == hf1 && h2(k, k + i) == hf2) {
                                dp[k + i] = true;
                            }
                            if (k + j <= n && h1(k, k + j) == hs1 && h2(k, k + j) == hs2) {
                                dp[k + j] = true;
                            }
                        }
                    }
                    if (dp[n]) {
                        cout << (2) << endl;
                        cout << (s.substr(0, i)) << endl;
                        cout << (s.substr(i1, i1 + j)) << endl;
                        return 0;
                    }
                }
            }
        }
        cout << (3) << endl;
        cout << ("a") << endl;
        cout << ("b") << endl;
        cout << ("c") << endl;
    }
}

