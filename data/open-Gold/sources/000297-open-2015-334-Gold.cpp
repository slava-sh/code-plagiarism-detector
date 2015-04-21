#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (int)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

int dp[3010][3010];
int a[3010], b[3010];

int main() {
    inp("input.txt");
    must;
    int n, k, c, d, i, j, ans(0);
    cin >> n >> k >> c >> d;
    for(i = 1; i <= n; i++)
        cin >> a[i] >> b[i], ans += (b[i] - a[i]);
    for(i = 2; i <= n; i++)
        for(j = k; j >= 1; j--) {
            dp[i][j] = dp[i - 1][j] + (a[i] - b[i - 1]) * d;
            if(j > 1)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + c);
        }
//    for(i = 1; i <= n; i++)
//        for(j = 1; j <= k; j++)
//            cout << dp[i][j] << " \n"[j == k];
//    cout << "fin\n";
//    cout << ans * d << "\n";
    cout << *min_element(dp[n] + 1, dp[n] + 1 + k) + ans * d;
    return 0;
}
