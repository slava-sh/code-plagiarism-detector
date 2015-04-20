#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int N = (int)1e5 + 100;
int a[N];

bool check(int t, int n, int k)
{
	if (a[0] < t)
		return false;
	int r = a[0];
	for (int i = 1; i < n; i++)
	{
		if (r + t >= a[i])
			r += t;
		else
			r += (a[i] - r);
	}
	return (r <= k);
}

int main()
{
	freopen ("fence.in", "r", stdin);
	freopen ("fence.out", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);

	int l = 0, r = k + 1;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (check(m, n, k))
			l = m;
		else
			r = m;
	}
	printf("%d", l);

	return 0;
}