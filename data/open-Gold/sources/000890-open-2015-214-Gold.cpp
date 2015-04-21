#include<iostream>
#include<algorithm>
using namespace std;
long long dp[1007][1007];
long long l[100007], r[100007];
const long long INF = 1000000000000666666;
int main()
{
	long long n, k, c, d;
	cin >> n >> k >> d >> c;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}
	for (int i = 0; i < 1007; i++)
	{
		for (int j = 0; j < 1007; j++)
		{
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{		
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (r[i] - l[i])*c);
		}
		for (int j = 1; j < i; j++)
		{
			for (int p = 1; p <= k; p++)
			{
				dp[i][p] = min(dp[i][p], dp[j][p] + (r[i] - r[j])*c);
			}
		}
		dp[i][1] = min(dp[i][1], dp[i - 1][k] + (r[i] - l[i])*c + d);
	}
	long long ans = INF;
	for (int i = 0; i <= k; i++)
	{
		ans = min(ans, dp[n][i]);
	}
	cout << ans << endl;
}