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
ll a2[MAX_N];

void solve() {
	scanf("%I64d%I64d", &n, &d);
	for (ll i = 0;i < n;++i)
		scanf("%I64d", &a[i]);
	sort(a, a + n);
	a2[0] = 0;
	ll x = 0, y = 0;
	for (int i = 0;i < n;++i)
		if (a[i] >= 3 * d) {
			a2[++a2[0]] = a[i];
		} else if (a[i] >= d) {
			x = y;
			y = a[i];
		}
	if (a2[0] == 0) {
		if (x == 0) {
			cout << y << endl;
			return;
		}
		cout << max(x + y - 2 * d, y);
		return;
	}
	ll res = 0;
	ll res2 = 0;
	ll res3 = 0;
	if (x != 0) {
	res = x + y - 2 * d;
	for (int i = 1;i <= a2[0];++i)
		res += a2[i] - 2 * d;
	res2 = x - d;
	for (int i = 1;i < a2[0];++i)
		res2 += a2[i] - 2 * d;
	res2 += a2[a2[0]] - 2 * d;
	for (int i = 1;i < a2[0] - 1;++i)
		res3 += a2[i] - 2 * d;
	if (a2[0] > 2) {
		res3 += a2[a2[0]] - d;
		res3 += a2[a2[0] - 1] - d;
	}
	} else if (y != 0) {
		res = y - d;
		for (int i = 1;i < a2[0];++i)
			res += a2[i] - 2 * d;
		res += a2[a2[0]] - d;
		res2 = res;
		res3 = 0;
		for (int i = 1;i < a2[0] - 1;++i)
			res3 += a2[i] - 2 * d;
		if (a2[0] > 2) {
			res3 += a2[a2[0]] - d;
			res3 += a2[a2[0] - 1] - d;
		}
	} else {
		for (int i = 1;i < a2[0] - 1;++i)
			res3 += a2[i] - 2 * d;
		if (a2[0] > 2) {
			res3 += a2[a2[0]] - d;
			res3 += a2[a2[0] - 1] - d;
		}
	}
	cout << max(max(res, a[n - 1]), max(res2, res3));
}

int main() {
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	solve();
	return 0;
}
