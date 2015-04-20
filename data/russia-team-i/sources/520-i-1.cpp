#pragma comment(linker, "/STACK:0x04000000")
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector <int> a;
multiset <int> maxi;

int main() {
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t < 3 * d && t > d) {
			maxi.insert(t);
		}
		else if (t >= 3 * d) {
			a.push_back(t);
		}
	}
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ans += a[i] - 2 * d;
	}
	int kol = 0;
	while (kol < 2 && !maxi.empty()) {
		auto it = maxi.end();
		it--;
		int q = *it;
		ans += q - d;
		maxi.erase(q);
		kol++;
	}
	ans += d * (2 - kol);
	cout << ans;
}