#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string s[567];

int dp[2][567][567];

int main() {
//    freopen("input.txt", "r", stdin);
    int n, m, mod;
    cin >> n >> m >> mod;
    for (int i = 1; i <= m; ++i) {
        cin >> s[i];
        s[i] = '#' + s[i];
    }
    int one = 0, two = 0;
    for (int i = 1; i <= n; ++i) {
        int a = 0;
        for (int j = 1; j <= m; ++j)
            if (s[j][i] == '1')
                ++a;
        if (a == 1) ++one;
        else if (a == 0) ++two;
    }    
    n = n - m;
    cerr << "one = " << one << " two = " << two << " n = " << n << '\n';
    dp[0][n][0] = 1;
    int f = 0;
    for (int i = 0; i < two; ++i) {
        memset(dp[f ^ 1], 0, sizeof(dp[f ^ 1]));
        for (int r0 = 0; r0 <= n; ++r0)
            for (int r1 = 0; r0 + r1 <= n; ++r1) {
                if (dp[f][r0][r1] == 0) continue;
                if (r0 >= 2) {
                    dp[f ^ 1][r0 - 2][r1 + 2] = (dp[f ^ 1][r0 - 2][r1 + 2] + 1LL * dp[f][r0][r1] * r0 * (r0 - 1) / 2) % mod;
                }
                if (r0 >= 1 && r1 >= 1) {
                    dp[f ^ 1][r0 - 1][r1] = (dp[f ^ 1][r0 - 1][r1] + 1LL * dp[f][r0][r1] * r0 * r1) % mod;
                }
                if (r1 >= 2) {
                    dp[f ^ 1][r0][r1 - 2] = (dp[f ^ 1][r0][r1 - 2] + 1LL * dp[f][r0][r1] * r1 * (r1 - 1) / 2) % mod;
                }
            }
        f ^= 1;
    }
    for (int i = 0; i < one; ++i) {
        memset(dp[f ^ 1], 0, sizeof(dp[f ^ 1]));
        for (int r0 = 0; r0 <= n; ++r0)
            for (int r1 = 0; r0 + r1 <= n; ++r1) {
                if (dp[f][r0][r1] == 0) continue;
                if (r0 >= 1) {
                    dp[f ^ 1][r0 - 1][r1 + 1] = (dp[f ^ 1][r0 - 1][r1 + 1] + 1LL * dp[f][r0][r1] * r0) % mod;
                }
                if (r1 >= 1) {
                    dp[f ^ 1][r0][r1 - 1] = (dp[f ^ 1][r0][r1 - 1] + 1LL * dp[f][r0][r1] * r1) % mod;
                }
            }
        f ^= 1;
    }
    cout << dp[f][0][0] % mod;
}