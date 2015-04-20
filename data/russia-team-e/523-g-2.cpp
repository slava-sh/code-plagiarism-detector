#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define LL long long
#define LD long double
#define SIZE 500000
#define FILENAME "prizes"

using namespace std;

LL n, m, i, r, k, ans, l, d;

int main() {
	freopen(FILENAME".in", "r", stdin);
	freopen(FILENAME".out", "w", stdout);
	cin >> n >> m; 
	if (n < m) {
		LL temp = n;
		n = m;
		m = temp;
	}

	if (m >= 3) {
		cout << "1";
		return 0;
	}
	if (m == 1) {
		cout << (n + 1) / 4;
		return 0;
	}
	cout << "0";
	return 0;
}
