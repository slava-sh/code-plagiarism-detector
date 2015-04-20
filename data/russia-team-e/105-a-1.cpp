#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = (int)1e3 + 100;
const long long mod = (long long)1e9 + 7;

struct Edge
{
	int v, t;
	Edge () {}
	Edge (int v, int t) : v(v), t(t) {}
};

int z[N];
int color[N];
vector <Edge> g[N];
vector <int> sG[N];
bool used[N];
int tc[N];
int cc = 1;

void paintV(int v)
{
	color[v] = cc;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i].v;
		if (g[v][i].t == 0 && !color[to])
		{
			paintV(to);
		}
	}
}

bool dfs(int v)
{
	int p = (tc[v] == 1 ? 2 : 1);
	for (int i = 0; i < (int)sG[v].size(); i++)
	{
		int to = sG[v][i];
		if (!tc[to])
		{
			tc[to] = p;
			if (!dfs(to))
				return false;
		}
		else
		{
			if (p != tc[to])
				return false;
		}
	}
	return true;
}

bool tryPaint()
{
	for (int i = 1; i < cc; i++)
	{
		if (!used[i])
		{
			tc[i] = 1;
			if (!dfs(i))
				return false;
		}
	}
	return true;
}

void fail()
{
	puts("0");
	exit(0);
}

void dfsComp(int v)
{
	used[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i].v;
		if (!used[to])
			dfsComp(to);
	}
}

int main()
{
	freopen ("binary.in", "r", stdin);
	freopen ("binary.out", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &z[i]);

	for (int i = 1; i < n; i++)
	{
		if (z[i] == -1)
			continue;
		if (i + z[i] > n)
			fail();
		for (int s = 0; s < z[i]; s++)
		{
			g[s].push_back(Edge(i + s, 0));
			g[i + s].push_back(Edge(s, 0));
		}
		g[z[i]].push_back(Edge(i + z[i], 1));
		g[i + z[i]].push_back(Edge(z[i], 1));
	}

	for (int i = 0; i < n; i++)
	{
		if (!color[i])
		{
			paintV(i);
			cc++;
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < (int)g[i].size(); s++)
		{
			int to = g[i][s].v;
			if (g[i][s].t == 1)
			{
				if (color[to] == color[i])
				{
					fail();
				}
				sG[i].push_back(to);
				sG[to].push_back(i);
			}
		}
	}

	if (!tryPaint())
		fail();

	memset(used, 0, sizeof(used));

	long long ans = 1;

	for (int i = 0; i < n; i++)
	{
		if (!used[i])
		{
			ans = (ans * 2) % mod;
			dfsComp(i);
		}
	}
	printf("%lld", ans);

	return 0;
}