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
		n = m;
	if (n < 3)
		cout << '0';
	else
		cout << '1';
	return 0;
}