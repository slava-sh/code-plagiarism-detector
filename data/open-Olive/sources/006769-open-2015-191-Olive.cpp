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

vector<int> v, tv;
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

	fori(i, n)
	{
		cin >> f;
		v.push_back(f);
	}

	int best_ans = INT_MAX, tl = -1, tr = -1;
	int tans;

	int cl, cr, pl, pr;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[j] > v[i])
				continue;

			cl = cr = pl = pr = 0;
			for (int p = i; p < j; p++)
			{
				if (v[p] < v[j])
					cl++;
				else 
					cr++;
				if (p != i && v[p] < v[i])
					pl++;
				else if (p != i)
					pr++;
			}

			if (-cr + cl - pl + pr < best_ans)
			{
				best_ans = -cr + cl - pl + pr;
				tl = i + 1;
				tr = j + 1;
			}
		}
	}

	cout << tl << ' ' << tr << endl;

//-----------------------------------------------------------
	return 0;
}