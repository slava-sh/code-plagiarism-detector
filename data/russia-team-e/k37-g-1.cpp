#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	cout << min((n + 1) / 4, (m + 1) / 4);
		return 0;
}
