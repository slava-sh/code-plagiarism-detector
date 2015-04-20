#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200000;
int a[MAXN];

int main()
{
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int sm = 0, cs = 0;
	int lt = 0, rs = a[n - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] <= d) break;
		if (a[i] < 3 * d)
		{
			if (lt == 2) break;
			else lt++;
		}
		sm += a[i];
		rs = max(rs, sm - (n - i - 1) * 2 * d);
	}
	cout << rs << endl;
	return 0;
}