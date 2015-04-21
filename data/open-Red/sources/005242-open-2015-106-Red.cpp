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

const int nmax = 1000 * 1000;
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
map<int, bool> used[nmax];
queue<pair<int, int> > qu;
map<int, int> dist[nmax];

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
			for (int j = 0; j < (int)a[i].size(); j++)
			{
				used[i][a[i][j].ind] = false;
				dist[i][a[i][j].ind] = inf;
			}	
		for (int i = 0; i < (int)a[x].size(); i++)
		{
			qu.push(mp(x, a[x][i].ind));
			dist[x][a[x][i].ind] = 0;
		}	
		while (!qu.empty())
		{
			pair<int, int> v = qu.front();
			qu.pop();
			for (int j = 0; j < (int)a[v.first].size(); j++)
			{
				int u = a[v.first][j].y;
				if (!used[u][a[v.first][j].ind] && abs(ed[v.second].t - ed[a[v.first][j].ind].t) <= d)
				{
					dist[u][a[v.first][j].ind] = dist[v.first][v.second] + 1;
					used[u][a[v.first][j].ind] = true;
					qu.push(mp(u, a[v.first][j].ind));
				}
			}
		}
		int answer = inf;
		for (int j = 0; j < (int)a[y].size(); j++)
			answer = min(answer, dist[y][a[y][j].ind]);
		if (answer >= inf)
			cout << -1 << endl;
		else
			cout << answer << endl;
	}
	return 0;
}