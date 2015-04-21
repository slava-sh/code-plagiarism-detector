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

pair<int, int> operator - (pair<int, int> ob1, pair<int, int> ob2)
{
	return m_p(ob1.first - ob2.first, ob1.second - ob2.second);
}

llg operator ^ (pair<int, int> ob1, pair<int, int> ob2)
{
	pair<llg, llg> b1 = ob1;
	pair<llg, llg> b2 = ob2;
	return b1.first * b2.second - b1.second * b2.first;
}

bool contains_y(int s1, int s2)
{
	pair<int, int> vec = segments[s1].second - segments[s1].first;
	
	llg p1 = vec ^ (segments[s2].first - segments[s1].first);
	llg p2 = vec ^ (segments[s2].second - segments[s1].first);

	if (p1 != 0)
		p1 /= abs(p1);
	if (p2 != 0)
		p2 /= abs(p2);
	
	return p1 * p2 < 0;
}

bool intersec(int s1, int s2)
{
	point b_s1 = segments[s1].first, e_s1 = segments[s1].second;
	point b_s2 = segments[s2].first, e_s2 = segments[s2].second;

	if (b_s1.first <= b_s2.first&& 
		e_s1.first >= e_s2.first
		&& contains_y(s1, s2) && e_s1 != e_s2 && b_s1 != b_s2)
	{
		cout << "No" << endl << lines[s1] + 1 << ' ' << lines[s2] + 1 << endl;
		return true;
	}
	
	if (b_s2.first <= b_s1.first&& 
		e_s2.first >= e_s1.first
		&& contains_y(s1, s2) && e_s1 != e_s2 && b_s1 != b_s2)
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
				segments.push_back(m_p(m_p(_x, _y), m_p(x, y)));
				lines.push_back(i);
			}
			_x = x;
			_y = y;
		}
	}

	bool is_ok = true;

	for (int i = 0; i < (int)segments.size(); i++)
	{
		for (int j = i + 1; j < (int)segments.size(); j++)
			if (intersec(i, j))
			{
				is_ok = false;
				break;
			}
	}

	if (is_ok)
		cout << "Yes";
//-----------------------------------------------------------
	return 0;
}