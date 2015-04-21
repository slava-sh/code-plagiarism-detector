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

vector<vector<pair<pair<int, int>, pair<int, int> > > > segments;

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


bool intersec(int s1, int s2)
{
	if (segments[s1][0].first.second < segments[s2][0].first.second)
		swap(s1, s2);
	else if (segments[s1][0].first == segments[s2][0].first)
	{
		if (segments[s1].back().second.second < segments[s2].back().second.second)
			swap(s1, s2);
	}

	if (segments[s1].back().second.second < segments[s2].back().second.second &&
		segments[s1][0].first != segments[s2][0].first)
		return true;

	int l = 0, l_n = segments[s1].size(), r = 0, r_n = segments[s2].size();

	while (l < l_n && r < r_n)
	{
		while (l < l_n && segments[s2][r].first.first > segments[s1][l].second.first)
			l++;
		
		if (l < l_n && segments[s2][r].first.second < segments[s1][l].first.second)
			return true;

		r++;
	}
	return false;
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

	segments.resize(n);

	fori(i, n)
	{
		cin >> m;
		m++;
 		fori(j, m)
		{
			cin >> x >> y;
			if (j != 0)
			{
				segments[i].push_back(m_p(m_p(_x, _y), m_p(x, y)));
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
				cout << "No" << endl << i + 1 << ' ' << j + 1 << endl;
				break;
			}
	}

	if (is_ok)
		cout << "Yes";
//-----------------------------------------------------------
	return 0;
}