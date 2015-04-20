#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int n, m;

int main()
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);

	cin >> n >> m;

	if (n == 2 || m == 2)
	{
		cout << 0;
		return 0;
	}

	if (n == 1 || m == 1)
	{
		cout << max((n + 1) / 4, (m + 1) / 4);
		return 0;
	}

	cout << 1;
}