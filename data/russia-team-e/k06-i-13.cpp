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

int id;

void solve() {
	ll res = 0;
	scanf("%I64d%I64d", &n, &d);
	for (ll i = 0;i < n;++i)
		scanf("%I64d", &a[i]);
	sort(a, a + n);
	for (int i = 0;i < n;i ++ )
		if (a[i] >= 3 * d)
		{
			id = i;
			break;
		}
	for (int i = id;i < n;i ++ )
		res += a[i] - 2 * d;
	if ((id >= 2 && a[id - 1] >= d && a[id - 2] <= d) || (id == 1 && a[0] >= d))
		res += a[id - 1];
	else if (id >= 2 && a[id - 2] >= d)
		res += a[id - 1] + a[id - 2] - 2 * d;
	else
		res += 2 * d;
	cout << max(res, a[n - 1]) << endl;
}

int main() {
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	solve();
	return 0;
}
