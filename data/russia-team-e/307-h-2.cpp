#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

#define pb push_back
#define rs resize
#define inf 1e9
#define mp make_pair

typedef vector <int> vi;
typedef pair <int, int> pii;
typedef long long ll;
typedef vector<ll> vl;
typedef vector <string> vs;
typedef vector <vs> vvs;
typedef vector <vi> vvi;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vii> vvii;
typedef vector <bool> vb;

int main()
{
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi a(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	vvii g(n + 1);
	for (int i = 1; i <= n; ++i)
		if (a[i] == 1)
		{
			g[0].pb(mp(i, 1));
			g[i].pb(mp(0, 1));
		}
	int x, y, z;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y >> z;
		g[x].pb(mp(y, z));
		g[y].pb(mp(x, z));
	}
	vi d(n + 1, inf), p(n + 1, -1);
	vb u(n + 1, 0);
	d[0] = 0;
	for (int i = 0; i <= n; ++i)
	{
		int v = -1;
		for (int j = 0; j <= n; ++j)
			if (!u[j]  && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == inf)
			break;
		u[v] = 1;
		for (int j = 0; j < g[v].size(); j++)
		{
			int to = g[v][j].first, l = g[v][j].second;
			if (d[to] > d[v] + l)
			{
				d[to] = d[v] + l;
				p[to] = v;
			}
		}
	}
	int ans = inf;
	for (int i = 1; i <= n; ++i)
		if (a[i] == 2)
			if (ans > d[i])
				ans = d[i], y = i;
	if (ans == inf)
	{
		cout << -1;
		return 0;
	}
	x = y;
	while (p[x] > 0)
		x = p[x];
	cout << x << ' ' << y << ' ' << ans - 1;
}