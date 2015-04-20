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
int n, d, a[150000], kol = 0, ans = 0;
int main()
{
	freopen(txt".in", "r", stdin);
	freopen(txt".out", "w", stdout);
	cin >> n >> d;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a+n);
	if (a[n-1] <= d)
	{
		cout << a[n-1];
		return 0;
	}
	for(int i = n-1; i >= 0; i--)
	{
		if(kol == 0)
		{
			if(a[i] - d > 0)
			{
				ans += a[i] - d;
				kol++;
			}
		}
		else
		{
			if(i != 0)
			{
				if(a[i] - d*2 > 0 && a[i-1] - d > 0)
				{
					ans += a[i] - d*2;
					kol++;
				}
				else
				{
					ans += a[i] - d;
					break;
				}
			}
			else
			{
				if(a[i] - d > 0)
					ans += a[i]-d;
			}
		}
	}
	if (a[n-1] > ans)
		ans = a[n-1];
	cout << ans;
	return 0;
}