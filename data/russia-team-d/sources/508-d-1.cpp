#include <iostream>
#include <vector>
#include <algorithm>

#pragma comment(linker, "/STACK:256000000");
using namespace std;

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	long long n, k;
	cin >> n >> k;
	long long a[1000000];
	long long z = 1000000000000;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		z=  min(z, a[i]);
	}
	sort(a, a + n);
	long long l =  -1, r = z;
	while (l < r)
	{
		long long m = (l + r + 1) / 2;
		long long x = 0;
		for (int i = 0; i < n; i++)
		{
			x += m + (((a[i] - m) - x) > 0? ((a[i] - m) - x): 0);
		}
		if (x > k)
			r = m - 1;
		else
			l = m;
	}
	cout << l;

	return 0;
}