#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#define eps 1e-9
#define INF 1e+9
#define txt "sochi"

using namespace std;
int n, d, a[150000], ans , ans1, fl, k;
int main()
{
	freopen(txt".in", "r", stdin);
	freopen(txt".out", "w", stdout);
	cin >> n >> d;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (n == 1)
	{
		cout << a[0];
		return 0;
	}
	sort(a, a+n);
	if (a[n-1] <= d)
	{
		cout << a[n-1];
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (fl == 2)
			break;
		if (a[i] >= 2*d)
		{
			fl++;
			ans += a[i] - d;
			k = i;
		}
	}
	for (int i = k+1; i < n; i++)
		ans += a[i] - 2*d;
	if (ans < a[n-1])
		ans = a[n-1];
	cout << ans;
	return 0;
}