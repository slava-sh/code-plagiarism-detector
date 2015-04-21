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

	vector<vector<ll> > dp(n+1, vector<ll>(k+1, 1e18));
	dp[0][0] = 0;
	for (ll i = 1; i <= n; ++i) {
		dp[i][1] = dp[i-1][1]+d*(v[i].first-v[i-1].second);
		if (i == 1) {
			dp[i][1] = 0;
		}
		for (ll j = 0; j <= k; ++j) {
			dp[i][1] = min<ll>(dp[i][1], dp[i-1][j]+c);
		}
		for (ll j = 2; j <= k; ++j) {
			dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]+d*(v[i].first-v[i-1].second));
		}
	}

	ll mn = *min_element(dp[n].begin(), dp[n].end())+total*d;
	cout << mn << endl;

	return 0;
}