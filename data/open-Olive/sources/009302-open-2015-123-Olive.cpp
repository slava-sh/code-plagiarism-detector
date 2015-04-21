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
int n, mas[1000000], a(-2), b(-2), a1[1000000], b1[1000000];
long long mi(MAXLL), seg[4200000], st = 0;

void put(int l, int r, int ind, int& v)
{
	++seg[ind];
	if(l == r)
		return;
	if(v > (l + r) / 2)
		put((l + r) / 2 + 1, r, ind * 2 + 1, v);
	else
		put(l, (l + r) / 2, ind * 2, v);
}

long long get(int l, int r, int ind, int v)
{
	if(l >= v)
		return seg[ind];
	if(r < v)
		return 0;
	return get(l, (l + r) / 2, ind * 2, v) + get((l + r) / 2 + 1, r, ind * 2 + 1, v);
}

long long cou2(int a, int b)
{
	long long res(0);
	swap(mas[a], mas[b]);
	for(int i(0); i < n; ++i)
	{
		if(mas[i] != n)
			res += a1[i] = get(1, n, 1, mas[i] + 1);
		b1[i] = mas[i] - 1 - i + a1[i];
		//b1[i] -= i;
		//a1[i] -= n - 1 - i;
		put(1, n, 1, mas[i]);
	}
	swap(mas[a], mas[b]);
	res -= st * n * (n - 1) / 2;
	++st;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	for(int i(0); i < 4200000; ++i)
		seg[i] = 0;
	cin >> n;
	for(int i(0); i < n; ++i)
		cin >> mas[i];
	mi = cou2(0, 0);
	if(mi == 0)
	{
		cout << "-1 -1";
		return 0;
	}
	long long s = 0;
	for(int i(0); i < n; ++i)
		s += a1[i];
	for(int j(0); j < n; ++j)
		s += b1[j];
	int x(0), y(n - 1);
	for(int i(1); i < n; ++i)
		if(b1[i] > b1[x])
			x = i;
	for(int i(n - 2); i >= 0; --i)
		if(a1[i] > a1[y])
			y = i;
	if(x < y)
		cout << x + 1 << ' ' << y + 1;
	else
		cout << "-1 -1";
	/*cout << '\n';

	for(int i(0); i < n; ++i)
	for(int j(i + 1); j < n; ++j)
	{
		long long t = cou2(i, j);
		if(t < mi)
		{
			a = i;
			b = j;
			mi = t;
		}
	}
	cout << a + 1 << ' ' << b + 1;*/
	return 0;
}
/*20
1 5 7 3 10 14 12 20 17 18 19 11 15 16 2 4 6 9 8 13*/













