#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include <set>
#include <queue>

#define ll long long
#define mp make_pair

#define TASKNAME "dwarfs"

using namespace std;

const int maxn = 3e5;
const int INF = int(1e9);

void bfs(int u, vector <vector <int> > & G, vector <int> & d, vector <int> & p)
{
	int n = int(d.size());
	queue <int> Q;
	Q.push(u);
	vector <int> mark(n);
	mark[u] = 1;
	d[u] = 0;

	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();

		for (int i = 0; i < G[u].size(); i++)
		{
			int to = G[u][i];

			if (!mark[to] && d[u] + 1 < d[to])
			{
				d[to] = d[u] + 1;
				mark[to] = 1;
				Q.push(to);
				p[to] = u;
			}
		}
	}
}

int dfs(int u, vector <vector <int> > & G, vector <int> & mark)
{
	mark[u] = 1;
	int now = 0;

	for (int i = 0; i < G[u].size(); i++)
	{
		if (!mark[G[u][i]])
			now = max(now, dfs(G[u][i], G, mark) + 1);
	}
	return now;
}

int main() {
#ifdef SHAOLING
	freopen("input.txt", "r", stdin);
#else
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif

	int n;
	cin >> n;
	vector <vector <int> > G(maxn);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int s1, s2;
	cin >> s1 >> s2;
	s1--, s2--;
	vector <int> d(maxn, INF), p(maxn, -1);
	bfs(s1, G, d, p);
	vector <int> path;
	int now = s2;

	while (now != s1)
	{
		path.push_back(now);
		now = p[now];
	}
	path.push_back(s1);
	reverse(path.begin(), path.end());

	vector <int> mark(maxn);

	for (int i = 0; i < int(path.size()); i++)
		mark[path[i]] = 1;
	vector <int> A;

	for (int i = 0; i < int(path.size()); i++)
		A.push_back(dfs(path[i], G, mark));
	vector <int> ff(maxn), ss(maxn);

	for (int i = 0; i < int(path.size()); i++)
		ff[i] = (i == 0 ? A[i] + i : max(ff[i - 1], A[i] + i));

	ss.push_back(0);
	for (int i = int(path.size()) - 1; i >= 0; i--)
		ss[i] = (i == int(path.size()) - 1 ? A[i] + int(path.size()) - i - 1 : max(ss[i + 1],  A[i] + int(path.size()) - i - 1));
	int res = 0;
	

	for (int i = 0; i < int(path.size()); i++)
		res = max(res, min(ff[i], ss[i + 1]));
	cout << res + 1 << '\n';
	return 0;
}