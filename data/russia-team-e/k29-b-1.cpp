#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int n, r, i, j, a[300001], ans;

int main()
{
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	cin >> n >> r;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (a[i] - a[j] > r)
				ans++;
	cout << ans;
	return 0;
}