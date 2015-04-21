#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

vector<ll> cul;
ll n;

struct treap_t {
	treap_t *l, *r;
};

struct tree_t {
	vector<vector<ll> > t;
	ll z, n;

	tree_t() {
	}

	tree_t(vector<ll> &a) {
		setup(a);
	}

	void setup(vector<ll> &a) {
		n = a.size();
		z = 1;
		while (z < n) {
			z *= 2;
		}
		t.resize(4*z+1);
		build(1, 0, n-1, a);
	}

	void build(ll v, ll tl, ll tr, vector<ll> &a) {
		t[v].clear();
		for (ll i = tl; i <= tr; ++i) {
			t[v].push_back(a[i]);
		}
		sort(t[v].begin(), t[v].end());
		if (tl == tr) {
			return;
		}
		ll tm = (tl+tr)>>1;
		build(v*2, tl, tm, a);
		build(v*2+1, tm+1, tr, a);
	}

	ll cnt(ll v, ll tl, ll tr, ll p, ll val) {
		if (tr < p) {
			return 0;
		}
		if (tl >= p) {
			ll z = lower_bound(t[v].begin(), t[v].end(), val)-t[v].begin();
			return z;
		}
		ll tm = (tl+tr)>>1;
		ll r1 = cnt(v*2, tl, tm, p, val);
		ll r2 = cnt(v*2+1, tm+1, tr, p, val);
		return r1+r2;
	}

	ll ineqcnt(ll v, ll tl, ll tr, ll l, ll r, ll lv, ll rv) {
		if (tr < l || tl > r) {
			return 0;
		}
		if (tl >= l && tr <= r) {
			ll L = lower_bound(t[v].begin(), t[v].end(), lv)-t[v].begin();
			ll R = lower_bound(t[v].begin(), t[v].end(), rv)-t[v].begin();
			return max(0, R-L+1);
		}
		ll tm = (tl+tr)>>1;
		ll r1 = ineqcnt(v*2, tl, tm, l, r, lv, rv);
		ll r2 = ineqcnt(v*2+1, tm+1, tr, l, r, lv, rv);
		return r1+r2;
	}
};

tree_t t;

/*void longest(vector<ll> &crnt, ll cres, ll &res) {
	t.build(1, 0, n-1, crnt);
	res = 0;
	for (ll i = 0; i < n; ++i) {
		res += t.cnt(1, 0, n-1, i+1, crnt[i]);
	}
}*/

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;

	vector<ll> a(n);
	cul.resize(n);
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
		cul[i] = i;
	}

	ll best = -1, besti = -1, bestj = -1;
	t.setup(a);
	best = 0;
	//longest(a, 0, best);
	for (ll j = 0; j < n; ++j) {
		for (ll i = j + 1; i < n; ++i) {
			/*ll cres = -1;
			swap(a[i], a[j]);
			longest(a, 0, cres);
			swap(a[i], a[j]);*/
			ll cres = 0;
			ll r1 = t.cnt(1, 0, n-1, j+1, a[i]);
			ll r2 = t.cnt(1, 0, n-1, i+1, a[j]);
			ll r3 = t.cnt(1, 0, n-1, i+1, a[i]);
			ll r4 = t.cnt(1, 0, n-1, j+1, a[j]);
			ll r5 = t.ineqcnt(1, 0, n-1, j+1, i-1, a[j], a[i]);
			ll r6 = t.ineqcnt(1, 0, n-1, j+1, i-1, a[i], a[j]);
			cres = r1+r2-r1-r2+r5-r6;

			if (cres < best) {
				best = cres;
				besti = i+1;
				bestj = j+1;
			}
		}
	}

	cout << besti << " " << bestj << endl;

	return 0;
}