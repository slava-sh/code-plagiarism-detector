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

/*struct nd {
	pair<int, int> mx1, mx2;
	int pr, d;
} g[200005];

vector<int> a[200005];

void dfs(int v, int pr = -1) {
	int i, to;
	g[v].pr = pr;
	if (pr == -1)
		g[v].d = 0;
	else
		g[v].d = g[pr].d + 1;
	if (a[v].size() == 1 && pr != -1) {
		g[v].mx1 = mp(0, v);
		g[v].mx1 = mp(-INF, -1);
	}
	for (i = 0; i < a[v].size(); i++) {
		if (a[v][i] != pr) {
			to = a[v][i];
			dfs(to, v);
			if (g[to].mx2 > g[v].mx1) {
				g[v].mx2 = g[v].mx1;
				g[v].mx1 = mp(g[to].mx2, to);
			} else if (g[to].mx2 > g[v].mx2) {
				g[v].mx2 = mp(g[to].mx2, to);
			}
			if (g[to].mx1 > g[v].mx1) {
				g[v].mx2 = g[v].mx1;
				g[v].mx1 = mp(g[to].mx1, to);
			} else if (g[to].mx1 > g[v].mx2) {
				g[v].mx2 = mp(g[to].mx1, to);
			}
		}
	}
}*/

vector< vector< pair< li, li > > > g;
vector< char > sum, used;
bool panic = false;

void dfs (li v)
{
	used[v] = true;
	for (li i = 0 ; i < g[v].size () ; ++i)
	{
		if (used[g[v][i].fs])
		{
			if (sum[g[v][i].fs] != sum[v] ^ g[v][i].sc)
				panic = true;
		}
		else
		{
			sum[g[v][i].fs] = sum[v] ^ g[v][i].sc;
			dfs (g[v][i].fs);
		}
		if (panic)
			return;
	}
}

li binpow (li n)
{
	li res = 1;
	for (li i = 0 ; i < n ; ++i)
	{
		res *= 2;
		res %= P;
	}
	return res;
}

int main() {
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
	/*int n, i, x, y, s1, s2, ans = 0, a1, a2, pp, p1;
	pair<int, int> q;
	cin >> n;
	for (i = 0; i < n - 1; i++) {
		cin >> x >> y;
		x--;
		y--;
		a[x].pb(y);
		a[y].pb(x);
	}
	dfs(s1);
	i = s2;
	while (g[i].pr != s1) {
		i = g[i].pr;
	}
	pp = i;
	p1 = s2;
	i = s2;
	while (true) {
		q = g[i].mx1 
	}*/

	li n;
	cin >> n;
	li a[5000];
	for (li i = 0 ; i < n ; ++i)
		cin >> a[i];
	g.assign (n, vector< pair < li, li > > ());
	for (li i = 1 ; i < n ; ++i)
	{
		if (a[i] == -1)
			continue;
		li j;
		for (j = 0 ; j < a[i] ; ++j)
		{
			if (i + j >= n)
			{
				cout << 0;
				return 0;
			}
			g[i + j].pb (mp (j, 0));
			g[j].pb (mp (i + j, 0));
		}
		if (i + j < n)
		{
			g[i + j].pb (mp (j, 1));
			g[j].pb (mp (i + j, 1));
		}
	}

	/*for (li i = 0 ; i < n ; ++i)
	{
		for (li j = 0 ; j < g[i].size () ; ++j)
			cout << g[i][j].fs << ' ';
		cout << endl;
	}*/

	li comp = 0;
	sum.assign (n, false);
	used.assign (n, false);
	for (li i = 0 ; i < n ; ++i)
	{
		if (!used[i])
		{
			dfs (i);
			if (panic)
			{
				cout << 0;
				return 0;
			}
			++comp;
		}
	}
	cout << binpow (comp);
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