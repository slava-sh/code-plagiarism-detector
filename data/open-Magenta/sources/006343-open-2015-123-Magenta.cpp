#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#pragma comment(linker, "/STACK:100000000")
using namespace std;

const int MAXINT = 1000000010;
const long long MAXLL = 2e18;
const long long MODUL = 1000000007;

template <typename T>
inline T MIN(T a, T b)
{
	return (a < b ? a : b);
}

template <typename T>
inline T MAX(T a, T b)
{
	return (a > b ? a : b);
}

template <typename T>
inline T MOD(T a)
{
	return (a > 0 ? a : -a);
}

const double TL = 3;

bool tl;
inline void isTL()
{
	static int cou(1000);
	static double lost(0);
	if(!(--cou))
	{
		cou = 1000;
		if (clock() > (TL - 0.3) * CLOCKS_PER_SEC)
			tl = 1;
	}
}
char c('N');

inline bool u()
{
	cout << 'U' << endl;
	cout.flush();
	cin >> c;
	return (c != 'N');
}

inline bool d()
{
	cout << 'D' << endl;
	cout.flush();
	cin >> c;
	return (c != 'N');
}

inline bool r()
{
	cout << 'R' << endl;
	cout.flush();
	cin >> c;
	return (c != 'N');
}

inline bool l()
{
	cout << 'L' << endl;
	cout.flush();
	cin >> c;
	return (c != 'N');
}


int main()
{
	ios_base::sync_with_stdio(0);
	for(int t(0); 1; ++t)
	{
		int k = MIN(1 << t, 1000), n = k * 2;
		for(int j(0); j < k; ++j)
		{
			for(int i(1); i < n; ++i)
				if(u())
					return 0;
			if(r())
				return 0;
			for(int i(1); i < n; ++i)
				if(d())
					return 0;
			if(r())
				return 0;
		}
	}
	return 0;
}














