#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int used[int(1e5) + 10], t[int(1e5) + 10], p[int(1e5) + 10], d[int(1e5) + 10];
vector < pair<int, int> > a[int(1e5) + 10];
vector <int> w;


int main()
{
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for ( int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	for ( int i = 0; i < m; i++)
	{
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		u--;
		v--;
		a[u].push_back(make_pair(v, c));
		a[v].push_back(make_pair(u, c));
	}
	for ( int i = 0; i < n; i++)
	{
		if ( t[i] != 1)
			d[i] = int(1e9);
		p[i] = -1;
	}
	for ( int q = 0; q < n; q++)
	{
		int pos = -1;
		for ( int i = 0; i < n; i++)
			if ( used[i] == 0 && (pos == -1 || d[i] < d[pos]))
				pos = i;
		used[pos] = 1;
		for ( int i = 0; i < (int)a[pos].size(); i++)
		{
			int to = a[pos][i].first;
			if ( d[pos] + a[pos][i].second < d[to])
			{
				d[to] = d[pos] + a[pos][i].second;
				p[to] = pos;
			}
	   	}
	}
	int q = -1;

	for ( int i = 0; i < n; i++)
		if ( t[i] == 2 && (q == -1 || d[q] > d[i]))
			q = i;
	if ( q == -1 || d[q] == int(1e9))
	{
		printf("-1");
		return 0;
	}
	int q1 = q;
	while ( p[q] != -1)
	{
		w.push_back(q);
		q = p[q];
   	}
   	printf("%d %d %d\n", q + 1, q1 + 1, d[q1]);
	return 0;
}