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
	else
		cout << (min(n, m) + 1) / 4;
	/*int dp[1000][1000][6];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 6; k++)
				dp[i][j][k] = 0;
	for (int i = 0; i < 6; i++)
		dp[0][0][i] = 1000000;
	dp[0][0][0] = 0;*/
	 



	return 0;
}