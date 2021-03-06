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

bool go(int i)
{
	if(i & 1)
	{
		for(int j(1); j < i; ++j)
			if(r())
				return 0;
		if(d())
			return 0;
		for(int j(0); j < i; ++j)
			if(l())
				return 0;
	}
	else
	{
		for(int j(1); j < i; ++j)
			if(u())
				return 0;
		if(l())
			return 0;
		for(int j(0); j < i; ++j)
			if(d())
				return 0;
	}
	return 1;
}


int main()
{
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	int i(2);
	for(; i <= 3; ++i)
		if(!go(i))
			return 0;
	if(!go(10))
		return 0;
	if(!go(11))
		return 0;
	for(; i <= 5; ++i)
		if(!go(i))
			return 0;
	if(!go(30))
		return 0;
	if(!go(31))
		return 0;
	for(int j(10); j <= 24; j += 7)
	{
		for(; i <= j; ++i)
			if(!go(i))
				return 0;
		for(int k(1); k <= 5; ++k)
		{
			if(!go(j * j / k))
				return 0;
			if(!go(j * j / k + 1))
				return 0;
		}
	}
	for(int j(35); j <= 80; j += 15)
	{
		for(; i <= j; ++i)
			if(!go(i))
				return 0;
		for(int k(1); k <= 10; ++k)
		{
			if(!go(j * j / k))
				return 0;
			if(!go(j * j / k + 1))
				return 0;
		}
	}
	for(int k(2); k < 15; ++k)
		if(!go(80 * k))
			return 0;
	for(; 1;)
	{
		if(!go(80))
			return 0;
	}
	return 0;
}














