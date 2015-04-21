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

struct tree_t {
	vector<vector<ll> > t;
	ll z, n;

	tree_t(vector<ll> &a) {
		n = a.size();
		z = 1;
		while (z < n) {
			z *= 2;
		}
		t.resize(4*z+1);
		build(1, 0, n-1, a);
	}

	void build(ll v, ll tl, ll tr, vector<ll> &a) {
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
};


void longest(vector<ll> &crnt, ll cres, ll &res) {
	tree_t t(crnt);
	res = 0;
	for (ll i = 0; i < n; ++i) {
		for (ll j = i+1; j < n; ++j) {
			res += t.cnt(1, 0, n-1, i+1, crnt[i]);
			/*if (crnt[i]>crnt[j]) {
				++res;
			}*/
		}
	}
}

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
	longest(a, 0, best);
	for (ll i = 0; i < n; ++i) {
		for (ll j = i + 1; j < n; ++j) {
			ll cres = -1;
			swap(a[i], a[j]);
			longest(a, 0, cres);
			swap(a[i], a[j]);
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