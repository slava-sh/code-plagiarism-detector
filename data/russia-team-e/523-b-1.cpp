#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define LL long long
#define LD long double
#define SIZE 500000
#define FILENAME "che"

using namespace std;

LL n, i, r, a[SIZE], ans, l, d;

int main() {
	freopen(FILENAME".in", "r", stdin);
	freopen(FILENAME".out", "w", stdout);
	cin >> n >> d;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
//	for (i = 0; i < n; i++)
//		cout << a[i] << " ";
	l = 0;
	r = 0;                                               
	ans += l - r;
	for (l = 0; l < n; l++) {
		while ((a[r + 1] - a[l] <= d) && (r + 1 < n)) r++;
		ans += n - r - 1;
//		cerr << ans << endl;
	}
	cout << ans;

	return 0;
}
