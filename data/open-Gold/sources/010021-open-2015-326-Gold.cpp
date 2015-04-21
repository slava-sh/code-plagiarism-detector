#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<ll, ll> pll;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ll n, k, c, d;
	cin >> n >> k >> c >> d;
	vector<pll> v(n+1, pll(0, 0));
	ll total = 0;
	for (ll i = 0; i < n; ++i) {
		cin >> v[i+1].first >> v[i+1].second;
		total += v[i+1].second-v[i+1].first;
	}

	vector<vector<ll> > dp(2, vector<ll>(k+1, 1e18));
	dp[0][0] = 0;
	for (ll i = 1; i <= n; ++i) {
		dp[1][1] = min<ll>(dp[0][k]+c, dp[0][1]+d*(v[i].first-v[i-1].second));
		if (i == 1) {
			dp[1][1] = 0;
		}

		for (ll j = 2; j <= k; ++j) {
			ll sw = dp[0][j-1];
			ll nsw = dp[0][j]+d*(v[i].first-v[i-1].second);
			/*if (sw > nsw) {
				cout << i << " " << j << " " << sw << " " << nsw << endl;
			}*/
			dp[1][j] = min(sw, nsw);
		}
		dp[0].swap(dp[1]);
		fill(dp[1].begin(), dp[1].end(), 1e18);
	}

	ll mn = *min_element(dp[0].begin(), dp[0].end())+total*d;
	cout << mn << endl;

	return 0;
}