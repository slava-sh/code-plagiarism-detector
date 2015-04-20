#include <iostream>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = (int)1e9 + 100;
const int M = (int)2e5 + 100;
const int N = 6000;

struct Edge
{
	int a, b, c;
	Edge () {}
	Edge (int a, int b, int c) : a(a), b(b), c(c) {}
};
struct Item
{
	int v, ind;
	Item () {}
	Item (int v, int ind) : v(v), ind(ind) {}
};
struct Vertex
{
	int v, dist;
	Vertex () {}
	Vertex (int v, int dist) : v(v), dist(dist) {}
	bool operator < (const Vertex &x) const
	{
		if (x.dist != dist)
			return dist < x.dist;
		return v < x.v;
	}
};

vector <Item> g[N];
Edge listE[M];
int indE;
bool used[N];
int dist[N];
int color[N];
int par[N];

int main()
{
	freopen ("secure.in", "r", stdin);
	freopen ("secure.out", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &color[i]);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		listE[indE++] = Edge(a, b, c);
		listE[indE++] = Edge(b, a, c);

		int tA = a, tB = b;
		if (color[a] == 1)
			tA = n;
		if (color[a] == 2)
			tA = n + 1;
		if (color[b] == 1)
			tB = n;
		if (color[b] == 2)
			tB = n + 1;
		g[tA].push_back(Item(tB, indE - 2));
		g[tB].push_back(Item(tA, indE - 1));
	}

	for (int i = 0; i < N; i++)
		dist[i] = INF;
	dist[n] = 0;

	while (1)
	{
		int bestV = -1;
		int bestD = INF;
		for (int i = 0; i <= n + 1; i++)
		{
			if (!used[i] && bestD > dist[i])
			{
				bestD = dist[i];
				bestV = i;
			}
		}
		if (bestV == -1)
			break;
		int v = bestV;
		used[v] = 1;

		for (int i = 0; i < (int)g[v].size(); i++)
		{
			int e = g[v][i].ind;
			int to = g[v][i].v;
			if (dist[to] > dist[v] + listE[e].c)
			{
				par[to] = e;
				dist[to] = dist[v] + listE[e].c;
			}
		}
	}

	if (dist[n + 1] == INF)
	{
		puts("-1");
		return 0;
	}

	int t = n + 1;
	int cur = listE[par[n + 1]].b;
	int a, b;
	b = cur;
	while (1)
	{
		t = listE[par[t]].a;
		if (color[t] == 1)
		{
			a = t;
			break;
		}
	}
	printf("%d %d %d", a + 1, b + 1, dist[n + 1]);

	return 0;
}