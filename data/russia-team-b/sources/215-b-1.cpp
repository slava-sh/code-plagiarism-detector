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

#define FILENAME "che"
int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	int n, r;
	cin >> n >> r;
	vector< int > d(n);
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		auto it = lower_bound(d.begin() + i, d.end(), d[i] + r + 1);
		ans += d.end() - it;
	}
	cout << ans << "\n";
	return 0;
}