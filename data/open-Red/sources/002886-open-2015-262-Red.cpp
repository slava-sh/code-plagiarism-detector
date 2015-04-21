#include "stdafx.h"
#pragma comment(linker, "/STACK:67108864")
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

#define int long long

using namespace std;

struct edge
{
	int to;
	int t;

	edge(int to, int t) : to(to), t(t) {}

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
	int v;
	int t;
	int d;

	query(int v, int t, int d) : v(v), t(t), d(d) {}
};

void main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, m, d, from, to, t;
	scanf("%lld%lld%lld", &n, &m, &d);

	vector<set<edge>> gg(n);

	for (int i = 0; i < m; i++)
	{
		scanf("%lld%lld%lld", &from, &to, &t);
		from--, to--;
		gg[from].insert(edge(to, t));
		gg[to].insert(edge(from, t));
	}

	int tests;
	scanf("%lld", &tests);

	while (--tests >= 0)
	{
		int a, b, ans = -1;
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
			int v = x.v;
			q.pop();

			if (v == b)
			{
				ans = x.d;
				break;
			}

			if (g[v].empty()) continue;
			int lower_t = x.t - d;
			int upper_t = x.t + d;
			int dist = x.d;

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

	//return 0;
}