#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

long long n, k, i, l, r, m, ans, c = 1000*1000*1000, R;
long long a[100001];

bool check(long long len)
{
	R = c;
	for (i = 2; i <= n; i++)
		if (a[i] - R >= len)
			R = a[i];
		else R = R + len;
	if (R <= k)
		return true;
	else return false;
}

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	cin >> n >> k;
	for (i = 1; i <= n; i++){
		cin >> a[i];
		c = min(a[i], c);
	}
	sort (a + 1, a + n + 1);
	l = 0, r = c;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (check(m))
			l = m + 1, ans = m;
		else r = m - 1; 
	}
	cout<< ans;
	return 0;
}