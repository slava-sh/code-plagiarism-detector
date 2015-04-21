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
typedef pair<int, int> point;

set<pair<int, int> > st;

vector<pair<pair<int, bool>, pair<int, int> > > v;

vector<pair<pair<int, int>, pair<int, int> > > segments;

vector<int> lines;

bool intersec(int s1, int s2)
{
	if (segments[s1].first.second < segments[s2].first.second && 
		segments[s1].second.second > segments[s2].second.second)
	{
		cout << "No" << endl << lines[s1] + 1 << ' ' << lines[s2] + 1 << endl;
		return true;
	}
	
	if (segments[s2].first.second < segments[s1].first.second && 
		segments[s2].second.second > segments[s1].second.second)
	{
		cout << "No" << endl << lines[s1] + 1 << ' ' << lines[s2] + 1 << endl;
		return true;
	}

	return false;
}

bool add(pair<int, int>  pr)
{
	pair<int, int> point = m_p(segments[pr.second].first.second, pr.second);

	set<pair<int, int> > :: iterator up_it = st.upper_bound(m_p(point.first - 1, point.second));
	set<pair<int, int> > :: iterator lw_it = st.upper_bound(m_p(point.first - 2, point.second));
	if (up_it != st.end())
		up_it++;
	while (lw_it != up_it)
	{
		if (lines[lw_it->second] == lines[pr.second])
			continue;
		if (intersec(lw_it->second, pr.second))
			return false;
		lw_it++;
	}

	up_it = st.upper_bound(m_p(point.first + 1, point.second));
	lw_it = st.upper_bound(m_p(point.first, point.second));
	
	if (up_it != st.end())
		up_it++;
	while (lw_it != up_it)
	{
		if (lines[lw_it->second] == lines[pr.second])
			continue;
		if (intersec(lw_it->second, pr.second))
			return false;
		lw_it++;
	}

	st.insert(point);

	return true;
}

bool erase(pair<int, int> pr)
{
	pair<int, int> point = m_p(segments[pr.second].first.second, pr.second);

	set<pair<int, int> > :: iterator up_it = st.upper_bound(m_p(point.first - 1, point.second));
	set<pair<int, int> > :: iterator lw_it = st.upper_bound(m_p(point.first - 2, point.second));

	if (up_it != st.end())
		up_it++;
	while (lw_it != up_it)
	{
		if (lines[lw_it->second] == lines[pr.second])
		{
			lw_it++;
			continue;
		}
		if (intersec(lw_it->second, pr.second))
			return false;
		lw_it++;
	}

	up_it = st.upper_bound(m_p(point.first + 1, point.second));
	lw_it = st.upper_bound(m_p(point.first, point.second));
	
	if (up_it != st.end())
		up_it++;
	while (lw_it != up_it)
	{
		if (lines[lw_it->second] == lines[pr.second])
		{
			lw_it++;
			continue;
		}
		if (intersec(lw_it->second, pr.second))
			return false;
		lw_it++;
	}

	st.erase(m_p(segments[point.second].first.second, point.second));
	return true;
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


	int a, b, n, m, x, y, _x, _y;

	cin >> a >> b >> n;

	fori(i, n)
	{
		cin >> m;
		m++;
 		fori(j, m)
		{
			cin >> x >> y;
			if (j != 0)
			{
				v.push_back(m_p(m_p(x, true), m_p(y, (int)segments.size())));
				segments.push_back(m_p(m_p(_x, _y), m_p(x, y)));
				lines.push_back(i);
			}
			if (j != m - 1)
			{
				v.push_back(m_p(m_p(x, false), m_p(y, (int)segments.size())));
			}
			_x = x;
			_y = y;
		}
	}

	sort(v.begin(), v.end());

	bool is_ok = true;

	fori(i, v.size())
	{
		if (!v[i].first.second)
		{
			if(!add(v[i].second))
			{
				is_ok = false;
				break;
			}
		}
		else
		{
			if (!erase(v[i].second))
			{
				is_ok = false;
				break;
			}
		}
	}

	if (is_ok)
		cout << "Yes";
//-----------------------------------------------------------
	return 0;
}