#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define prev prev_
#define next next_

const ll LINF = (ll)1e18;

int main() {
    #define task "a"
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    ll c, d;
    cin >> n >> k >> c >> d;
    swap(c,d);
    vector<vector<ll> > dp(n + 1, vector<ll>(k + 1, LINF));
    vector<ll> a(n + 1);
    vector<ll> b(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    dp[0][1] = (b[0] - a[0]) * c;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i + 1][j] = min(dp[i][j] + (b[i + 1] - b[i]) * c, dp[i + 1][j]);
            if (j != k) {
                dp[i + 1][j + 1] = min(dp[i][j] + (b[i + 1] - a[i + 1]) * c, dp[i + 1][j + 1]);
            } else {
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][k] + d + (b[i + 1] - a[i + 1]) * c);
            }
        }
    }
    ll ans = LINF;
    for (int j = 1; j <= k; j++) {
        ans = min(dp[n - 1][j], ans);
    }
    cout << ans << endl;
    return 0;
}
