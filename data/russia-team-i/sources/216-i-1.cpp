#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
typedef long long ll;

using namespace std;

int a[100010];

int main() {
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int uk = 0;// укакзатель на первое >= 3d
	int x;// укакзатель на первое >= d
	bool b = 1, bb = 1;
	if (n == 1) {
		cout << a[1];
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] >= 3 * d) {
			uk = i;
			break;
		}
		if (a[i] >= d && b) {
			x = i;
			b = 0;
		}
	}
	int p, k;
	b = 1;
	int o = 0;
	ll ans = 0;
	if (uk - x >= 2)
		p = a[uk - 1], k = a[uk - 2];
	if (uk - x == 1 || n - x == 0) {
		p = a[x];
		o = 2;
	}
	if (uk - x == 0)
		b = 0;
	if (!b) {
		if (n - uk == 0) {
			cout << a[n];
			return 0;
		}
		ans += a[n] - d;
		ans += a[n - 1] - d;
		for (int i = uk; i <= n - 2; i++)
			ans += a[i] - d - d;
		cout << ans; 
		return 0;
	}
	if (uk == 0) {
		if (o == 2) {
			cout << p;
			return 0;
		}
		cout << (p - d) + k - d;
		return 0;
	}
	if (o == 2) {
		ans += p - d;
		ans += a[n] - d;
		for (int i = uk; i <= n - 1; i++) 
			ans += a[i] - d - d;
		cout << ans;
		return 0;
	}
	ans += p - d + k - d;
	for (int i = uk; i <= n; i++)
		ans += a[i] - d - d;
	cout << ans;
	return 0;
}




