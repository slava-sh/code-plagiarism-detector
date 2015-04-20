#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

struct way_
{
	long long v, pr;
	bool operator < (const way_ &a) const {
		return pr < a.pr || pr == a.pr && v < a.v;
	}
};

long long x, y, ans;
int const Max = 5555;
int n, m;
int v1, v2;
int mark[Max];
long long const INF = Max * 101101;
long long d[Max];
int f[Max];
vector <way_> dist[Max];
set <way_> s;

int X;

void D(int v)
{
	//cout << ans << ' ' << x << ' ' << y << endl;
	f[v] = 1;
	for (int i = 0; i < dist[v].size(); i++)
		if (d[dist[v][i].v] > d[v] + dist[v][i].pr)
		{
			d[dist[v][i].v] = d[v] + dist[v][i].pr;
			if (mark[X] + mark[dist[v][i].v] == 3)
			{
				if (d[dist[v][i].v] < ans)
				{
					ans = d[dist[v][i].v];
					if (mark[X] == 1)
					{
						x = X;
						y = dist[v][i].v;
					}
					else
					{
						y = X;
						x = dist[v][i].v;
					}
				}
			}
			way_ way;
			way.v = dist[v][i].v;
			way.pr = dist[v][i].pr;
			s.insert(way);
		}
	for (set <way_>::iterator it = s.begin(); it != s.end(); it++)
		if (f[(*it).v] == 0)
		{
			int newV = ((*it).v);
			/*
			for (set <way_>::iterator it1 = s.begin(); it1 != it; it1++)
				s.erase(*it1);
			*/
			D(newV);
			break;
		}
}

int main()
{
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	scanf(" %d %d", &n, &m);
	v1 = 0;
	v2 = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf(" %d", &mark[i]);
		if (mark[i] == 1)
			v1++;
		if (mark[i] == 2)
			v2++;
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		scanf(" %d %d %d", &a, &b, &c);
		way_ w;
		w.pr = c;
		w.v = b;
		dist[a].push_back(w);
		w.v = a;
		dist[b].push_back(w);
	}
	ans = INF;
	x = -1;
	y = -1;
	for (int i = 1; i <= n; i++)
	{
		if (mark[i] == 1 && v1 <= v2)
		{
			s.clear();
			for (int j = 0; j < Max; j++)
			{
				f[j] = 0;
				d[j] = INF;
			}
			d[i] = 0;
			X = i;
			D(i);
		}
		if (mark[i] == 2 && v2 < v1)
		{
			s.clear();
			for (int j = 0; j < Max; j++)
			{
				f[j] = 0;
				d[j] = INF;
			}
			d[i] = 0;
			X = i;
			D(i);
		}
	}
	if (ans == INF)
		printf("-1\n");
	else
		printf("%lld %lld %lld\n", x, y, ans);
	return 0;
}
/*
6 7
1 0 1 2 2 0
1 3 3
1 2 4
2 3 3
2 4 2
1 6 5
3 5 6
5 6 1
*/