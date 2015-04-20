#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, d;
long long ans, cnt;
vector <long long> a;


int main () {
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	freopen("sochi.in", "r", stdin);freopen("sochi.out", "w", stdout);
	cin >> n >> d;
	a.resize(n + 1);
	for (int j = 1; j <= n; j++) {
		cin >> a[j];
	}
	sort(a.begin(), a.end());
	ans = a[n];
	cnt = ans;
	int i = n - 1;
	for (i = n - 1; i >= 1; i--) {
		if ((i == n - 1 && a[i + 1] >= 2 * d) || (i != n - 1 && a[i + 1] >= 3 * d)) {
			cnt += a[i];
			cnt -= 2 * d;
			ans = max(ans, cnt);
		} else {
			break;
		}
	}
	if (a[i] >= d && ((i == n - 1 && a[i + 1] >= 2 * d) || (i != n - 1 && a[i + 1] >= 3 * d))) {
		cnt = cnt + a[i] - 2 * d;
		ans = max(cnt, ans);
	}
	i--;
	if (i >= 1 && a[i] >= d && ((i == n - 1 && a[i + 1] >= 2 * d) || (i != n - 1 && a[i + 1] >= 3 * d))) {
		cnt = cnt + a[i] - 2 * d;
		ans = max(cnt, ans);
	}
	cout << ans;
	return 0;
}