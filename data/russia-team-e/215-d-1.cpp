#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef long long lint;

lint n, k;
vector< lint > a(n);

bool solve(lint x) {
	lint last = 0;
	for (int i = 0; i < n; ++i) {
		last = max(last + x, a[i]);
	}
	return last <= k;
}

#define FILENAME "fence"
int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	cin >> n >> k;
	a.resize(n);
	lint left = 0;
	lint right = k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		right = min(right, a[i]);
	}
	++right;
	sort(a.begin(), a.end());
	while (left + 1 != right) {
		lint middle = (left + right) / 2;
		if (solve(middle)) {
			left = middle;
		}
		else {
			right = middle;
		}
	}
	lint ans = left;
	cout << ans << "\n";
	return 0;
}