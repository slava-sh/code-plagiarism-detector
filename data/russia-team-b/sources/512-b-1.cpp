#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

int n, ra, p, ans;
vector <int> a;

int bina (int k) {
	int l = 0, r = n + 1, m;
	while (l + 1 < r) {
		m = (l + r) / 2;
		if (a[m] >= k) {
			r = m;
		} else {
			l = m;
		}
	}
	return r;
}

int main () {
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	freopen("che.in", "r", stdin);freopen("che.out", "w", stdout);
	cin >> n >> ra;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		p = bina(ra + a[i] + 1);
		if (p != 0) {
			ans += (n - p + 1);
		}
	}
	cout << ans;
	return 0;
}