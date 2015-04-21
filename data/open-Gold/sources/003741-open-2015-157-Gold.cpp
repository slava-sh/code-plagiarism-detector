#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = LLONG_MAX;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n, k, c, d;
    cin >> n >> k >> c >> d;

    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    b[0] = a[1];

    vector<vector<ll> > dp(n + 1, vector<ll> (k + 1, INF));
    dp[1][0] = d * (b[1] - a[1]);
    ll minval = dp[1][0];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = minval + d * (b[i] - a[i]) + c;
        minval = INF;
        for (int j = 0; j <= k; j++) {
            if (dp[i - 1][j] != INF) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + d * (b[i] - b[i - 1]));
                if (j > 0 && j < k) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + d * (b[i] - a[i]));
                }
                minval = min(minval, dp[i][j]);
            }
        }
    }
/*
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }*/

    ll ans = INF;
    for (int i = 0; i < k; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
}
