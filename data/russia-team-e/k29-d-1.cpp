#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

long long n, k, a[100001], i, mn = 1000*1000*1000, col =1 , d, m, c = 1000*1000*1000;

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	cin >> n >> k;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		c = min(c, a[i]);
	}
	sort (a + 1, a + n + 1);
	for (i = 2; i <= n; i++)
		if (mn >= a[i] - a[i - 1]){
			if (mn == a[i] - a[i - 1])
				col++;
			else col = 1;
			mn = (mn, a[i] - a[i - 1]);
		}
	m = k - a[n];
	mn++; m -= col; col = n - 1;
	mn += (m / col); m %= col;
	cout << min(mn, c);

	return 0;
}