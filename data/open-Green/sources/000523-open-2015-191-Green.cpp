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

llg solve(llg n, int k)
{
	llg ans = (n + 1) / 2;
	
	if (k == 0)
	{
		return ans;
	}

	llg pf = 2, tans;

	llg kn = n;

	for(;;pf++)
	{
		if (pf * pf > kn)
			break;

		if (kn % pf != 0)
			continue;
		
		ans = min(ans, ((pf + 1) / 2) * solve(kn / pf, k - 1));
		ans = min(ans, (((kn / pf) + 1) / 2) * solve(pf, k - 1));
	}
	return ans;
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

	llg n;
	int k;

	cin >> n >> k;

	if (k == 1)
	{
		cout << (n + 1) / 2 << endl;
		return 0;
	}
	llg tf = 1, f, pf;

	ullg ans = LLONG_MAX, tans, dt;

	k--;
	
	ans = solve(n, k);

	cout << ans << endl;

//-----------------------------------------------------------
	return 0;
}