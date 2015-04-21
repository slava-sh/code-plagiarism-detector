#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <iterator>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define scf scanf
#define prf printf

using namespace std;

typedef long long ll;

int n, k, c, d;
int a[200500], b[200500];
ll dp[3030][3030];
                     
int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scf("%d%d%d%d", &n, &k, &c, &d);
	for (int i = 1; i <= n; i++) scf("%d%d", &a[i], &b[i]);
	for (int i = 0; i < 3030; i++) for (int j = 0; j < 3030; j++) {
		dp[i][j] = (ll)1e18;
	}
	dp[1][k - 1] = 1LL * d * (b[1] - a[1]);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (dp[i][j] == (ll)1e18) continue;
			dp[i + 1][j] = min(dp[i + 1][j], 1LL * d * (b[i + 1] - b[i]) + dp[i][j]);
			dp[i + 1][j - 1] = min(dp[i + 1][j - 1], 1LL * d * (b[i + 1] - a[i + 1]) + dp[i][j]);
		}
		dp[i + 1][0] = min(dp[i + 1][0], 1LL * d * (b[i + 1] - b[i]) + dp[i][0]);
		dp[i + 1][k - 1] = min(dp[i + 1][k - 1], 1LL * d * (b[i + 1] - a[i + 1]) + 1LL * c + dp[i][0]);
	}
	ll res = (ll)1e18;
	for (int i = 0; i <= k; i++) res = min(res, dp[n][i]);
	cout << res << "\n";
	return 0;
}