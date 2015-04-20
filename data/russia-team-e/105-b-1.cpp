#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = (int)4e5;
int a[N];

int main()
{
	freopen ("che.in", "r", stdin);
	freopen ("che.out", "w", stdout);

	int n, d;
	scanf("%d%d", &n, &d);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	long long ans = 0;
	int r = 0;
	for (int i = 0; i < n; i++)
	{
		while (r < n && a[r] - a[i] <= d)
			r++;
		if (r != n)
			ans += n - r;
	}
	printf("%lld", ans);
	return 0;
}