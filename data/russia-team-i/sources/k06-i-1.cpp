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

int n, d;
int a[MAX_N];

void solve() {
	ll res = 0;
	scanf("%d%d", &n, &d);
	for (int i = 0;i < n;++i)
		scanf("%I64d", &a[i]);
	sort(a, a + n);
	int i = 0;
	for (;i < n && a[i] <= d;++i);
	if (i >= n - 1) {
		cout << a[n - 1];
		return;
	}
	res += a[i] + a[i + 1] - 2 * d;
	for (i = i + 2;i < n;++i)
		if (a[i] > 2 * d)
			res += a[i] - 2 * d;
	cout << max(res, (ll)max(a[n - 1], a[n - 1] + a[n - 2] - 2 * d)) << endl;
}

int main() {
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	solve();
	return 0;
}
