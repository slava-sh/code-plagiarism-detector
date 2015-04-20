#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int n, r, a[310000], p;
long long ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	cin >>n >>r;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	p = 1;

	for (int i = 1; i <= n; i++)
	{
		while (p <= n && a[i] + r >= a[p]) p++;
		if (p > n)
			break;
		ans += n - p + 1;
	}
	cout << ans;
}