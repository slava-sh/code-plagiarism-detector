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

bool pow(llg tf, int k, llg n, llg &ans)
{
	ans = 1;
	for (int i = 0; i < k; i++)
	{
		ans *= tf;
		if (ans > n)
			return false;
	}
	return true;
}

llg b_pow(llg tf, int k)
{
	llg ans = 1;
	fori(i, k)
		ans *= tf;
	return ans;
}

int main()
{
#ifdef LOCAL
	file_opener FileOpener("test");
#else
	file_opener FileOpener("input", "output");
#endif

	//ios_base :: sync_with_stdio(false);
	cout.setf(cout.fixed);
	cout.precision(10);
//-----------------------------------------------------------

	llg n, k;

	cin >> n >> k;

	llg tf = 1, f, pf;

	llg ans = LLONG_MAX, tans;

	k--;
	for (;;tf++)
	{
		if (pow(tf, k, n, f))
		{
			if (n % f != 0)
				continue;
			pf = ((tf + 1) / 2);
			tans = b_pow(pf, k);

			tans = tans * ((n / f) + 1) / 2;
			
			ans = min(ans, tans);
		}
		else
			break;
	}
	cout << ans;

//-----------------------------------------------------------
	return 0;
}