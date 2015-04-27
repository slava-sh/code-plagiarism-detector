#include <iostream>               
#include <cstdio>
#define MaxV 500009
#define MaxE 1600009
#define inf 1000000000
using namespace std;

int n, m, cur = 0;
int next[MaxE], first[MaxE], end[MaxE], was[MaxV], D[MaxV], cost[MaxE];
int A[15][MaxV], head[MaxV], tail[MaxV];

void push(int q, int a)
{
	tail[q]++;
	A[q][tail[q]] = a;
}

int pop(int q)
{
	head[q]++;
	return A[q][head[q] - 1];
}

bool empty(int q)
{
	if (head[q] > tail[q])
	{
		head[q] = 1;
		tail[q] = 0;
		return true;
	}
	else
		return false;
}

void bfs(int x)
{
	push(0, x);
	was[x] = 1;
	while (true)
	{
		int jj = 0;
		bool flag = false;
		while (empty(cur))
		{
			jj++;
			cur++;
			if (jj > 12)
			{
				flag = true;
				break;
			}
		}
		if (flag) break;
		cur %= 13;
		while (empty(cur) == false)
		{
			int u;
			int ver = pop(cur);
			was[ver] = 1;
			for (u = first[ver]; u > 0; u = next[u])
			{
				if (was[end[u]] == 0 && D[end[u]] > D[ver] + cost[u])
				{                        	
					D[end[u]] = D[ver] + cost[u];
					push((cur + cost[u]) % 13, end[u]);
				}
			}
		}
	}
}

int main()
{
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);

	int i, n, m, p, q, c;
	cin >> n >> m;
	int u = 0;
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &p, &q, &c);
		u++;
		next[u] = first[p];
		first[p] = u;
		end[u] = q;
		if (c == 1) cost[u] = 12;
		if (c == 2) cost[u] = 6;
		if (c == 3) cost[u] = 4;
		if (c == 4) cost[u] = 3;
		u++;
		next[u] = first[q];
		first[q] = u;
		end[u] = p;
		cost[u] = cost[u - 1];
	}

	for (i = 1; i <= n; i++)
		D[i] = inf;
	for (i = 0; i <= 12; i++)
		head[i] = 1;
	D[1] = 0;

	bfs(1);

	double ans = 0;
	for (i = 2; i <= n; i++)
	{
		ans = D[i];
		ans /= 12;
		printf("%.10f\n", ans);
	}

	return 0;
}