#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (lol)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

const lol N = 50000;
lol a[N], l, k;
lol dp[15][N];
lol inf = 1000000000000000ll;

int main() {
    inp("input.txt");
    must;
    lol n, i, j, jj;
    cin >> n >> k;
    for(i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            a[++l] = i;
            if(i != n / i)
                a[++l] = n / i;
        }
    }
    k++;
    sort(a + 1, a + 1 + l);
    for(i = 1; i <= k; i++)
        for(j = 1; j <= l; j++)
            dp[i][j] = inf;
    dp[1][1] = 1;
    for(i = 2; i <= k; i++)
        for(j = 1; j <= l; j++) {
            for(jj = j; jj >= 1; jj--) {
                if(a[j] % a[jj] == 0 && dp[i - 1][jj] != inf)
                    dp[i][j] = min(dp[i][j], dp[i - 1][jj] * ((a[j] / a[jj] + 1) / 2));
            }
        }

    cout << dp[k][l];
}

