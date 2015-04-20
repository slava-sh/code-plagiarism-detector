#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include <set>

#define ll long long
#define TASKNAME "secure"

using namespace std;

const int INF = 1e6;

void dfs(vector <vector <pair <int, int> > > & G, vector <int> & d, vector <int> & p)
{
	int n = int(d.size());
	vector <int> mark(n);

	while (true)
	{
		int u = -1;

		for (int i = 0; i < n; i++)
			if (mark[i] == 0 && (u == -1 || d[i] < d[u]))
				u = i;

		if (u == -1 || d[u] >= INF)
			break;
		mark[u] = 1;

		for (int j = 0; j < int(G[u].size()); j++)
		{
			int to = G[u][j].first, w = G[u][j].second;

			if (d[u] + w < d[to])
			{
				d[to] = d[u] + w;
				p[to] = u;
			}
		}
	}
}

int main() {
#ifdef SHAOLING
	freopen("input.txt", "r", stdin);
#else
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector <vector <pair <int, int> > > G(n);
	vector <int> d(n, INF), p(n, -1), A(n);

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];

		if (A[i] == 1)
			d[i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		G[a].push_back(make_pair(b, c));
		G[b].push_back(make_pair(a, c));
	}
	dfs(G, d, p);
	int resb = -1;

	for (int i = 0; i < n; i++)
	{
		if (A[i] == 2 && (resb == -1 || d[i] < d[resb]))
			resb = i;
	}

	if (d[resb] >= INF)
	{
		cout << "-1\n";
		return 0;
	}
	int resa = resb;

	while (A[resa] != 1)
		resa = p[resa];

	cout << resa + 1 << ' ' << resb + 1 << ' ' << d[resb] << '\n';
	return 0;
}