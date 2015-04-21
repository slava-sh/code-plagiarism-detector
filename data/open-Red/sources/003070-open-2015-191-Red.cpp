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

vector<vector<pair<int, int> > > g;
vector<map<int, int> > temper;
vector<map<int, int> > changed;
queue<int> q;

bool comp(pair<int, int> mn, pair<int, int> cmp)
{
	return cmp.second > mn.first;
}

int solve(int begin, int end, int d)
{
	fori(i, g[begin].size())
	{
		temper[g[begin][i].first][g[begin][i].second] = 1;

		changed[g[begin][i].first][g[begin][i].second] = 1;

		temper[begin][g[begin][i].second] = 0;		
		q.push(g[begin][i].first);
	}
	int vertex;

	vector<pair<int, int> > :: iterator find_iter;

	while (!q.empty())
	{
		vertex = q.front();
		q.pop();

		forit(it, changed[vertex])
		{
			find_iter = upper_bound(g[vertex].begin(), g[vertex].end(), m_p(it->first - d - 1, 0), comp);

			while (find_iter != g[vertex].end())
			{
				if (find_iter->second - it->first > d)
					break;

				if (temper[find_iter->first].find(find_iter->second) == temper[find_iter->first].end())
				{
					temper[find_iter->first][find_iter->second] = it->second + 1;
					changed[find_iter->first][find_iter->second] = it->second + 1;

					q.push(find_iter->first);
				}
				else if (temper[find_iter->first][find_iter->second] > it->second + 1)
				{
					temper[find_iter->first][find_iter->second] = it->second + 1;
					changed[find_iter->first][find_iter->second] = it->second + 1;

					q.push(find_iter->first);
				}
				find_iter++;
			}
		}
		changed[vertex].clear();
	}

	int ans = INT_MAX;

	forit(it, temper[end])
		ans = min(ans, it->second);
	return (ans == INT_MAX ? -1 : ans);
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
	temper.resize(n);
	changed.resize(n);

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
		cin >> f >> p;
		f--, p--;
		fori(i, n)
		{
			temper[i].clear();
			changed[i].clear();
		}

		cout << solve(f, p, d) << endl;
	}

//-----------------------------------------------------------
	return 0;
}