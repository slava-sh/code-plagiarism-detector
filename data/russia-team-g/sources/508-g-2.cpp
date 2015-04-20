#include <iostream>
#include <vector>
#include <algorithm>

#pragma comment(linker, "/STACK:256000000");
using namespace std;

int main()
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	if(n == m && n == 1)
		cout << 0;
	else
		cout << (max(n - 1, m - 1) + 2) / 4;
	/*int dp[1000][1000][6];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 6; k++)
				dp[i][j][k] = 0;

	dp[*/



	return 0;
}