#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

const long long Inf = 1000000000000000000;

map<pair<long long, int>, long long> ans;

long long get_ans(long long n, int k)
{
	if (ans.count(make_pair(n, k)))
		return ans[make_pair(n, k)];
	if (k == 1)
		return n / 2 + n % 2;
	long long curr = Inf;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
		{
			long long curr1;
			long long nxt = get_ans(n / i, k - 1);
			long long d1 = i / 2 + (i % 2);
			ans[make_pair(n, k)] = nxt * d1;
			return nxt * d1;
		}
}

int main()
{
	long long n;
	int k;
	cin >> n >> k;
	cout << get_ans(n, k) << endl;
}