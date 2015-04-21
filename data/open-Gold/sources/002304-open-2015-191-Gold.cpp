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

vector<llg> v;

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

	int n, k;
	llg c, d, ans = 0;
	
	cin >> n >> k >> c >> d;

	llg a, b, old_b;


	fori(i, n)
	{
		cin >> a >> b;
		ans += (b - a) * d;
		if (i != 0)
		{
			ans += (a - old_b) * d;
			v.push_back(a - old_b);
		}
		old_b = b;
	}

	sort(v.rbegin(), v.rend());

	llg t_time = 0;

	llg best_ans = ans;

	int tk = k;
	for (int i = 0; i < (int)v.size(); i++)
	{
		ans -= v[i] * d;
		tk--;
		if (tk == 0)
		{
			tk = k;
			ans += c;
		}
		best_ans = min(ans, best_ans);
	}
	cout << best_ans << endl;
	
//-----------------------------------------------------------
	return 0;
}