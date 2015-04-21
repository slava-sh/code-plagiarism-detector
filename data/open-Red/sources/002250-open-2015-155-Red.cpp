#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

const long long Inf = 1000000000009;

struct edge
{
	long long u, v, t, id;
	edge(){}
	edge(long long u, long long v, long long t, long long id) : u(u), v(v), t(t), id(id) {}
};

vector<edge> lst[100009];

map<long long, long long> d[200009];

int main()
{
	long long n, m, d1;
	cin >> n >> m >> d1;
	for (long long i = 0; i < m; ++i)
	{
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		lst[a].push_back(edge(a, b, t, i));
		lst[b].push_back(edge(b, a, t, i));
	}
	long long q1;
	cin >> q1;
	for (long long i = 0; i < q1; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		queue<pair<long long, long long> > q;
		for (long long i = 0; i < (long long)lst[a].size(); ++i)
		{
			d[a][lst[a][i].t] = 0;
			q.push(make_pair(a, lst[a][i].t));
		}
		while (!q.empty())
		{
			pair<long long, long long> v = q.front();
			q.pop();
			long long currd;
			auto itr = d[v.first].lower_bound(v.second);
			currd = itr->second;
			/*long long l = 0, r = (long long)lst[v.first].size();
			while (r - l > 1)
			{
				long long bm = (l + r) / 2;
				if (lst[v.first][bm].t + d1 <= v.second)
					l = bm;
				else
					r = bm;
			}
			long long l1 = l;
			l = 0, r = (long long)lst[v.first].size();
			while (r - l > 1)
			{
				long long bm = (l + r) / 2;
				if (lst[v.first][bm].t >= v.second + d1)
					r = bm;
				else
					l = bm;
			}
			long long r1 = r;*/
			for (long long i = 0; i < (long long)lst[v.first].size(); ++i)
			{
				if (abs(lst[v.first][i].t - v.second) <= d1)
				{
					long long u = lst[v.first][i].v;
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
			long long min_ = Inf;
			for (auto it = d[b].begin(); it != d[b].end(); ++it)
				min_ = min(min_, it->second);
			cout << min_ << endl;
		}
		for (long long i = 1; i <= n; ++i)
			d[i].clear();

	}
}