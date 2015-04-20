#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

long long n, d, i, sum, a[100001], l, r, ans;

int main()
{
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	cin >> n >> d;
	for (i =1 ; i <= n; i++)
	{
		cin >> a[i];
		ans = max(ans, a[i]);
	}
	sort (a + 1, a + n + 1);
	if (a[n] - d > 0 && a[n - 1] - d > 0)
	l = a[n] - d, r = a[n - 1] - d,	sum = l + r;
	for (i = n - 2; i >= 1; i--)
	{
		if (l > r && l - d >= d && a[i] > d)
			l = (a[i] - d), sum = sum - d + l;
			else
		if (r >= l && r - d >= d && a[i] > d)
			r = (a[i] - d), sum = sum - d + r;
	}
	cout << max(ans, sum);

	return 0;
}
