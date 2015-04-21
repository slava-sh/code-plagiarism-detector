#include<iostream>
#include<algorithm>
using namespace std;
long long dp[3007][3007];
long long best[3007];
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
	for (int i = 0; i < 3007; i++)
	{
		for (int j = 0; j < 3007; j++)
		{
			dp[i][j] = INF;
		}
	}
	for (int i = 1; i <= 3007; i++)
	{
		best[i] = INF;
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (r[i] - l[i])*c);
		}		
		for (int j = 1; j <= k; j++)
		{
			best[j] += (r[i] - r[i - 1])*c;
		}
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = min(dp[i][j], best[j]);
		}		
		dp[i][1] = min(dp[i][1], dp[i - 1][k] + (r[i] - l[i])*c + d);
		for (int j = 1; j <= k; j++)
		{
			best[j] = min(best[j], dp[i][j]);
		}
	}
	long long ans = INF;
	for (int i = 0; i <= k; i++)
	{
		ans = min(ans, dp[n][i]);
	}
	cout << ans << endl;
}