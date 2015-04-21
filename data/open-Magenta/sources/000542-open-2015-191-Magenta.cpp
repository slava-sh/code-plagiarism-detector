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

int main()
{
#ifdef LOCAL
	//file_opener FileOpener("test");
#else
	//file_opener FileOpener("input", "output");
#endif
	cout.setf(cout.fixed);
	cout.precision(10);
//-----------------------------------------------------------

	bool needR = true;
	int tk = 0;
	char ans;
	while (true)
	{
		tk++;
		if (needR)
		{
			cout << "R" << endl;
			needR = false;
		}
		else
		{
			cout << "U" << endl;
			needR = true;
		}
		cout.flush();
		cin >> ans;
		if (ans == 'E' || ans == 'Y')
			return 0;

		if (tk > 500)
		{
			cout << "U" << endl;
			cout.flush();
			cin >> ans;
			if (ans == 'E' || ans == 'Y')
				return 0;
			tk = 0;
		}
	}

//-----------------------------------------------------------
	return 0;
}