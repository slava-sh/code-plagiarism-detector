#include <iostream>

using namespace std;

long long a[100010];

int main () {
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);
	int n;
	cin >> n;
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i >= 2 && a[i] != a[i - 1]) ans++;
	}
	int qq;
	cin >> qq;
	for (int i = 0; i < qq; i++) {
		int uk;
		long long t;
		cin >> uk >> t;
		long long q = a[uk];
		a[uk] = t;
		if (q == t) {
			cout << ans << endl;
			continue;
		}
		if (uk == 1) {
			if (t == a[uk + 1]) ans--;
			if (q == a[uk + 1]) ans++;
			cout << ans << endl;
			continue;
		}
		if (uk == n) {
			if (t == a[uk - 1]) ans--;
			if (q == a[uk - 1]) ans++;
			cout << ans << endl;
			continue;
		}
		if (a[uk - 1] == a[uk + 1]) {
			if (t == a[uk + 1]) ans -= 2;
			if (q == a[uk + 1]) ans += 2;
			cout << ans << endl;
			continue;
		}
		if ((t == a[uk - 1] || t == a[uk + 1]) && (q == a[uk - 1] || q == a[uk + 1])) {
			cout << ans << endl;
			continue;
		}
		if (t == a[uk - 1] || t == a[uk + 1]) {
			ans--;
			cout << ans << endl;
			continue;
		}
		if (q == a[uk - 1] || q == a[uk + 1]) {
			ans++;
			cout << ans << endl;
			continue;
		}
		cout << ans << endl;
	}
	return 0;
}