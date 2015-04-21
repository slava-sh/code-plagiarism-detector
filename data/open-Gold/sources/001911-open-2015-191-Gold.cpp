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

map<int, llg> dp[2];

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
			v.push_back(a - old_b);
		}
		old_b = b;
	}

	int cur = 1, old = 0;

	dp[old][k] = 0;

	fori(i, v.size())
	{
		forit(it, dp[old])
		{
			if (it->first != 0)
			{
				if (dp[cur].find(it->first - 1) != dp[cur].end())
					dp[cur][it->first - 1] = min(dp[cur][it->first - 1], it->second + v[i] * d);
				else
					dp[cur][it->first - 1] = it->second + v[i] * d;
			}
			else
			{
				if (dp[cur].find(k) != dp[cur].end())
					dp[cur][k] = min(dp[cur][k], it->second + c);
				else
					dp[cur][k] = it->second + c;
			}
		}
		dp[old].clear();
		swap(old, cur);
	}

	llg tans = LLONG_MAX;
	forit(it, dp[old])
		tans = min(tans, it->second);

	cout << ans + tans;

//-----------------------------------------------------------
	return 0;
}