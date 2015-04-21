//#include "stdafx.h"
//#pragma comment(linker, "/STACK:67108864")
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <string>
#include <memory.h>

using namespace std;

long long n, k;

long long dfs(long long pos, long long people)
{
	if (pos == k)
		return people / 2ll + (people % 2ll > 0ll);

	if (people == 1)
		return 1ll;

	long long min_div = people;
	long long ans = 1e9;

	for (long long x = 2; x * x <= people; ++x)
	{
		if (people % x == 0)
		{
			min_div = x;
			long long num_to_win = min_div / 2ll + (min_div % 2ll > 0ll);
			ans = min(ans, num_to_win * dfs(pos + 1, people / min_div));
		}
	}

	long long num_to_win = min_div / 2ll + (min_div % 2ll > 0ll);
	ans = min(ans, num_to_win * dfs(pos + 1, people / min_div));

	return ans;
}

int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	cin >> n >> k;
	cout << dfs(1, n);

	return 0;
}