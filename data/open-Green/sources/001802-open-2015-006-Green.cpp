#pragma comment(linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>

using namespace std;

map <pair <long long, int>, long long> dp;

long long go(long long x, int k) {
	if (!dp.count(make_pair(x, k))) {
		if (k == 1) {
			dp[make_pair(x, k)] = (x + 1) / 2;
		} else {
			long long ans = (long long)1e18;
			for (long long i = 1; i * i <= x; i++) {
				if (x % i == 0) {
					ans = min(ans, (i + 1) / 2 * go(x / i, k - 1));
					ans = min(ans, (x / i + 1) / 2 * go(i, k - 1));
				}
			}

			dp[make_pair(x, k)] = ans;
		}
	}

	return dp[make_pair(x, k)];
}

int main() {
	long long x;

	cin >> x;

	int k;

	cin >> k;

	cout << go(x, k) << endl;

	return 0;
}
