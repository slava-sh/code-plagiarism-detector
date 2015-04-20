#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n, d, p;
long long ans, cur;
vector <long long> a;

int main () {
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	freopen("sochi.in", "r", stdin);freopen("sochi.out", "w", stdout);
	cin >> n >> d;
	a.resize(n + 1);
	if (n == 1) {
		cin >> p;
		cout << p;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a.begin() + 1, a.end());
	ans = a[n];
	cur = ans;
	for (int i = n - 1; i >= 1; i--) {
		if ((i == n - 1 && a[i + 1] - d >= d) || (i != n - 1 && a[i + 1] - 2 * d >= d)) {
			cur += a[i];
			cur -= 2 * d;
			ans = max(ans, cur);
		}
	}
	cout << max(ans, cur);
	return 0;
}