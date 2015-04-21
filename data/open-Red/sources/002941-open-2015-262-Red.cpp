//#include "stdafx.h"
//#pragma comment(linker, "/STACK:67108864")
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <string>
#include <memory.h>

using namespace std;

struct edge
{
	long long to;
	long long t;

	edge(long long to, long long t) : to(to), t(t) {}

	bool operator<(const edge& x) const
	{
		return t < x.t;
	}

	bool operator<=(const edge& x) const
	{
		return t <= x.t;
	}

	bool operator==(const edge& x) const
	{
		return t == x.t;
	}
};

struct query
{
	long long v;
	long long t;
	long long d;

	query(long long v, long long t, long long d) : v(v), t(t), d(d) {}
};

int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	long long n, m, d, from, to, t;
	scanf("%lld%lld%lld", &n, &m, &d);

	vector<set<edge>> gg(n);

	for (long long i = 0; i < m; i++)
	{
		scanf("%lld%lld%lld", &from, &to, &t);
		from--, to--;
		gg[from].insert(edge(to, t));
		gg[to].insert(edge(from, t));
	}

	long long tests;
	scanf("%lld", &tests);

	while (--tests >= 0)
	{
		long long a, b, ans = -1;
		scanf("%lld%lld", &a, &b);
		a--, b--;

		vector<set<edge>> g(gg);
		queue<query> q;

		for (auto it = g[a].begin(); it != g[a].end(); it++)
			q.push(query(it->to, it->t, 1));

		g[a].clear();

		while (!q.empty())
		{
			query x = q.front();
			long long v = x.v;
			q.pop();

			if (v == b)
			{
				ans = x.d;
				break;
			}

			if (g[v].empty()) continue;
			long long lower_t = x.t - d;
			long long upper_t = x.t + d;
			long long dist = x.d;

			auto it = g[v].lower_bound(edge(0, lower_t));
			if (it == g[v].end()) continue;

			if (it == g[v].begin())
			{
				while (true)
				{
					auto it2 = g[v].begin();
					if (it2 == g[v].end()) break;
					assert(it2->t >= lower_t);
					if (it2->t > upper_t) break;
					q.push(query(it2->to, it2->t, dist + 1));
					g[v].erase(it2);
				}
			}

			else
			{
				--it;

				while (true)
				{
					auto it2 = it;
					++it2;
					if (it2 == g[v].end()) break;
					assert(it2->t >= lower_t);
					if (it2->t > upper_t) break;
					q.push(query(it2->to, it2->t, dist + 1));
					g[v].erase(it2);
				}
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}