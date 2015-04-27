#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cassert>
#include <utility>
#include <cstring>

using namespace std;

#define EPS 1E-8

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forv(i, a) for (int i = 0; i < int(a.size()); i++)
#define fors(i, a) for (int i = 0; i < int(a.length()); i++)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define VS vector<string>

#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())

#define C_IN_FILE "signchange.in"
#define C_OUT_FILE "signchange.out"

const int list = 1 << 17;

int m, n, ans;
vector<int> a;
int t[list << 1];

void outdata() {
}

void update(int v, int a) {
	v += list;
	t[v] = a;
	while (v > 1) {
		v >>= 1;
		t[v] = t[v << 1] + t[(v << 1) ^ 1];
	}                           
}

int sum(int l, int r) {
	l += list;
	r += list;
	int res = 0;
	while (l <= r) {
		if (l & 1) res += t[l];
		if ((r & 1) == 0) res += t[r];
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
	return res;
}

void solve() {
	memset(t, 0, sizeof t);
    forn(i, n) t[i + list] = a[i] * (1 - 2 * (i & 1));
    for(int i = list - 1; i > 0; --i) t[i] = t[i << 1] + t[(i << 1) ^ 1];
    cin >> m;
    forn(i, m) {
    	int t, l, r;
		cin >> t >> l >> r;
		assert(t == 0 || t == 1);
		if (t == 0) {
			assert(1 <= l && l <= n);
			assert(1 <= r && r <= 10000);
			--l;
			update(l, r * (1 - 2 * (l & 1)));
		} else {
			assert(1 <= l && l <= r && r <= n);
			--l; --r;
			int res = sum(l, r);
			if (l & 1) res = -res;
			cout << res << endl;
		}
    }
}

void readdata() {
	cin >> n;
//	assert(1 <= n && n <= 100000);
	a.resize(n);
	forn(i, n) cin >> a[i];
	forn(i, n) assert(1 <= a[i] && a[i] <= 10000);
}

int main() {
    freopen(C_IN_FILE, "rt", stdin);
    freopen(C_OUT_FILE, "wt", stdout);
	readdata();
	solve();
	outdata();
	return 0;
}
