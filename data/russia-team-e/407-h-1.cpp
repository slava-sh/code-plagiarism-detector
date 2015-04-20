#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <fstream>

using namespace std;

vector<vector<pair<int, int> > > v(10000);
int n, m, a[5101], d[5101], x, y, z;
int pr[5101];

set<pair<int, int> > s;

void dj(int vert)
{
	int dist = 0;
	pair<int, int> p;
	for (int i = 0; i <= n + 1; i++)
	{
		d[i] = INT_MAX;
	}
	d[vert] = 0;
	s.insert(make_pair(0, vert));
	while (!s.empty())
	{
		p = *s.begin();
		s.erase(s.begin());
		dist = p.first;
		vert = p.second;
		for (int i = 0; i < (int)v[vert].size(); i++)
		{
			if (d[v[vert][i].first] > dist + v[vert][i].second)
			{
				d[v[vert][i].first] = dist + v[vert][i].second;
				pr[v[vert][i].first] = vert;
				s.insert(make_pair(d[v[vert][i].first], v[vert][i].first));
			}
		}
	}
}

int main()
{
	FILE *in, *out;
	in = freopen("secure.in", "r", stdin);
	out = freopen("secure.out", "w", stdout);
//-------------------------------------------------------------------

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		v[x].push_back(make_pair(y, z));
		v[y].push_back(make_pair(x, z));
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1)
			v[n + 1].push_back(make_pair(i, 0));
	}
	dj(n + 1);
	int dist = INT_MAX, p = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 2 && d[i] < dist)
		{
			dist = d[i];
			p = i;
		}
	}
	if (dist == INT_MAX)
	{
		cout << "-1";
		return 0;
	}

	int l, r = p;

	while (pr[p] != n + 1)
	{
		p = pr[p];
	}
	l = p;
	cout << l << ' ' << r << ' ' << dist;

//-------------------------------------------------------------------
	fclose(in);
	fclose(out);
	return 0;
}
