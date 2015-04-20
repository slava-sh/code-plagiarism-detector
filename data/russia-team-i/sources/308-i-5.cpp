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
long long n, d, a[150000], kol, ans , ans1;
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
	ans = a[n-1];
	if (a[n-1] <= d)
	{
		cout << a[n-1];
		return 0;
	}
	for (int i = n-1; i > 0; i--)
	{
		ans1 = ans;
		ans += a[i-1] - 2*d;
		if (ans < ans1)
		{
			cout << ans1;
			return 0;
		}
		if (a[i-1] < 3*d)
			break;
	}
	cout << ans;
	return 0;
}