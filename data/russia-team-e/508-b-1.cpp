#include <iostream>
#include <vector>
#include <algorithm>

#pragma comment(linker, "/STACK:256000000");
using namespace std;

int main()
{
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	long long n, r;
	cin >> n >> r;
	long long a[1000000];
	for (int i  =0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	long long ans = 0;

	for (int i = 0; i < n; i++)
	{
		long long x = a[i] + r + 1;
		int l = 0;
		int r = n + 1;
		while (r > l)
		{
			long long m =  (l + r + 1) / 2;
			if (a[m] > x)
				r = m - 1;
			else
				l = m;
		}
		ans += l < n? n - l: 0;

	}
	
	cout << ans;

	return 0;
}