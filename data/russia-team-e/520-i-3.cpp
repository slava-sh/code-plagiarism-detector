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

vector<int> a, b, c;

int main() {
#ifdef NAVI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
#endif
	int n;
	int d;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t >= 3 * d) {
			a.push_back(t);
		} else if (t >= 2 * d) {
			b.push_back(t);
		} else {
			c.push_back(t);
		}
	}
	sort(b.rbegin(), b.rend());
	sort(c.rbegin(), c.rend());
	if (a.size() + b.size() == 0) {
		cout << c[0] << "\n";
		return 0;
	}
	int res = 0;
	int q = a.size();
	for (int i = 0; i < a.size(); i++) {
		res += a[i];
	}
	int i = 0;
	while (i < 2 && i < b.size()) {
		res += b[i];
		i++;
	}
	q += i;
	res -= (q - 1) * 2 * d;
	cout << res << "\n";
}