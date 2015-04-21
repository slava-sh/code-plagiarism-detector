#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <functional>
#include <queue>
#include <deque>
#include <bitset>

#define fori(i, n) for (int i = 0; i < (int)n; i++)

#define forit(i, v) for (auto i = (v).begin(); i != (v).end(); i++)

#define forab(i, a, b) for (int i = (int)a; i < (int)b; i++)

#define m_p(x, y) make_pair(x, y)
using namespace std;
struct file_opener
{
	FILE *in, *out;
	file_opener(string file_name)
	{
		in = freopen((file_name + ".in").c_str(), "r", stdin);
		out = freopen((file_name + ".out").c_str(), "w", stdout);
	}
	file_opener(string input_file, string output_file)
	{
		in = freopen((input_file + ".txt").c_str(), "r", stdin);
		out = freopen((output_file + ".txt").c_str(), "w", stdout);
	}
	~file_opener()
	{
		fclose(in);
		fclose(out);
	}
};

typedef long double ldb;
typedef long long llg;
typedef unsigned long long ullg;

vector<vector<pair<int, llg> > > g;
vector<map<llg, int> > dist;
queue<pair<llg, int> > que;

bool comp(pair<int, llg> mn, pair<int, llg> cmp)
{
	return cmp.second > mn.second;
}

int solve(int begin, int end, int d)
{
	forit(it, g[begin])
	{
		dist[it->first][it->second] = 1;
		que.push(m_p(it->second, it->first));
	}

	vector<pair<int, llg> > :: iterator find_it;
	
	int to, td, vertex, tmin = INT_MAX;

	pair<llg, int> tpair;

	while (!que.empty())
	{
		tpair = que.front();
		que.pop();

		vertex = tpair.second;

		if (vertex == end)
		{
			return dist[tpair.second][tpair.first];
		}

		tpair = m_p(tpair.first, dist[tpair.second][tpair.first]);
		
		find_it = upper_bound(g[vertex].begin(), g[vertex].end(), m_p(0, tpair.first - d - 1), comp);

		while (find_it != g[vertex].end() && abs(find_it->second - tpair.first) > d)
			find_it++;

		while (find_it != g[vertex].end() && abs(find_it->second - tpair.first) <= d)
		{
			if (dist[find_it->first].find(find_it->second) == dist[find_it->first].end())
			{
				dist[find_it->first][find_it->second] = tpair.second + 1;
				que.push(m_p(find_it->second, find_it->first));
			}
			else if (dist[find_it->first][find_it->second] > tpair.second + 1)
			{
				dist[find_it->first][find_it->second] = tpair.second + 1;
				que.push(m_p(find_it->second, find_it->first));
			}
			find_it++;
		}
	}

	int ans = INT_MAX;

	forit(it, dist[end])
		ans = min(ans, it->second);
	return (ans == INT_MAX ? -1 : ans);
}

void clear(int n)
{
	fori(i, n)
	{
		dist[i].clear();
	}
	while (!que.empty())
		que.pop();
}

int main()
{
#ifdef LOCAL
	file_opener FileOpener("test");
#else
	file_opener FileOpener("input", "output");
#endif
	cout.setf(cout.fixed);
	cout.precision(10);
//-----------------------------------------------------------

	int n, m, d, f, p, q;

	cin >> n >> m >> d;

	g.resize(n);
	dist.resize(n);

	fori(i, m)
	{
		cin >> f >> p >> q;
		f--,p--;
		g[f].push_back(m_p(p, q));
		g[p].push_back(m_p(f, q));
	}

	cin >> q;

	fori(i, q)
	{
		clear(n);
		cin >> f >> p;
		f--, p--;
		cout << solve(f, p, d) << endl;
	}

//-----------------------------------------------------------
	return 0;
}