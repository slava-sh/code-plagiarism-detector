#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

const int Inf = 1000000009;

struct edge
{
	int u, v, t, id;
	edge(){}
	edge(int u, int v, int t, int id) : u(u), v(v), t(t), id(id) {}
	bool operator<(edge x)
	{
		return (t < x.t);
	}
};

vector<edge> lst[100009];

map<int, int> d[200009];

int main()
{
	int n, m, d1;
	cin >> n >> m >> d1;
	for (int i = 0; i < m; ++i)
	{
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		lst[a].push_back(edge(a, b, t, i));
		lst[b].push_back(edge(b, a, t, i));
	}
	int q1;
	cin >> q1;
	for (int i = 0; i < q1; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		queue<pair<int, int> > q;
		for (int i = 0; i < (int)lst[a].size(); ++i)
		{
			d[a][lst[a][i].t] = 0;
			q.push(make_pair(a, lst[a][i].t));
		}
		while (!q.empty())
		{
			pair<int, int> v = q.front();
			q.pop();
			int currd;
			auto itr = d[v.first].lower_bound(v.second);
			currd = itr->second;
			int l = 0, r = (int)lst[v.first].size();
			while (r - l > 1)
			{
				int bm = (l + r) / 2;
				if (lst[v.first][bm].t + d1 < v.second)
					l = bm;
				else
					r = bm;
			}
			int l1 = l;
			l = 0, r = (int)lst[v.first].size();
			while (r - l > 1)
			{
				int bm = (l + r) / 2;
				if (lst[v.first][bm].t > v.second + d1)
					r = bm;
				else
					l = bm;
			}
			int r1 = r;
			l = l1, r = r1;
			while(l1 < 0 || lst[v.first][l1].t - v.second < -d1)
				++l1;
			while (r1 >= (int)lst[v.first].size() || lst[v.first][r1].t - v.second > d1)
				--r1;
			if (l1 > r1)
				continue;

			for (int i = l1; i <= r1; ++i)
			{
				{
					int u = lst[v.first][i].v;
					auto it = d[u].lower_bound(lst[v.first][i].t);
					if (it != d[u].end())
					{
						if (it->first == lst[v.first][i].t)
						{
							if (it->second <= currd + 1)
							{
								continue;
							}
						}
					}
					d[u][lst[v.first][i].t] = currd + 1;
					q.push(make_pair(u, lst[v.first][i].t));
				}
			}
		}
		if (d[b].empty())
		{
			cout << -1 << endl;
		}
		else
		{
			int min_ = Inf;
			for (auto it = d[b].begin(); it != d[b].end(); ++it)
				min_ = min(min_, it->second);
			cout << min_ << endl;
		}
		for (int i = 1; i <= n; ++i)
			d[i].clear();

	}
}