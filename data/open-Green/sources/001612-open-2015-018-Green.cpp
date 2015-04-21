#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

long long n;
vector<long long> posl;
map<pair<long long, int>, long long> tmp;
vector<long long> del;

long long dp(long long c, int level) {
	if (level == 1) return (c + 1) / 2;
	long long mn = (c + 1) / 2;
	for (long long i = 0; i < (long long) del.size() && del[i] <= c; ++i) {
		if (c % del[i] != 0) continue;
		if (tmp.count(make_pair(c / del[i], level - 1)) == 0) {
			tmp[make_pair(c / del[i], level - 1)] = dp(c / del[i], level - 1);
		}
		mn = min(mn, (long long)((del[i] + 1) / 2) * tmp[make_pair(c / del[i], level - 1)]);
	}
	return mn;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	long long n;
	int k;
	cin >> n >> k;
	for (int i = 1; i < sqrt((long double)n) + 1; ++i) {
		if (n % i == 0) {
			del.push_back(i);
		}
	}
	del.push_back(n);
	cout << dp(n, k) << endl;

	return 0;
}