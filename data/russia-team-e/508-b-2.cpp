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
	//sort(a, a + n);
	long long ans = 0;
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		while (x < n && a[x] <= a[i] + r)
			x++;
		if (x < n) ans += n - x;

	}
	
	cout << ans;

	return 0;
}