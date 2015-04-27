#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

const int N = 503 + 9;
int dp[2][N][N];
int mod;
typedef long long LL;
void add(int & a, LL b) {
    b %= mod;
    a += b;

    if(a >= mod) {
        a %= mod;
    }
}
int cnt[N];
LL C[N];
int main() {
    int i, j, k, n, m;
    cin >> n >> m >> mod;
    string str;

    for(i = 1; i <= n; ++i) {
        C[i] = i * (i - 1) / 2;
    }

    for(i = 0; i < m; ++i) {
        cin >> str;

        for(j = 0; j < str.length(); ++j) {
            if(str[j] == '1') {
                ++cnt[j];
            }
        }
    }

    int one = 0, zero = 0;

    for(i = 0; i < n; ++i) {
        if(cnt[i] == 0) {
            ++zero;
        } else if(cnt[i] == 1) {
            ++one;
        }
    }

    int pre = 0, cur = 1;
    dp[cur][zero][one] = 1;

    for(i = m; i < n; ++i) {
        swap(pre, cur);
        memset(dp[cur], 0, sizeof(dp[0]));

        for(j = 0; j <= n; ++j) {
            for(k = 0; k + j <= n; ++k) {
                int & r = dp[pre][j][k];

                if(!r) {
                    continue;
                }

                if(j >= 2) {
                //    00 == > 11
                    add(dp[cur][j - 2][k + 2], r * C[j]);
                }

                if(k >= 2) {
                    add(dp[cur][j][k - 2], r * C[k]);
                }

                if(j >= 1 && k >= 1) {
                    add(dp[cur][j - 1][k], 1LL * r * j * k);
                }
            }
        }
    }

    int ans = 0;

    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            add(ans, dp[cur][i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}
