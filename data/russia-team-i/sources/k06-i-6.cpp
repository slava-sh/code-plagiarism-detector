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
const int MAX_N = 200500;

ll n, d;
ll a[MAX_N];

void solve() {
	ll res = 0;
	scanf("%I64d%I64d", &n, &d);
	for (ll i = 0;i < n;++i)
		scanf("%I64d", &a[i]);
	sort(a, a + n);
	ll i = 0;
	for (;i < n && a[i] <= d;++i);
	if (i >= n - 1) {
		cout << a[n - 1];
		return;
	}
	res += a[i] + a[i + 1] - 2 * d;
	for (int j = i + 2;j < n;++j)
		if (a[j] >= 3 * d)
			res += a[j] - 2 * d;
	ll res2 = 0;
	ll res3 = 0;
	res3 = a[i] - d;
	for (int j = i + 1;j < n - 1;++j)
		if (a[j] >= 3 * d)
			res3 += a[j] - 2 * d;
	res3 += a[n - 1] - d;	
	res2 += a[n - 1] + a[n - 2] - 2 * d;
	for (int i = 0;i < n - 2;++i)
		if (a[i] >= 3 * d)
			res2 += a[i] - 2 * d;
	cout << max(res, (ll)max(a[n - 1], max(res2, res3))) << endl;
}

int main() {
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	solve();
	return 0;
}
