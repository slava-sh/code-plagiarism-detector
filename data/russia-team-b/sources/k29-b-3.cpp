#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

long long n, c, i, j, a[400001], ans, all, l, r, m;

int main()
{
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	cin >> n >> c;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	for (i = 1; i <= n; i++)
	{
		l = 1; r = n;
		ans = 0;
		while (l <= r) {
			m = (l + r) / 2;
			if (a[m] - a[i] > c)
			{
				r = m - 1; ans = n - m + 1;
			}
			else
				l = m + 1;
		}
		all += ans;
	}
	cout << all;
	return 0;
}