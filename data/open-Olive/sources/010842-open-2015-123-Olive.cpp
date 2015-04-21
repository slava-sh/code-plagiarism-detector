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
int n, mas[5000], a(-2), b(-2);
long long mi(MAXLL), seg[42000], st = 0, dp[5001][5001];

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
			res += get(1, n, 1, mas[i] + 1);
		for(int j(1); j < n; ++j)
			dp[i][j] = get(1, n, 1, j + 1);
		put(1, n, 1, mas[i]);
	}
	swap(mas[a], mas[b]);
	res -= st * n * (n - 1) / 2;
	++st;
	return res;
}

int main()
{
	long long t;
	ios_base::sync_with_stdio(0);
	for(int i(0); i < 42000; ++i)
		seg[i] = 0;
	cin >> n;
	for(int i(0); i < n; ++i)
		cin >> mas[i];
	t = mi = cou2(0, 0);
	if(mi == 0)
	{
		cout << "-1 -1";
		return 0;
	}
	for(int i(0); i < n; ++i)
	for(int j(i + 1); j < n; ++j)
	{
		t -= dp[i][mas[i]] + dp[j][mas[j]];
		t -= dp[i][mas[i]];
		t -= dp[j][mas[j]];
		t += dp[j][mas[i]] + dp[i][mas[j]];
		t += dp[j][mas[i]];
		t += dp[i][mas[j]];
		if(t < mi)
		{
			a = i;
			b = j;
			mi = t;
		}
		t += dp[i][mas[i]] + dp[j][mas[j]];
		t +=   dp[i][mas[i]];
		t +=  dp[j][mas[j]];
		t -= dp[j][mas[i]] + dp[i][mas[j]];
		t -=   dp[j][mas[i]];
		t -=   dp[i][mas[j]];
	}
	cout << a + 1 << ' ' << b + 1;
	return 0;
}
/*20
1 5 7 3 10 14 12 20 17 18 19 11 15 16 2 4 6 9 8 13*/













