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

vector <pair <long long, int> > now;

long long go(long long x, int k);

long long gen(int pos, long long f, long long x, int k) {
	if (pos == (int)now.size()) {
		return (f / x + 1) / 2 * go(x, k);
	} else {
		long long ans = (long long)1e18;
		int cnt = now[pos].second;
		long long mul = 1;

		for (int i = 0; i <= cnt; i++) {
			now[pos].second = i;
			ans = min(ans, gen(pos + 1, f, x * mul, k));
			mul *= now[pos].first;
		}

		return ans;
	}
}

long long go(long long x, int k) {
	if (!dp.count(make_pair(x, k))) {
		if (k == 1) {
			dp[make_pair(x, k)] = (x + 1) / 2;
		} else {
			long long ans = gen(0, x, 1, k - 1);
			dp[make_pair(x, k)] = ans;
		}
	}

	return dp[make_pair(x, k)];
}

void gen_now(long long x) {
	for (long long i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			int cnt = 0;
			while (x % i == 0) {
				x /= i;
				cnt++;
			}
			now.push_back(make_pair(i, cnt));
		}
	}

	if (x != 1) {
		now.push_back(make_pair(x, 1));
	}
}

int main() {
	long long x;

	cin >> x;

	gen_now(x);

	int k;

	cin >> k;

	cout << go(x, k) << endl;

	return 0;
}
