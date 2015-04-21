#include<iostream>
#include<algorithm>
using namespace std;
long long dp[200007];
//int best[1007];
long long l[200007], r[200007];
const long long INF = 1000000000000666666;
long long needAdd = 0;
int main()
{
	long long n, k, c, d;
	cin >> n >> k >> d >> c;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
		needAdd += (r[i] - l[i])*c;
	}
	for (int i = 1; i < n; i++)
	{
		l[i] = r[i];
		r[i] = l[i + 1];
	}	
	for (int i = 1; i <= n; i++)
	{
		dp[i] = INF;
	}
	for (int i = 1; i < n; i++)
	{
		dp[i] = dp[i - 1] + (r[i] - l[i])*c;
		if (i - k >= 0)
		{
			dp[i] = min(dp[i], dp[i - k] + d);
		}
		else
		{
			dp[i] = 0;
		}
	}
	cout << needAdd + dp[n - 1] << endl;
}