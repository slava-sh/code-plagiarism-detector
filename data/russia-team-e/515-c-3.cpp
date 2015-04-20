#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#include<utility>

using namespace std;
const int X = 2 * 1e5 + 2;
bool is[X], used[X];
int d[X], mxd[X];
vector <int> lst[X], g[X];
pair <int, int> p[X];

int  u, v;
void clear()
{
	int i;
	for(i = 0; i < X; i++)
	{
		used[i] = false;
	}
}

void dfs1(int s, int cnt)
{
	int i, to;
	used[s] = true;
	d[s] = cnt;
	for(i = 0; i < lst[s].size(); i++)
	{
		to = lst[s][i];
		if(!used[to])
		{
			dfs1(to, cnt + 1);
			g[s].push_back(to);
		}
	}
	for(i = 0; i < g[s].size(); i++)
	{
		to = g[s][i];
		if(to == v || is[to])
		{
			is[s] = true;
		}
	}
}
void dfs2(int s)
{
	int i, to;
	for(i = 0; i < g[s].size(); i++)
	{
		to = g[s][i];
		dfs2(to);
	}
	if(g[s].size() == 0)
	{
		mxd[s] = 0;
	}
	for(i = 0; i < g[s].size(); i++)
	{
		to = g[s][i];
		if(!is[to] && to != v)
		{
			mxd[s] = max(mxd[to] + 1, mxd[s]);
		}
	}
}

int main()
{
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);//*/
	int n, a, b, i, j, c, mn = 0;
	cin >> n;
	for(i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		a--;
		b--;
		lst[a].push_back(b);
		lst[b].push_back(a);
		p[i] = make_pair(a, b);

	}
	cin >> u >> v;
	u--;
	v--;
	dfs1(u, 0);
	clear();
	dfs2(u);
	for(i = 0; i < n - 1; i++)
	{
		if(d[p[i].first] > d[p[i].second])
		{
			swap(p[i].first, p[i].second);
		}
		if(is[p[i].second] || p[i].second == v)
		{
			if(p[i].first == u)
			{
				mn = max(mn, min(mxd[u], mxd[p[i].second] + d[v] - d[p[i].second]));
			}
			else
			{
				mn = max(mn, min(max(mxd[u], d[p[i].first] + mxd[p[i].first]), mxd[p[i].second] + d[v] - d[p[i].second]));
			}
		}
	}
	cout << mn + 1;
	return 0;
}

/*
6
1 2
2 3
3 4
4 5
5 6
4 5
8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8
*/