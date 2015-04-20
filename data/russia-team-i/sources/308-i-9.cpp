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
long long n, d, a[150000], ans , ans1, fl, k;
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
	if (n == 2)
	{
		cout << max(a[n-1], a[n-1]+a[0]-2*d);
		return 0;
	}
	for (int i = 2; i < n; i++)
	{
		if (a[i] >= 3*d)
		{
			if (a[i-2] >= 2*d)
			{
				ans += a[i-2] - d;
				ans += a[i-1] - d;
				k = i-1;break;
			}
			else if (a[i-1] >= 2*d)
			{
				ans += a[i-1] - d;
				ans += a[i] - d;
				k = i;break;
			}
			else
			{
				ans += a[i] - d;
				if (i < n-1)
					ans += a[i+1] - d;
				break;
			}
		}
	}
	for (int i = k+1; i < n; i++)
	{
		if (a[i] >= 3*d)
			ans += a[i] - 2*d;
	}
	if (ans < a[n-1])
		ans = a[n-1];
	cout << ans;
	return 0;
}