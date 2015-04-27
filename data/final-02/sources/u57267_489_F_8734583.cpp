/* Daca nu iau totul mai bine nu ma complic
Nu sunt de liga a doua, eu joc in Champions League */

#include <vector>
#include <map>
#include <set>
#include <deque>
#include <bitset>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

template<class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<class T> void chmax(T &t, const T &f) { if (t < f) t = f; }

using namespace std;

int f[555];
char tmp[555];
int dp[555][555];

int comb(int x, int mod) {
    return ((long long)x * (x - 1) / 2) % mod;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int n, m, mod;
    scanf("%d%d%d\n", &n, &m, &mod);
    for (int i = 1; i <= n; ++i)
        f[i] = 2;
    for (int i = 1; i <= m; ++i) {
        gets(tmp + 1);
        for (int j = 1; j <= n; ++j)
            if (tmp[j] == '1')
                --f[j];
    }

    dp[0][0] = 1;
    int two = 0, one = 0;
    for (int i = 1; i <= n; ++i) {
        if (f[i] == 2)
            ++two;
        if (f[i] == 1)
            ++one;
    }

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j) {
            if (i == 0 && j == 0)
                continue;
            dp[i][j] = (dp[i][j] + (long long) dp[i - 2][j + 2] * comb(i, mod)) % mod;
            dp[i][j] = (dp[i][j] + (long long) dp[i - 1][j] * i * j % mod);
            dp[i][j] = (dp[i][j] + (long long) dp[i][j - 2] * comb(j, mod) % mod) % mod;
        }

    printf("%d", dp[two][one]);
    return 0;
}

