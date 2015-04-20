#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define LL long long
#define LD long double
#define SIZE 500000
#define FILENAME "fence"

using namespace std;

LL n, i, r, a[SIZE], ans, l, d,x, k;

int main() {
	freopen(FILENAME".in", "r", stdin);
	freopen(FILENAME".out", "w", stdout);
	cin >> n >> k;
	for (i = 0; i<n; i++){
		cin >> a[i];
	}
//	cerr << "LOL";

	sort(a, a + n);
//	cerr << "LOL";
	if (n == 1) {
		cout << a[0];
		return 0;
	}

	x = (k - a[0]) / (n - 1);
	for (i = 0; i < n - 1; i++) {
		x = min(x, (k - a[i]) / (n - 1 - i));
//		cerr << "LOL";
	}
	//	for (i = 0; i<n; i++){
 	//	cerr << a[i] << " ";}
	cout << min(x, a[0]);
}
	