#include <iostream>
#include <algorithm>

using namespace std;

typedef long long li;

int main() {
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n > 2 && m > 2) {
		cout << 1;
		return 0;
	}
	if (n == 2 || m == 2) {
		cout << 0;
		return 0;
	}
	if (n == 1 || m == 1) {
		n = max(n, m);
		cout << (n + 1) / 4;
		return 0;
	}
	/*int n, i, a[100005], d;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (i = 0; i < n; i++) {

	}*/
	return 0;
}