// written by Amirmohsen Ahanchi //
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <map>
#include <fstream>
#include <cstring>
#include <list>
#include <iterator>
#include <complex>
#include <cassert>

#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second
#define Size(n) ((int)(n).size())
#define Foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define aint(x) x.begin(),x.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define dbg(x) "#" << #x << ": " << x 
#define spc << " " <<

using namespace std;

//#define cin fin
//#define cout fout

typedef long long LL;
typedef pair <int, int> PII; 

const int maxN = 2000 + 5;

int mark[maxN];

int g[maxN][maxN];
int b[maxN][maxN];
int h[maxN], lvl[maxN];

vector <int> adj[maxN];
int a[maxN];
int n, m;

int root[maxN];
int N = 0;

void dfs1(int x, int p)
{
	mark[x] = 1;
	h[x] = n;
	for (int u = 0; u < n; u++) if (g[x][u] && u != p)
	{
		if (mark[u])
			h[x] = min(h[x], lvl[u]);
		else
		{
			lvl[u] = lvl[x]+1;
			dfs1(u, x);
//			cerr << x << " " << u << endl;
			if (h[u] > lvl[x])
				b[x][u] = b[u][x] = 1;
			h[x] = min(h[x], h[u]);
		}
	}
}

void dfs2(int x, int c)
{
	mark[x] = 1;
	root[x] = c;
	a[c]++;
	for (int u = 0; u < n; u++)
		if (!mark[u] && g[x][u] && !b[x][u])
			dfs2(u, c);
}

int sum[maxN];

void dfs3(int x, int p)
{
	sum[x] = a[x];
	for (int u : adj[x]) if (u != p)
	{
		dfs3(u, x);
		sum[x] += sum[u];
	}
}

int dfs4(int x, int p)
{
	int res = a[x]*a[x];
	for (int u : adj[x]) if (u != p)
	{
		res += dfs4(u, x);
		res += sum[u]*a[x];
	}
	return res;
}

int d[maxN];

int solve(int x)
{
	dfs3(x, -1);
	int res = dfs4(x, -1);
//	cerr << res << endl;
	vector <int> que;
	memset(d, 0, sizeof d);
	d[0] = 1;
	int mx = 0;
//	for (int u : adj[x])
//		cerr << sum[u] << " ";
//	cerr << endl;
	for (int u : adj[x])
		for (int i = mx; i >= 0; i--) if (d[i])
			d[i+sum[u]] = 1, mx = max(mx, i+sum[u]);
	int y = 0;
	for (int i = 1; i <= mx; i++)
		if (d[i])
			y = max(y, i * (mx-i));
	return res+y;
}




int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, m)
	{
		int u, v; cin >> u >> v;
		u--; v--;
		g[u][v] = g[v][u] = 1;
	}
	dfs1(0, -1);
	memset(mark, 0, sizeof mark);
	N = 0;
	rep(i, n) if (!mark[i])
		dfs2(i, N++);
	rep(i, n) rep(j, n) if (g[i][j] && b[i][j])
		adj[root[i]].pb(root[j]);
//	rep(i, n) rep(j, n) if (g[i][j])
//		cerr << i << " " << j << " " << b[i][j]  << endl;
	n = N;
//	cerr << n << endl;
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, solve(i));
	cout << ans << endl;
	return 0;
}

