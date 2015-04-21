#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define prev prev_
#define next next_

set<ll> getDivisors(ll x) {
    set<ll> ans;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            ans.insert(i);
            ans.insert(x / i);
        }
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n;
    int k;
    cin >> n >> k;
    vector<unordered_map<ll, pair<ll,ll> > > dp(k + 1);
    set<ll> divs = getDivisors(n);
    dp[0][1ll] = {1ll, 1ll};
    for (int i = 0; i < k; i++) {
        for (auto x : dp[i]) {
            for (auto d : divs) {
                if (d < x.se.se) {
                    continue;
                }
                if (d > n / x.fi) {
                    break;
                }
                ll p = x.fi * d;
                pair<ll,ll> val = dp[i + 1][p];
                if (val.fi == 0) {
                    val.fi = n + 5;
                }
                dp[i + 1][p] = min(val, {x.se.fi * ((d + 1) / 2), d});
            }
        }
    }
    cout << dp[k][n].fi << endl;
    return 0;
}
