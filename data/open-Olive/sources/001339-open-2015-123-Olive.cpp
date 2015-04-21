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
	int n;
	long long mas[1000001], mi(0), tmp(0), a(-1), b(-1);
	cin >> n;
	++n;
	for(int i(1); i < n; ++i)
		cin >> mas[i], tmp += mas[i] * i;
	mi = tmp;
	for(int i(1); i < n; ++i)
	for(int j(i + 1); j < n; ++j)
	{
		tmp -= mas[i] * i + mas[j] * j;
		tmp += mas[i] * j + mas[j] * i;
		if(mi < tmp)
		{
			a = i;
			b = j;
			mi = tmp;
		}
		tmp -= mas[i] * j + mas[j] * i;
		tmp += mas[i] * i + mas[j] * j;
	}
	cout << a << ' ' << b;
	return 0;
}














