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
queue<int> que;

bool comp(pair<int, int> mn, pair<int, int> cmp)
{
	return cmp.second > mn.first;
}

int solve(int begin, int end, int d)
{
	forit(it, g[begin])
	{
		changed[it->first][it->second] = 1;
		temper[begin][it->second] = 0;
		que.push(it->first);
	}

	vector<pair<int, int> > :: iterator find_it;

	int to, td, vertex, tmin = INT_MAX;
	while (!que.empty())
	{
		vertex = que.front();
		que.pop();

		forit(it, changed[vertex])
		{
			if (vertex == end)
				tmin = min(tmin, it->second);
			find_it = upper_bound(g[vertex].begin(), g[vertex].end(), m_p(it->first - d - 1, 0), comp);

			while (find_it != g[vertex].end())
			{
				if (find_it->second - it->first > d)
					break;

				to = find_it->first;
				td = find_it->second;
				if (temper[to].find(td) == temper[to].end() && 
					(changed[to].find(td) == changed[to].end() || changed[to][td] > it->second + 1))
				{
					changed[to][td] = it->second + 1;
					que.push(to);
				}
				else if (temper[to].find(td) != temper[to].end() && temper[to][td] > it->second + 1 && 
					(changed[to].find(td) == changed[to].end() || changed[to][td] > it->second + 1))
				{
					changed[to][td] = it->second + 1;
					que.push(to);
				}
				find_it++;
			}
			temper[vertex][it->first] = it->second;
		}
		//changed[vertex].clear();
		if (vertex == end)
			return tmin;
	}

	int ans = INT_MAX;

	forit(it, temper[end])
		ans = min(ans, it->second);
	forit(it, changed[end])
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
			while(!que.empty())
				que.pop();
		}


		cout << solve(f, p, d) << endl;
	}

//-----------------------------------------------------------
	return 0;
}