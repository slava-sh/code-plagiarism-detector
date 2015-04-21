#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int l[200500], r[200500], n, k, C, D;
const ll inf = (ll)2e18;
ll dp[3003][3003];

int main()
{
    scanf("%d%d%d%d", &n, &k, &C, &D);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &l[i], &r[i]);
    }
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= k; ++j)
            dp[i][j] = inf;
    }
    dp[0][k-1] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= k; ++j){
            if(dp[i][j] == inf)
                continue;
            ll cur = (r[i]-l[i]) * 1LL * D;
            if(j)
                dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j] + cur);
            else
                dp[i+1][k-1] = min(dp[i+1][k-1], dp[i][j] + cur + C);
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + cur + (i == n-1 ? 0 : (l[i+1] - r[i])) * 1LL * D);
        }
    }
    ll ans = inf;
    for(int i = 0; i <= k; ++i){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << '\n';
    return 0;
}
