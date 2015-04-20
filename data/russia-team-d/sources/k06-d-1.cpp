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
#define FNAME "fence"

using namespace std;

typedef long long ll;

const int INF = 1e9;
const int MAX_N = 100500;

ll n, k;
ll a[MAX_N];

bool ok(ll x) {
	ll r = 0;
	for (int i = 0;i < n;++i) {
		if (x > k - r || a[i] < x) {
			return 0;
		}
		if (a[i] > r)
			r += max(a[i] - r, x);
		else
			r += x;
	}
	return 1;
}

void solve() {
	scanf("%I64d%I64d", &n, &k);
	for (int i = 0;i < n;++i)
		scanf("%I64d", &a[i]);
	sort(a, a + n);
	ll l = 0, r = k + 1;
	while (r - l > 1) {
		ll m = (l + r) >> 1;
		if (ok(m))
			l = m;
		else
			r = m;
	}
	cout << l << endl;
}

int main() {
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	solve();
	return 0;
}
