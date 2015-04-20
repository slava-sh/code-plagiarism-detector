#include <iostream>
#include <vector>
#include <algorithm>

#pragma comment(linker, "/STACK:256000000");
using namespace std;

vector<int> a[1000000];
int h[1000000];
int hh[1000000];

int dfs1(int v, int p, int t)
{
	int m = 0;
	for (int i = 0; i < a[v].size(); i++)
		if (a[v][i] != p)
			m = max(m, dfs1(a[v][i], v, t + 1) + 1);
	hh[v] = t;
	return h[v] = m;
}

bool f[1000000];
bool _find(int v, int p, int x)
{
	if (v == x)
		return f[v] = true;
	for (int i = 0; i < a[v].size(); i++)
		if (a[v][i] != p && _find(a[v][i], v, x))
		{
			f[v] = true;
			return true;
		}
	return f[v] = false;
}

int d[1000000];
int dfs2(int v, int p, int x)
{
	int m = 0;
	if (v != x)
	{
		for (int i = 0; i < a[v].size(); i++)
			if (a[v][i] != p)
				if (f[a[v][i]])
					m = dfs2(a[v][i], v, x);
	}
	for (int i = 0; i < a[v].size(); i++)
		if (a[v][i] != p && !f[a[v][i]])
			m = max(m, 1 + h[a[v][i]] + hh[x] - hh[v]);
	return d[v] = m;
}

int ans;

void dfs3(int v, int p, int x)
{
	int m = 0;
	int q = 0;
	for (int i = 0; i < a[v].size(); i++)
	{
		
		if (a[v][i] != p && !f[a[v][i]])
			m = max(h[a[v][i]] + h[v], m);
		else if (f[a[v][i]] &&  !f[a[v][i]])
		{
			q = d[a[v][i]];
			ans = max(ans, dfs3(a[v][i], v, x));
		}
	}
	ans = min(m, q);

}




int main()
{
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < 1000000; i++)
		f[i] = false, h[i] = -1;
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int u, v;
	cin >> u >> v;
	u--, v--;
	dfs1(u, -1, 0);
	for (int i = 0; i < a[u].size(); i++)
		_find(a[u][i], u, v);
	dfs2(u, -1, v);
	int y = 0;
	for (int i = 0; i < a[u].size(); i++)
		if (f[a[u][i]])
			y = d[a[u][i]];
	int x = 0;
	for (int i = 0; i < a[u].size(); i++)
		if (!f[a[u][i]])
			x = max(x, h[a[u][i]] + 1);
	ans = min(x , y);
	dfs3(u, -1, v);
	cout << ans + 1;

	return 0;
}