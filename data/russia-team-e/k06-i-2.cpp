#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#include <ctime>
#include <bitset>
#include <algorithm>
#include <utility>

#define pb(x) push_back(x)
#define fi first
#define se second
#define mp make_pair
#define FNAME "sochi"

using namespace std;

typedef long long ll;

const int INF = 1e9;
const int MAX_N = 100500;

ll n, d;
ll a[MAX_N];
ll dp[MAX_N];

void solve() {
	ll res = 0;
	scanf("%I64d%I64d", &n, &d);
	for (int i = 0;i < n;++i)
		scanf("%I64d", &a[i]);
	sort(a, a + n);
	dp[0] = a[0];
	for (int i = 1;i < n;++i)
		dp[i] = max(dp[i - 1], max(dp[i - 1] + a[i] - 2 * d, 
			(ll)max(a[i - 1] + a[i] - 2 * d, a[i])));
	cout << dp[n - 1] << endl;
}

int main() {
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	solve();
	return 0;
}
