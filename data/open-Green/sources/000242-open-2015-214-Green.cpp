#include<iostream>
#include<algorithm>
using namespace std;
int dp[1007][11];
bool solved[1007][11];
int solve(int n, int k)
{
	if (solved[n][k])
	{
		return dp[n][k];
	}
	solved[n][k] = true;
	if (k == 1)
	{
		dp[n][k] = (n + 1) / 2;
		return dp[n][k];
	}
	dp[n][k] = n + 1;
	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0)
		{
			dp[n][k] = min(dp[n][k], solve(n / i, k - 1)*((i + 1) / 2));
		}
	}
	return dp[n][k];
}
int main()
{	
	int n, k;
	cin >> n >> k;
	cout << solve(n, k) << endl;
}