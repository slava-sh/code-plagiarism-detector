#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;

int main()
{	
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);

	cin >> n >> m;


	if (n <= 2 && m <= 2)
		cout << 0;
	else
	if (n == 2 || m == 2)
		cout << 0;
	else
	if (n == 1 || m == 1)
		cout << (max(n, m) - 3) / 4 + 1;
	else
		cout << 1;


	return 0;
}