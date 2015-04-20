#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

#define fname "fence."
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz size()
#define ll long long

const ll MAXN = 100500;
const ll INF = (ll)(1 << 30);

ll n, k, a[MAXN];

bool check(ll x) {
	ll cur = 0;
	for (ll i = 1; i <= n; i++) 
		if (a[i] < x) return 0;
	cur = a[1];
	for (ll i = 2; i <= n; i++)
		cur = max (a[i], cur + x);
	if (cur <= k) return 1;
	return 0;
}

int main () {
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
		cin >> n >> k;
		for (ll i = 1; i <= n; i++)	
			cin >> a[i];
		sort(a + 1, a + n + 1);
		ll l = 0, r = INF, ans = 0;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (check(mid)) {
				l = mid + 1;
				ans = mid;
			}
			else
				r = mid - 1;
		}
		cout << ans;
	return 0;
}
