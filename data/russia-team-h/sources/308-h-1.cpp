#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <queue>
#define eps 1e-9
#define next naoisdfa
#define end gfajpoi
#define INF 1e+15
#define txt "file"

using namespace std;
queue <int> c;
int a[5100], n, m, x, y, a1,a2, z;
long long ans;
bool was[5100];
int edges, next[200500], first[5100], end[200500], cost[200500];
long long l[5100];
void AddEdge(int x, int y, int c)
{
	next[edges] = first[x];
	first[x] = edges;
	cost[edges] = c;
	end[edges++]=y;
}
void d(int x)
{
	int v;
	while (!c.empty())
	{
		v = c.front();
		c.pop();
		for (int j = first[v]; j != -1; j = next[j])
		{
			if (was[end[j]] != 1)
				c.push(end[j]);
			was[end[j]] = 1;
			l[end[j]] = min(l[end[j]], l[v] + cost[j]);
		}
	}
}
int main()
{
	freopen(txt".in", "r", stdin);
	freopen(txt".out", "w", stdout);
	cin >> n >> m;
	ans = INF;
	memset(first, -1, sizeof(first));
	for (int i = 1; i <= n; i++)
	{
		l[i] = INF;
		cin >> a[i];
	}
	for (int j = 1; j <= m; j++)
	{
		cin >> x >> y >> z;
		AddEdge(x, y, z);
		AddEdge(y, x, z);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			l[j] = INF;
		if (a[i] == 1)
		{
			memset(was, 0, sizeof(was));
			c.push(i);
			l[i] = 0;
			d(i);
			for (int j = 1; j <= n; j++)
			{
				if (a[j] == 2 && l[j] < ans)
				{
					ans = l[j];
					a1 = i;
					a2 = j;
				}
			}
		}
	}
	if (ans == INF)
		cout << -1;
	else
		cout << a1 << ' ' << a2 << ' ' << ans;
	return 0;
}