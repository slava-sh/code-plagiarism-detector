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

int main()
{
	ios_base::sync_with_stdio(0);
	char c('N');
	for(int i(0); c == 'N'; ++i)
	{
		if(i & 1)
		{
			for(int j(0); j < i && c == 'N'; ++j)
			{
				cout << 'R';
				cout.flush();
				cin >> c;
			}
			for(int j(0); j < i && c == 'N'; ++j)
			{
				cout << 'D';
				cout.flush();
				cin >> c;
			}
			if(c == 'N')
			{
				cout << 'R';
				cout.flush();
				cin >> c;
			}
		}
		else
		{
			for(int j(0); j < i && c == 'N'; ++j)
			{
				cout << 'U';
				cout.flush();
				cin >> c;
			}
			for(int j(0); j < i && c == 'N'; ++j)
			{
				cout << 'L';
				cout.flush();
				cin >> c;
			}
			if(c == 'N')
			{
				cout << 'U';
				cout.flush();
				cin >> c;
			}
		}
	}
	return 0;
}














