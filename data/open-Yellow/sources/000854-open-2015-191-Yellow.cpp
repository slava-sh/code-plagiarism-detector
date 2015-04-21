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

vector<int> v;

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

	int n, f, t, ans = 1, q;
	cin >> n;

	fori(i, n)
	{
		cin >> f;
		if (i != 0)
			if (f != v.back())
				ans++;
		v.push_back(f);
	}

	n--;
	
	cin >> q;
	fori(i, q)
	{
		cin >> t >> f;
		t--;
		if (t == 0)
		{
			if (v[t] == v[t + 1])
				ans++;
			if (f == v[t + 1])
				ans--;
			v[t] = f;
		}
		else if (t == n)
		{
			if (v[t] == v[t - 1])
				ans++;
			if (f == v[t - 1])
				ans--;
			v[t] = f;
		}
		else
		{
			if (v[t] == v[t - 1])
				ans++;
			if (v[t] == v[t + 1])
				ans++;

			if (f == v[t - 1])
				ans--;
			if (f == v[t + 1])
				ans--;
			v[t] = f;
		}
		cout << ans << endl;
	}

//-----------------------------------------------------------
	return 0;
}