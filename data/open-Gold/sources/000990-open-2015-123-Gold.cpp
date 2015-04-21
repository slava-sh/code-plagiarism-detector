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
	int n, k;
	long long a[200000], b[200000], ans(0), c, d, st(0), cou(0);
	vector<long long> wwin;
	cin >> n >> k >> c >> d;

	for(int i(0); i < n; ++i)
	{
		cin >> a[i] >> b[i];
		ans += (b[i] - a[i]) * d;
	}

	for(int i(1); i < n; ++i)
		a[i] -= b[i - 1];
	sort(a + 1, a + n);

	wwin.push_back(0);
	for(int i(n - k), j(1); i > 0; --i, ++j)
	{
		wwin.back() += a[i];
		if(j == k)
		{
			wwin.back() *= d;
			wwin.push_back(0);
			j = 0;
		}
	}
	wwin.back() *= d;
	for(int i(0); i < wwin.size(); ++i)
	if(wwin[i] > c)
		++cou;
	else
	{
		for(int j(i); j < wwin.size(); ++j)
			st += wwin[j];
		break;
	}
	ans += st + cou * c;
	cout << ans;
	return 0;
}














