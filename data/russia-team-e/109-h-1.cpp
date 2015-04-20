#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long li;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const li INF = 1e15;

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

vector< pair<li, li> > a[5005];
pair<li, li> ans[5005];

int main() {
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	li n, m, t[5005], u[5005], i, j, x, y, c;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> t[i];
	for (i = 0; i < m; i++) {
		cin >> x >> y >> c;
		x--;
		y--;
		a[x].pb(mp(y, c));
		a[y].pb(mp(x, c));
	}
	for (i = 0; i < n; i++) {
		u[i] = 0;
		ans[i] = mp(INF, -1);
	}
	for (i = 0; i < n; i++) {
		if (t[i] == 2) {
			u[i] = 1;
			ans[i] = mp(0, i);
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < a[i].size(); j++) {
			if (u[a[i][j].fs]) {
				if (ans[i].fs > ans[a[i][j].fs].fs + a[i][j].sc) {
					ans[i] = mp(ans[a[i][j].fs].fs + a[i][j].sc, ans[a[i][j].fs].sc);
				}
			}
		}
		u[i] = 1;
	}
	li aans = INF, ians, jans;
	for (i = 0; i < n; i++) {
		if (t[i] == 1) {
			if (aans > ans[i].fs) {
				aans = ans[i].fs;
				ians = i;
				jans = ans[i].sc;
			}
		}
	}
	if (aans == INF) {
		cout << -1;
	} else {
		cout << ians + 1 << ' ' << jans + 1 << ' ' << aans;
	}
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
6 7
1 0 1 2 2 0
1 3 3
1 2 4
2 3 3
2 4 2
1 6 5
3 5 6
5 6 1

*/