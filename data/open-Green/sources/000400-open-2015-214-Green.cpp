#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<pair<long long, int>, long long> dp;
long long solve(long long n, int k)
{
	pair<long long, int>cur = make_pair(n, k);
	if (dp.count(cur)!=0)
	{
		return dp[cur];
	}	
	if (k == 1)
	{
		dp[cur] = (n + 1) / 2;
		return dp[cur];
	}	
	dp[cur] = n + 1;
	for (long long i = 1; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{			
			dp[cur] = min(dp[cur], solve(n / i, k - 1)*((i + 1) / 2));
			long long j = n / i;
			dp[cur] = min(dp[cur], solve(n / j, k - 1)*((j + 1) / 2));
		}
	}
	return dp[cur];
}
int main()
{
	long long n;
	int k;
	cin >> n >> k;
	cout << solve(n, k) << endl;
}