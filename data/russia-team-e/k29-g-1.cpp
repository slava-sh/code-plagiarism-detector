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
	cout << min(m, n) / 3;
	return 0;
}