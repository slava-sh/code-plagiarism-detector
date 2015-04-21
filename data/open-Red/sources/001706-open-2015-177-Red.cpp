#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
const int MAXN = 100500;

int n, m, d;
vector <vector <pair <int, int> > > g;
map <pair <int, int>, int> dist;

void solve(int v, int to)
{	
	dist.clear();
	int res = MAXN;
	queue <pair<int, int> > q;
	
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		dist[g[v][i]] = 1;
		q.push(g[v][i]);
		if (g[v][i].first == to)
			res = min(res, 1);
	}

	while (!q.empty())
	{
		pair <int, int> cond = q.front();
		q.pop();
		int v = cond.first;
		int temp = cond.second;
		
		for (int i = 0; i < (int)g[v].size(); i++)
		{
			if (dist.count(g[v][i]) == 0 && abs(temp - g[v][i].second) <= d)
			{				
				dist[g[v][i]] = dist[cond] + 1;
				q.push(g[v][i]);				
				if (g[v][i].first == to)
					res = min(res, dist[g[v][i]]);
			}
		}
	}
	printf("%d\n", (res == MAXN ? -1 : res));
}


int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	scanf("%d%d%d", &n, &m, &d);
	g.resize(n);
	for(int i = 0; i < m; i++)
	{
		int v, to, cost;
		scanf("%d%d%d", &v, &to, &cost);
		v--;
		to--;
		g[v].push_back(make_pair(to, cost));
		g[to].push_back(make_pair(v, cost));
	}

	int q;
	scanf("%d", &q);

	for (int i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		solve(a - 1, b - 1);
	}
	
	return 0;
}