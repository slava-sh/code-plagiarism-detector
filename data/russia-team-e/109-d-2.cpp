#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long li;

#define pb push_back

/*struct nd {
	int mx1, mx2;
	int pr;
} g[200005];

vector<int> a[200005];

void dfs(int v, int pr = -1) {
	int i, to;
	g[v].pr = pr;
	for (i = 0; i < a[v].size(); i++) {
		if (a[v][i] != pr) {
			to = a[v][i];
			dfs(a[v][i], v);
			if (g[to].mx1 > g[v].mx1) {
				g[v].mx2 = g[v].mx1;
				g[v].mx1 = g[to].mx1;
			}
		}
	}
}*/

int main() {
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	li n, k, p, a[100005], i, l, r, m, mn = 1e9;
	cin >> n >> k;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	sort(a, a + n);
	l = 0;
	r = 1e9 + 5;
	while (l != r) {
		p = 0;
		m = (l + r) / 2;
		for (i = 0; i < n; i++) {
			if (a[i] < m) {
				r = m;
				break;
			}
			if (p < (a[i] - m)) {
				p += (a[i] - m) - p;
			}
			p += m;
		}
		if (i != n)
			continue;
		if (p > k) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	cout << l - 1;
	/*int n, i, x, y, s1, s2;
	cin >> n;
	for (i = 0; i < n - 1; i++) {
		cin >> x >> y;
		x--;
		y--;
		a[x].pb(y);
		a[y].pb(x);
	}
	dfs(s1);*/
	return 0;
}
/*
5 3
9 4 10 12 16

*/