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

ll n, k, a[100001], u;;

bool check(ll m) {
	ll v = min(a[1], m);
	ll ans = min(a[1], m); 
	for(int i = 2; i <= n; ++i) {
		v = min(v, min(m, a[i]));
		ans += min(m, a[i]);
	}
	if(ans <= k) {
		u = v;
		return true;
	}
	return false;
}

int main() {
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	ll l = 1, r = k;
	while(l + 1 < r) {
		ll m = (l + r) / 2;
		if(check(m)) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << u;
	return 0;
}