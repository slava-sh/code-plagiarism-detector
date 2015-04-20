#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

#define fname "fence"
#define pb push_back
#define mp make_pair
#define F first
#define forp(i, a, b) for(int i = a; i <= b; ++i)
#define form(i, a, b) for(int i = a; i >= b; --i)

ll n, k, a[100001], u;

bool check(ll m) {
	ll ans = a[1];
	for(int i = 2; i <= n; ++i) {
		ll v = max(m, a[i] - ans);
		ans += v;
	}
	if(ans <= k) return true;
	return false;
}
		 

int main() {
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if(n == 1) {
		cout << a[1];
		return 0;
	}
	ll l = 0, r = k;
	while(l <= r) {
		ll m = (l + r) / 2;
		if(check(m)) {
			l = m + 1;
			u = m;
		} else {
			r = m - 1;
		}
	}
	cout << min(a[1], u);
	return 0;
}