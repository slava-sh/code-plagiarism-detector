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
	if (n == 1 || m == 1)
	{
        cout << ((n + m - 1) + 1) / 4;
        return 0;
	}
	if (n >= 3 && m >= 3)
        cout << 1;
    else
        cout << 0;
    return 0;
}
