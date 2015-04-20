#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);

	int n, d;
	cin >> n >> d;
	vector <int> A(n);
	long long ans = 0;
	int i, l, m, r;
	for (i = 0; i < n; ++i) cin >> A[i];
	for (i = 0; i < n && A[n - 1] - A[i] > d; ++i) {
		l = i;
		r = n - 1;
		while (r - l > 1) {
			m = (l + r) / 2;
			if (A[m] - A[i] > d) {
				r = m;
			}
			else {
				l = m;
			}
		}
		ans += (n - r);
	}
	cout << ans << endl;
	return 0;
}