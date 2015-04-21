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

vector<vector<pair<int, int> > > v;

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
	
	if (v[s1][0].second < v[s2][0].second)
		swap(s1, s2);
	else if (v[s1][0] == v[s2][0] && v[s1].back().second < v[s2].back().second)
		swap(s1, s2);

	if (v[s1].back().second < v[s2].back().second)
		return true;
	
	vector<pair<int, int> > v1 = v[s1], v2 = v[s2];
	int l = 0, l_n = v1.size(), r = 1, r_n = v2.size();

	pair<int, int> vec1, vec2;


	while (l != l_n && r != r_n)
	{
		vec1 = v2[r] - v2[r - 1];

		while (l != l_n && v1[l].first <= v2[r].first)
		{
			vec2 = v1[l] - v2[r - 1];
			if ((vec2 ^ vec1) < 0)
				return true;
			l++;
		}
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

	v.resize(n);

	fori(i, n)
	{
		cin >> m;
		m++;
 		fori(j, m)
		{
			cin >> x >> y;
			v[i].push_back(m_p(x, y));
		}
	}

	bool is_ok = true;

	for (int i = 0; i < (int)v.size(); i++)
	{
		for (int j = i + 1; j < (int)v.size(); j++)
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