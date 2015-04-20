#include <iostream>
#include <vector>
#include <algorithm>

#pragma comment(linker, "/STACK:256000000");
using namespace std;

int main()
{
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	long long n, d, x = 0, y  = 0;
	cin >> n >> d;
	long long a[1000000], b[1000000];

	for (int i  = 0; i < n; i++)
	{
		long long t;
		cin >> t;
		if (t >= 3 * d)
			a[x++] = t;
		else if (t >= d)
			b[y++] = t;
	}
	sort(b, b + y);
	long long ans = 0;
	for (int i = 0; i < x; i++)
		ans += a[i] - 2 * d;
	if (y >= 2)
		ans += b[y - 1] + b[y - 2] - 2 * d;
	else if (y == 1)
		ans += b[y - 1];
	else if (x != 0)
		ans += 2 * d;
	cout << ans;




	return 0;
}