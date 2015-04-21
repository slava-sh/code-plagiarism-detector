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

struct point
{
	long long x, y;
};

struct ot
{
	long long a, b, c, x1, x2;
	ot(point& p1, point& p2)
	{
		x1 = p1.x;
		x2 = p2.x;
		a = p1.y - p2.y;
		b = p2.x - p1.x;
		c = p1.x * p2.y - p2.x * p1.y;
	}

	bool inter(ot& an)
	{
		if(a * an.b == an.a * b)
			return 0;
		double x, y;
		y = (an.c * a - an.a * c * 1.0) / (b * an.a - a * an.b);
		x = (-b * y - c) / a;
		if(x > x1 && x < x2)
			return 1;
		return 0;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	int n, l;
	ot *o1, *o2;
	long long a, b;
	vector<point> mas[100000];
	cin >> a >> b >> n;
	for(int i(0); i < n; ++i)
	{
		cin >> l;
		++l;
		mas[i].resize(l);
		for(int j(0); j < l; ++j)
			cin >> mas[i][j].x >> mas[i][j].y;
	}
	for(int i(0); i < n; ++i)
	for(int s(i + 1); s < n; ++s)
	for(int j(1), l = mas[i].size(); j < l; ++j)
	for(int k(1), l1 = mas[s].size(); k < l1; ++k)
	{
		o1 = new ot(mas[i][j - 1], mas[i][j]);
		o2 = new ot(mas[s][k - 1], mas[s][k]);
		if(o1->inter(*o2))
		{
			cout << "No\n";
			cout << i + 1 << ' ' << s + 1;
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}














