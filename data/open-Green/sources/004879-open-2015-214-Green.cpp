#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;
namespace std
{
	template<>
	struct hash<pair<long long, int>>
	{
		typedef pair<long long, int> argument_type;
		typedef std::size_t result_type;

		result_type operator()(argument_type const& s) const
		{
			result_type const h1(std::hash<long long>()(s.first));
			result_type const h2(std::hash<int>()(s.second));
			return h1 ^ (h2 << 1);
		}
	};
}
unordered_map<pair<long long, int>, long long> dp,dp2;
long long easy_solve(long long n, int k)
{
	pair<long long, int>cur = make_pair(n, k);
	if (dp.count(cur) != 0)
	{
		return dp[cur];
	}
	long long ans = n + 1;
	if (k == 1)
	{
		long long ans = (n + 1)>>1;
		dp[cur] = ans;
		return ans;
	}	
	for (long long i = 1; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			long long j = n / i;
			ans = min(ans, easy_solve(j, k - 1)*((i + 1)>>1));
			ans = min(ans, easy_solve(i, k - 1)*((j + 1)>>1));
		}
	}
	dp[cur] = ans;
	return ans;
}
long long epic_solve(long long n, int k)
{
	pair<long long, int>cur = make_pair(n, k);
	if (dp2.count(cur) != 0)
	{
		return dp2[cur];
	}
	long long ans = n + 1;
	if (k == 1)
	{
		long long ans = (n + 1) >> 1;
		dp2[cur] = ans;
		return ans;
	}
	vector<long long>totry;
	for (long long i = 1; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			totry.push_back(i);
			totry.push_back(n / i);
		}
	}
	sort(totry.begin(), totry.end());
	int m = totry.size() / 2;
	for (int i = m; i <= min(m + 47, (int)(totry.size() - 1)); i++)
	{
		ans = min(ans, epic_solve(totry[i], k - 1)*((n/totry[i] + 1) >> 1));
	}
	for (int i = m; i >= max(m - 47, 0); i--)
	{
		ans = min(ans, epic_solve(totry[i], k - 1)*((n/totry[i] + 1) >> 1));
	}
	dp2[cur] = ans;
	return ans;
}
int main()
{
	long long n;
	int k;
	cin >> n >> k;
	if (n <= 10000000000000LL)
	{
		cout << easy_solve(n, k) << endl;
	}
	else
	{
		cout << epic_solve(n, k) << endl;
	}
	cin >> n;
}