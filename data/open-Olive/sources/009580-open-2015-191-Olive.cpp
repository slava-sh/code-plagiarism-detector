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

vector<int> v, vl, vr;


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

	int n, f;

	cin >> n;

	int best_ans = INT_MAX, tl = -1, tr = -1, cl, cr;

	fori(i, n)
	{
		cin >> f;
		v.push_back(f);
		vl.push_back(0);
		vr.push_back(0);

		if (i == 0)
			continue;
		
		cl = cr = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (v[j] < f)
				cl++;
			else
				cr++;
			if (f > v[j])
				vr[j]++;
			else
				vl[j]++;

			if (v[j] < f)
				continue;
			if (-cr + cl - vl[j] + vr[j] < best_ans)
			{
				best_ans = -cr + cl - vl[j] + vr[j];
				tl = j + 1;
				tr = i + 1;
			}
		}
	}

	cout << tl << ' ' << tr << endl;

//-----------------------------------------------------------
	return 0;
}