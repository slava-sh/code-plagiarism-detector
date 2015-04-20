#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;

vector <vector <int> > graph;
vector <int> ancestor;
vector <int> tin;
vector <int> tout;
vector <int> dp;
vector <int> depth;
int v, u;
int Time = 0;
vector <bool> used;
int n;

void dfs1(int v, int d = 0, int pre = -1)
{
	depth[v] = d;
	used[v] = true;
	tin[v] = Time++;
	ancestor[v] = (pre == -1 ? v : pre);
	for (int i = 0; i < graph[v].size(); ++i)
	{
		if (!used[graph[v][i]])
		{
			dfs1(graph[v][i], d + 1, v);
		}
	}
	tout[v] = Time++;
}

int dpCount(int v, int f1, int f2)
{
	used[v] = 1;
	for (int i = 0; i < graph[v].size(); ++i)
	{
		if (!used[graph[v][i]] && graph[v][i] != f1 && graph[v][i] != f2)
		{
			dp[v] = max(dp[v], dpCount(graph[v][i], f1, f2) + 1);
		}
	}
	return dp[v];
}

void dpRecountStart(int f1, int f2)
{
	dp.assign(n, 1);
	used.assign(n, 0);
	dpCount(v, f1, f2);
}

bool weCan(int x)
{
	dpRecountStart(-1, -1);
	int curSteps = 0;
	int uu = u;
	int previousSon = -1;
	do
	{	
		if (uu == v)
			return false;
		int Max = 0;
		for (int i = 0; i < graph[uu].size(); ++i)
		{
			if (graph[uu][i] != ancestor[uu] && graph[uu][i] != previousSon)
				Max = max(Max, dp[graph[uu][i]]);
		}
		Max += 1;
		if (Max >= (x - curSteps))
			break;
		previousSon = uu;
		uu = ancestor[uu];
		++curSteps;
	}
	while (true);
	dpRecountStart(uu, -1);
	if (dp[v] >= x)
		return 1;
	return 0;
}

int main()
{
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);
	scanf("%d", &n);
	graph.resize(n);
	tin.resize(n);
	tout.resize(n);
	ancestor.resize(n);
	depth.resize(n);
	int a, b;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d %d", &a, &b);
		--a;
		--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	used.assign(n, 0);

	scanf("%d %d", &u, &v);
	--u;
	--v;
	dfs1(v);
	int low = 0;
	int high = n + 1;
	while (low != high - 1)
	{
		int middle = (low + high) / 2;
		if (weCan(middle))
		{
			low = middle;
		}
		else
		{
			high = middle;
		}
	}
	printf("%d\n", low);
	return 0;
}