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
int n, mas[1000000], a(-2), b(-2);
long long mi(MAXLL);

long long cou1(int a, int b)
{
	long long cou(0);
	int m1[1000000];
	for(int i(0); i < n; ++i)
		m1[i] = mas[i];
	swap(m1[a], m1[b]);
	for(int i(0); i < n; ++i)
	for(int j(1); j < n; ++j)
	if(m1[j] < m1[j - 1])
	{
		swap(m1[j], m1[j - 1]);
		++cou;
	}
	return cou;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i(0); i < n; ++i)
		cin >> mas[i];
	mi = cou1(0, 0);
	for(int i(0); i < n; ++i)
	for(int j(i + 1); j < n; ++j)
	{
		long long t = cou1(i, j);
		if(t < mi)
		{
			a = i;
			b = j;
			mi = t;
		}
	}
	cout << a + 1 << ' ' << b + 1;
	return 0;
}














