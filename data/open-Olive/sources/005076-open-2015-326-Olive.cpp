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

typedef int ll;
typedef long double ld;

vector<ll> cul;
ll n;

char MEM[512000000];
char *CMEM = MEM;

void *operator new(size_t cnt) {
	void *res = CMEM;
	CMEM += cnt;
	return res;
}

void operator delete(void *x) {
}

struct tree_t {
	vector<ll> t[100000];
	ll z, n;

	tree_t() {
	}

	tree_t(vector<ll> &a) {
		setup(a);
	}

	inline
	void setup(vector<ll> &a) {
		n = a.size();
		z = 1;
		while (z < n) {
			z *= 2;
		}
		//t.resize(4*z+1);
		build(1, 0, n-1, a);
	}

	inline
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

	inline
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

	inline
	ll ineqcnt(ll v, ll tl, ll tr, ll l, ll r, ll lv, ll rv) {
		if (tr < l || tl > r) {
			return 0;
		}
		if (tl >= l && tr <= r) {
			ll L = lower_bound(t[v].begin(), t[v].end(), lv)-t[v].begin();
			ll R = lower_bound(t[v].begin(), t[v].end(), rv)-t[v].begin();
			return max<ll>(0, R-L+1);
		}
		ll tm = (tl+tr)>>1;
		ll r1 = ineqcnt(v*2, tl, tm, l, r, lv, rv);
		ll r2 = ineqcnt(v*2+1, tm+1, tr, l, r, lv, rv);
		return r1+r2;
	}
};

tree_t t;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	vector<ll> a(n);
	cul.resize(n);
	for (ll i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		--a[i];
		cul[i] = i;
	}

	ll best = 0, besti = -1, bestj = -1;
	t.setup(a);
	vector<vector<ll> > r(n, vector<ll>(n, 0));
	for (ll i = 0; i < n-1; ++i) {
		for (ll j = 0; j < n; ++j) {
			r[i][j] = t.cnt(1, 0, n-1, i+1, a[j]);
		}
	}
	vector<vector<ll> > rin(n, vector<ll>(n, 0)), rout(n, vector<ll>(n, 0));
	for (ll i = 0; i < n; ++i) {
		for (ll j = i+2; j < n; ++j) {
			if (a[j]-a[i]<0) {
				rin[i][j] = t.ineqcnt(1, 0, n-1, i+1, j-1, a[i], a[j]);
			}
			if (a[i]-a[j]>0) {
				rout[i][j] = t.ineqcnt(1, 0, n-1, i+1, j-1, a[j], a[i]);
			}
		}
	}
	for (ll j = 0; j < n; ++j) {				
		for (ll i = j + 1; i < n; ++i) {
			ll cres = 0;
			ll r1 = r[j][i];//t.cnt(1, 0, n-1, j+1, a[i]);
			ll r2 = r[i][j];//t.cnt(1, 0, n-1, i+1, a[j]);
			ll r3 = r[i][i];//t.cnt(1, 0, n-1, i+1, a[i]);
			ll r4 = r[j][j];//t.cnt(1, 0, n-1, j+1, a[j]);

			ll r5 = 0;
			//ll r6 = 0;
			r5 = rin[j][i]-rout[j][i];//t.ineqcnt(1, 0, n-1, j+1, i-1, a[j], a[i]);
			//r6 = rout[j][i];//t.ineqcnt(1, 0, n-1, j+1, i-1, a[i], a[j]);
			cres = r1+r2-r3-r4+r5;//-r6;

			if (cres < best) {
				best = cres;
				besti = i+1;
				bestj = j+1;
			}
		}
	}

	printf("%d %d\n", besti, bestj);

	return 0;
}