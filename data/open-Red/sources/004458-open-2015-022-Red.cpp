#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 5e5 + 111;

const int INF = 1e9 + 10;

int n, m, d, edges, a, b;

int first[MAX], nextt[MAX], endd[MAX], t[MAX];

bool was[MAX];

int ans;

int cc;

void addEdge(int i, int j, int c)
{
	nextt[edges] = first[i];
	first[i] = edges;
	endd[edges] = j;
	t[edges++] = c;
}

void dfs(int v, int dist, int temp = INF)
{
	if(dist >= ans)
		return;
	cc++;
	if(v == b)
	{
		ans = min(ans, dist);
		return;
	}
	/*if(cc > 1e6)
		return;*/
	for(int i = first[v]; i != -1; i = nextt[i])
	{
		if(!was[i / 2])
		{
			if(temp == INF || abs(temp - t[i]) <= d)
			{
				was[i / 2] = true;
				dfs(endd[i], dist + 1, t[i]);
				was[i / 2] = false;
			}
		}
	}
}

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	fill(first, first + MAX, -1);
	scanf("%d %d %d", &n, &m, &d);
	for(int i = 0; i < m; i++)
	{
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		addEdge(--a, --b, t);
		addEdge(b, a, t);
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		scanf("%d %d", &a, &b);
		a--;b--;
		cc = 0;
		ans = INF;
		dfs(a, 0);
		if(ans == INF)
			printf("%d\n", -1);
		else printf("%d\n", ans);
	}
	return 0;
}
