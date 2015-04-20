#include <iostream>

using namespace std;

typedef long long li;

li a[300005];

int main() {
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	li n, t, i, j;
	li ans = 0;
	cin >> n >> t;
	for (i = 0; i < n; i++)
		cin >> a[i];
	j = 0;
	for (i = 0; i < n; i++) {
		while (j != n && a[j] - a[i] <= t)
			j++;
		ans += n - j;
	}
	cout << ans;
	return 0;
}