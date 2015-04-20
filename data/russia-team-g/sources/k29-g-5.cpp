#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

long long n, m;

int main()
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	cin >> n >> m;
	if (n == 1 && m == 1) cout << 0; else
	if (n == 1 && m == 2)  cout << 0;     else
	if (n == 2 && m == 1) cout << 0;         else
	if (n == 2 && m == 2) cout << 0;	           else
	if (n == 1 && m > 2) cout << (m - 3) / 4 + 1; else
	if (m == 1 && n > 2) cout << (n - 3) / 4 + 1; else
	if (n == 2) cout << 0; else
	if (m == 2) cout << 0; else
	cout << 1;
	return 0;
}