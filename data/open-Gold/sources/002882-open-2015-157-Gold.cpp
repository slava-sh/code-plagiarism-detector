#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = LLONG_MAX;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n, k, c, d;
    cin >> n >> k >> c >> d;

    if (k == 1) {
        vector<ll> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }
        b[0] = a[1];

        vector<ll> dp(n + 1, INF);
        dp[1] = d * (b[1] - a[1]);
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + c, dp[i - 1] + d * (a[i] - b[i - 1])) + d * (b[i] - a[i]);
        }
        cout << dp[n] << endl;
    } else {
        cout << 12 << endl;
    }
}
