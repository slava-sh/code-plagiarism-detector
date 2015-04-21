#pragma comment(linker, "/STACK:256000000")
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>

#define local
#define ll long long
#define ld long double
#define pii pair<int, int>
#define mp make_pair
#define N 3010

using namespace std;

const ld eps = 1e-9;
const int inf = 1e9 + 7, M = 1e9 + 7;



long long dp[N][N];

int main(){
#ifdef local
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << fixed;
	cout.precision(10);

	ll n, m, K, D, C, i, k, a, b, pa, pb;
	cin >> n >> K >> C >> D;
	
	vector< pair<ll, ll> > p(n + 1);
	for (i = 1; i <= n; i++){
		scanf("%lld %lld", &p[i].first, &p[i].second);
	}

	for (i = 0; i <= n; i++){
		fill(dp[i], dp[i] + n, 1e18);
	}
	for (i = 1; i <= n; i++){
		dp[i][1] = (p[i].second - p[1].first) * D;
	}

	for (i = 2; i <= n; i++){
		for (k = 1; k <= n; k++){
			ll pb = p[i - 1].second, a = p[i].first, b = p[i].second;
			dp[i][k] = min(dp[i - 1][k] + (b - pb) * D, dp[i - 1][k - 1] + (b - a) * D + (k % K == 0 ? C : 0));
		}
	}

	ll ans = 1e18;
	for (i = 1; i <= n; i++){
		ans = min(ans, dp[n][i]);
	}

	cout << ans;

	return 0;
}