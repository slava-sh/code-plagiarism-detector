#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
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
unordered_map<pair<long long, int>, long long> dp;
long long solve(long long n, int k)
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
			ans = min(ans, solve(j, k - 1)*((i + 1)>>1));
			ans = min(ans, solve(i, k - 1)*((j + 1)>>1));
		}
	}
	dp[cur] = ans;
	return ans;
}
int main()
{
	long long n;
	int k;
	cin >> n >> k;
	cout << solve(n, k) << endl;
}