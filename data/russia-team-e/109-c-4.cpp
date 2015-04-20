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

const int INF = 1e9;
const li P = 1e9 + 7;

struct nd {
	pair<int, int> mx1, mx2;
	int pr, d;
} g[200005];

vector<int> a[200005];

void dfs(int v, int pr = -1) {
	int i, to;
	g[v].pr = pr;
	g[v].mx1 = mp(-INF, -1);
	g[v].mx2 = mp(-INF, -1);
	if (pr == -1)
		g[v].d = 0;
	else
		g[v].d = g[pr].d + 1;
	if (a[v].size() == 1 && pr != -1) {
		g[v].mx1 = mp(0, v);
		g[v].mx2 = mp(-INF, -1);
	}
	for (i = 0; i < a[v].size(); i++) {
		if (a[v][i] != pr) {
			to = a[v][i];
			dfs(to, v);
			if (g[to].mx2.fs + 1 > g[v].mx1.fs) {
				g[v].mx2 = g[v].mx1;
				g[v].mx1 = mp(g[to].mx2.fs + 1, to);
				if (g[v].mx1.sc == g[v].mx2.sc)
					g[v].mx2 = mp(-INF, -1);
			} else if (g[to].mx2.fs + 1 > g[v].mx2.fs && to != g[v].mx1.sc) {
				g[v].mx2 = mp(g[to].mx2.fs + 1, to);
			}
			if (g[to].mx1.fs + 1 > g[v].mx1.fs) {
				g[v].mx2 = g[v].mx1;
				g[v].mx1 = mp(g[to].mx1.fs + 1, to);
				if (g[v].mx1.sc == g[v].mx2.sc)
					g[v].mx2 = mp(-INF, -1);
			} else if (g[to].mx1.fs + 1 > g[v].mx2.fs && to != g[v].mx1.sc) {
				g[v].mx2 = mp(g[to].mx1.fs + 1, to);
			}
		}
	}
}

/*pair< int, int > st;
int mx = -1;
char desk[505][505];
bool used[505][505];
int w, h, n;

pair< int, int > bfs ()
{
	queue< pair< int, int > > b;
	b.push (st);
	used[st.fs][st.sc] = true;
	while (!b.empty ())
	{
		pair< int, int > cur;
		cur = b.front ();
		b.pop ()
		for (int i = -1 ; i <= 1 ; ++i)
			for (int j = -1 ; j <= 1 ; ++j)
				if (abs (i + j) == 1)
					if (!used[][])
	}
}*/

int main() {
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);
	int n, i, x, y, s1, s2, ans = 0, a1, a2, a3, pp, p1;
	pair<int, int> q, q1;
	cin >> n;
	for (i = 0; i < n - 1; i++) {
		cin >> x >> y;
		x--;
		y--;
		a[x].pb(y);
		a[y].pb(x);
	}
	cin >> s1 >> s2;
	s1--;
	s2--;
	dfs(s1);
	i = s2;
	while (g[i].pr != s1) {
		i = g[i].pr;
	}
	pp = i;
	p1 = -1;
	i = s2;
	while (true) {
		q = g[i].mx1;
		if (q.sc == p1) {
			q = g[i].mx2;
		}
		if (q.sc != -1) {
			a1 = q.fs + g[s2].d - g[i].d;
		} else {
			a1 = g[s2].d - g[i].d;
		}
		q1 = g[g[i].pr].mx1;
		if (q1.sc == i) {
			q1 = g[g[i].pr].mx2;
		}
		if (q1.sc != -1) {
			a2 = q1.fs + g[g[i].pr].d;
		} else {
			a2 = g[g[i].pr].d;
		}
		q = g[s1].mx1;
		if (q.sc == pp)
			q = g[s1].mx2;
		if (q.sc == -1)
			a3 = 0;
		else
			a3 = q.fs;
		a2 = max(a2, a3);
		ans = max(ans, min(a1, a2));
		p1 = i;
		i = g[i].pr;
		if (i == s1)
			break;
	}
	cout << ans + 1;

	/*cin >> w >> h >> n;
	for (int i = 0 ; i < h ; ++i)
		for (int j = 0 ; j < w ; ++j)
		{
			cin >> desk[i][j];
			if (desk[i][j] == 'V')
				st = mp (i, j);
			used[i][j] = false;
		}*/
	return 0;
}
/*
6
1 2
2 3
3 4
4 5
5 6
4 5

8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8

10
1 2
2 4
2 3
1 5
5 9
5 10
10 8
10 7
10 6
1 8

5
1 2
2 3
3 4
4 5
1 5

*/