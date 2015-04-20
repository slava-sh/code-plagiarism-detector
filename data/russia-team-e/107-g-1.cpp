#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n > m) swap(n, m);
	if (n == 1)
	{
		cout << (m + 1) / 4 << endl;
	}
	else if (n == 2)
	{
		cout << 0 << endl;
	}
	else cout << 1 << endl;
	return 0;
}