#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100001;
long long a[MAXN];

int n;
long long k;

bool check(int x)
{
	long long t = 0;
	for (int i = 0; i < n; i++)
	{
		if ((n - i) * x > k - t) return false;
		t = max(t + x, a[i]);
	}
}

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	long long l = 0, r = a[0] + 1;
	while (r - l > 1)
	{
		int x = (r + l) / 2;
		if (check(x))
			l = x;
		else
			r = x;
	}
	cout << l << endl;
 	return 0;
}