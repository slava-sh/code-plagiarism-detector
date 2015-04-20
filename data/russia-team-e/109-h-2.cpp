#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

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
pair<li, li> d[5005];
li p1[5005];
li p[5005];

int main() {
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	li n, m, t[5005], i, j, x, y, c, mn, imn;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> t[i];
	t[n] = 0;
	for (i = 0; i < m; i++) {
		cin >> x >> y >> c;
		x--;
		y--;
		a[x].pb(mp(y, c));
		a[y].pb(mp(x, c));
	}
	for (i = 0; i < n; i++) {
		if (t[i] != 2) {
			mn = INF;
			for (j = 0; j < a[i].size(); j++) {
				if (t[a[i][j].fs] == 2) {
					if (mn > a[i][j].sc) {
						mn = min(mn, a[i][j].sc);
						imn = a[i][j].fs;
					}
				}
			}
			a[n].pb(mp(i, mn));
			a[i].pb(mp(n, mn));
			p1[i] = imn;
		}
	}
	n++;
	for (i = 0; i < n; i++)
		d[i] = mp(INF, -1);
	d[n - 1] = mp(0, -1);
	priority_queue< pair<li, li> > q;
	q.push(mp(0, n - 1));
	for (i = 0; i < n; i++)
		p[i] = -1;
	while (!q.empty()) {
		li v = q.top().sc;
		li cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v].fs) {
			continue;
		}
		for (j = 0; j < a[v].size(); j++) {
			li to = a[v][j].fs;
			if (t[to] == 2)
				continue;
			li len = a[v][j].sc;
			if (d[v].fs + len < d[to].fs) {
				d[to].fs = d[v].fs + len;
				p[to] = v;
				q.push(mp(-d[to].fs, to));
			}
		}
	}
	li aans = INF, ians, jans;
	for (i = 0; i < n; i++) {
		if (t[i] == 1) {
			if (aans > d[i].fs) {
				aans = d[i].fs;
				ians = i;
			}
		}
	}
	if (aans == INF) {
		cout << -1;
	} else {
		i = ians;
		while (p[i] != n - 1) {
			i = p[i];
		}
		mn = INF;
		for (j = 0; j < a[i].size(); j++)
			if (t[a[i][j].fs] == 2) {
				if (mn > a[i][j].sc) {
					mn = min(mn, a[i][j].sc);
					imn = a[i][j].fs;
				}
			}
		jans = imn;
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

5 4
0 1 2 0 2
1 5 1
1 4 1
3 2 2
2 4 1
*/