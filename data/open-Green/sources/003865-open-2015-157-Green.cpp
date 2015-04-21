#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;

typedef long long ll;

const ll INF = LLONG_MAX - 1234567890;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n, k;
    cin >> n >> k;
    ll p = 2;
    vector<ll> dels(1, 1);
    while (n != 1 && p * p <= n) {
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            dels.push_back(p);
        }

        p++;
    }
    if (n != 1) dels.push_back(n);

    n = (int)dels.size() - 1;
    vector<vector<ll> > dp(n + 1, vector<ll> (k + 1, -1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            ll cur = 1;
            for (int t = i; t >= 1; t--) {
                cur *= dels[t];
                if (dp[t - 1][j - 1] != -1) {
                    if (dp[i][j] == -1 || dp[i][j] > dp[t - 1][j - 1] * (cur / 2 + cur % 2)) {
                        dp[i][j] = dp[t - 1][j - 1] * (cur / 2 + cur % 2);
                    }
                }
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i <= k; i++) {
        if (dp[n][i] != -1)
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
}
