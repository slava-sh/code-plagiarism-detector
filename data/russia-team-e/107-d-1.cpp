#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100001;
long long a[MAXN];

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	int n;
	long long k;
	cin >> n >> k;
	long long rs = k / (long long)n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		rs = min(rs, a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++)
	{
		rs = min(rs, rs + (k - a[i]) / (long long)(n - i - 1));
	}
	cout << rs << endl;
	return 0;
}