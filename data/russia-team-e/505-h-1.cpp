#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define ld long double
const int MAX_N = 5005;
const int MAX_M = 100005;
const int INF = 2000000000;

struct elem
{
	int v, d;
	elem() {v = -1; d = INF;}
	elem(int v, int d):v(v), d(d) {}
};

int d[MAX_N];
vector<elem> e[MAX_N];
int colour[MAX_N];
int from[MAX_N];
int flag[MAX_N];

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &colour[i]);
	for (int i = 0; i < m; i++)
	{
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		x--;
		y--;
		e[x].push_back(elem(y, c));
		e[y].push_back(elem(x, c));
	}

	for (int i = 0; i < n; i++)
	{
		d[i] = INF;
		from[i] = -1;
	}

	for (int i = 0; i < n; i++)
		if (colour[i] == 1)
			d[i] = 0;

	while (1)
	{
		int v, minim = INF;
		for (int i = 0; i < n; i++)
			if (flag[i] == 0 && d[i] < minim && colour[i] != 2)
			{
				minim = d[i];
				v = i;
			}
		if (minim == INF)
			break;
		flag[v] = 1;
		for (int i = 0; i < (int)e[v].size(); i++)
			if (flag[e[v][i].v] == 0 && d[v] + e[v][i].d < d[e[v][i].v])
			{
				d[e[v][i].v] = d[v] + e[v][i].d;
				from[e[v][i].v] = v;
			}
	}

	int min_dist = INF;
	int v = -1;
	for (int i = 0; i < n; i++)
		if (colour[i] == 2 && d[i] < min_dist)
		{
			min_dist = d[i];
			v = i;
		}

	if (min_dist == INF)
		cout << -1;
	else
	{
		int p_kon = v;
		int p_nach;
		while (from[v] != -1)
			v = from[v];
		p_nach = v;
		cout << (p_nach  + 1) << " " << (p_kon  + 1) << " " << d[p_kon] << "\n";
		return 0;
	}

	return 0;
}