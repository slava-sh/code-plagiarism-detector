#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int const Max = 101101;
int n, k;
int a[Max];

bool check(int x)
{
	if (x > a[1])
		return false;
	int p = a[1];
	for (int i = 2; i <= n; i++)
		if (a[i] >= p + x)
			p = a[i];
		else
		{
			p += x;
			if (p > k)
				return false;
		}
	return true;
}

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	scanf(" %d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf(" %d", &a[i]);
	sort(a + 1, a + n + 1);
	int l, r, m;
	l = 0;
	r = k;
	while (true)
	{
		if (l == r)
		{
			printf("%d\n", l);
			return 0;
		}
		m = (l + r) / 2 + 1;
		if (check(m))
			l = m;
		else
			r = m - 1;
	}
}