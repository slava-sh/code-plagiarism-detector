#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int n, m;

int main()
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	cin >> n >> m;
	if (n > m)
		swap(n, m);
	if ((n == 1 && m < 3) || n == 2)
	{
		cout << 0 << endl;
		return 0;
	}
	if (n == 1 && m > 2)
	{
		cout << (m - 3) / 4 + 1 << endl;
		return 0;
	}
	cout << 1 << endl;
	return 0;
}