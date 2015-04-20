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
	else if (min(n, m) == 1)
		cout << (max(n, m) + 1) / 4;
	else if (min(n, m) == 2)
		cout << 0;
	else
		cout << 1;
/*	int dp[1000][1000][6];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 6; k++)
				dp[i][j][k] = 0;
	for (int i = 0; i < 6; i++)
		dp[0][0][i] = 1000000;
	dp[0][0][0] = 0;
	for (int i = 1; i < n; i++)
	{
		dp[i][0][0] = dp[i - 1][0][2];
		dp[i][0][1] = dp[i - 1][0][2];
		dp[i][0][2] = dp[i - 1][0][5];
		dp[i][0][3] = dp[i - 1][0][0];
		dp[i][0][4] = dp[i - 1][0][2];
		dp[i][0][5] = dp[i - 1][0][2] + 1;
	}
	for (int i = 1; i < m; i++)
	{
		dp[i][0][0] = dp[0][i - 1][4];
		dp[i][0][1] = dp[0][i - 1][0];
		dp[i][0][2] = dp[0][i - 1][4];
		dp[i][0][3] = dp[0][i - 1][4];
		dp[i][0][4] = dp[0][i - 1][5];
		dp[i][0][5] = dp[0][i - 1][1]; + 1;
	}
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
		{
			dp[i][j][0] = min(dp[i - 1][j][2], dp[i][j - 1][4]);
			dp[i][j][0] = min(dp[i - 1][j][2], dp[i][j - 1][0]);
			dp[i][j][0] = min(dp[i - 1][j][5], dp[i][j - 1][4]);
			dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][4]);
			dp[i][j][0] = min(dp[i - 1][j][2], dp[i][j - 1][4]);
			dp[i][j][0] = min(dp[i - 1][j][2], dp[i][j - 1][4]);
		}*/
	 



	return 0;
}