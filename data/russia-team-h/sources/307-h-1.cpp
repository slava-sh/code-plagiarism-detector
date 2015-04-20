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

int main()
{
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi c(n);
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	vvii g(n);
	int x, y, z;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y >> z;
		--x, --y;
		g[x].pb(mp(y, z));
		g[y].pb(mp(x, z));
	}
	queue <int> q;
	vi d(n), pr(n, -1);
	for (int i = 0; i < n; ++i)
		if (c[i] == 1)
		{
			d[i] = 0;
			q.push(i);
		}
		else
			d[i] = inf;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i].first, p = g[v][i].second;
			if (d[to] > d[v] + p)
			{
				pr[to] = v;
				d[to] = d[v] + p;
				q.push(to);
			}
		}
	}
	int ans = inf;
	x = 0, y = 0;
	for (int i = 0; i < n; ++i)
		if (c[i] == 2 && d[i] < ans)
			ans = d[i], y = i;
	if (ans == inf)
		cout << -1;
	else
	{
		x = y;
		while (pr[x] != -1)
			x = pr[x];
		cout << x + 1 << ' ' << y + 1 << ' ' << ans;
	}
	return 0;
}