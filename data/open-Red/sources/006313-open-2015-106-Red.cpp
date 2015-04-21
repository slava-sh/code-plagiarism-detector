#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <queue>
#include <string>
#include <cstring>
#define NAME ""
#define mp make_pair
#define mt make_tuple
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int nmax = 1500 * 100;
const int inf = 1000 * 1000 * 1000;
const ll infll = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
const ld pi = acos(-1.0);
const ll mod = 1000 * 1000 * 1000 + 7;

template<typename T, typename T1>
ostream& operator <<  (ostream& cout, const pair<T, T1> &a)
{
	return (cout << "(" << a.first << "; " << a.second << ")");
}

template<typename T>
ostream& operator << (ostream& cout, const vector<T> &a)
{
	if (a.size() == 0)
		return (cout << "()");
	cout << "(";
	for (int i = 0; i < (int)a.size() - 1; i++)
		cout << a[i] << "; ";
	cout << a.back() << ")";
	return cout;
}

struct edge
{
	int x, y, t;
	edge(){}
	edge(int X, int Y, int T)
	{
		x = X;
		y = Y;
		t = T;
	}
};

struct go
{
	int y, t, ind;
	go(){}
	go(int Y, int T, int IND)
	{
		y = Y;
		t = T;
		ind = IND;
	}
};

int n, m, d, x, y, t, q;
vector<go> a[nmax];
vector<edge> ed;
vector<pair<int, bool> > used[nmax];
queue<pair<int, int> > qu;
vector<pair<int, int> > dist[nmax];

int main()
{
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	cin >> n >> m >> d;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &x, &y, &t);
		x--;
		y--;
		a[x].pb(go(y, t, i));
		a[y].pb(go(x, t, i));
		ed.pb(edge(x, y, t));
	}
	scanf("%d", &q);
	for (int zz = 0; zz < q; zz++)
	{
		scanf("%d%d", &x, &y);
		x--;
		y--;
		while (!qu.empty())
			qu.pop();
		for (int i = 0; i < n; i++)
		{
			used[i].clear();
			dist[i].clear();
			for (int j = 0; j < (int)a[i].size(); j++)
			{
				used[i].pb(mp(a[i][j].ind, false));
				dist[i].pb(mp(a[i][j].ind, inf));
			}	
		}	
		for (int i = 0; i < (int)a[x].size(); i++)
		{
			qu.push(mp(x, a[x][i].ind));
			dist[x][lower_bound(dist[x].begin(), dist[x].end(), mp(a[x][i].ind, 0)) - dist[x].begin()].second = 0;
			used[x][lower_bound(used[x].begin(), used[x].end(), mp(a[x][i].ind, false)) - used[x].begin()].second = true;
		}	
		while (!qu.empty())
		{
			pair<int, int> v = qu.front();
			qu.pop();
			for (int j = 0; j < (int)a[v.first].size(); j++)
			{
				int u = a[v.first][j].y;
				if (!used[u][lower_bound(used[u].begin(), used[u].end(), mp(a[v.first][j].ind, false)) - used[u].begin()].second && abs(ed[v.second].t - ed[a[v.first][j].ind].t) <= d)
				{                       	
					dist[u][lower_bound(dist[u].begin(), dist[u].end(), mp(a[v.first][j].ind, 0)) - dist[u].begin()].second = dist[v.first][lower_bound(dist[v.first].begin(), dist[v.first].end(), mp(v.second, 0)) - dist[v.first].begin()].second + 1;
					used[u][lower_bound(used[u].begin(), used[u].end(), mp(a[v.first][j].ind, false)) - used[u].begin()].second = true;
					qu.push(mp(u, a[v.first][j].ind));
				}
			}
		}
		int answer = inf;
		for (int j = 0; j < (int)a[y].size(); j++)
			answer = min(answer, dist[y][lower_bound(dist[y].begin(), dist[y].end(), mp(a[y][j].ind, 0)) - dist[y].begin()].second);
		if (answer >= inf)
			printf("-1\n");
		else
			printf("%d\n", answer);
	}
	return 0;
}