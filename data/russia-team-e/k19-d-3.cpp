#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int n, k, a[1000001], mx = 1000000001;

bool check(int x)
{
	long long p = a[1], pos = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (a[i] - (p - pos) < x)
			pos += x - a[i] + (p - pos);
		p = a[i] + pos;
	}

	return p <= k;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);

	scanf("%d%d", &n, &k);

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		mx = min(mx, a[i]);
	}

	sort(a + 1, a + n + 1);

	int l = 0, r = mx + 1;

	while (r - l > 1)
	{
		int m = (l + r) >> 1;

		if (check(m))
			l = m;
		else
			r = m;				
	}

	cout << l;
}