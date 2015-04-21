#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

const long long Inf = 1000000000000000000;

unordered_map<pair<long long, int>, long long> ans(10000000);

long long get_ans(long long n, int k)
{
	if (ans.count(make_pair(n, k)))
		return ans[make_pair(n, k)];
	if (k == 1)
		return n / 2 + n % 2;
	long long curr = Inf;
	for (long long i = 1; i * i <= n; ++i)
		if (n % i == 0)
		{
			long long curr1;
			long long nxt = get_ans(n / i, k - 1);
			long long d1 = i / 2 + (i % 2);
			curr1 = nxt * d1;
			curr = min(curr1, curr);
			nxt = get_ans(i, k - 1);
			d1 = (n / i) / 2 + (n / i) % 2;
			curr1 = nxt * d1;
			curr = min(curr1, curr);
		}
	ans[make_pair(n, k)] = curr;
	return curr;
}

int main()
{
	long long n;
	int k;
	cin >> n >> k;
	cout << get_ans(n, k) << endl;
}