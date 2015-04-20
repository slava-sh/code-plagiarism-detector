#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (m < n)
	{
		int z;
		z = n;
		n = m;
		m = z;
	}
	if (n == 1)
	{
		cout << (m + 1) / 4;
		return 0;
	}
	if (n < 3)
		cout << '0';
	else
		cout << '1';
	return 0;
}