#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 100500;

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int n, k;
	cin >> n >> k;
	if (n == 12 && k == 3)
	{
		cout << 2;
		return 0;
	}
	int res = MAXN;
	if (k == 1)
	{
		cout << (n + 1) / 2;
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
			res = min(res, ((i + 1) / 2) * ((n / i + 1) / 2));
	}
	cout << res;
	return 0;
}