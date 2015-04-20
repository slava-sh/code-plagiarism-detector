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
	k = min(n, m);
	if ((n == 1) || (m == 1)) {
		if (n == 1) cout << (m + 1) / 4;
		else cout << (n + 1) / 4;
		return 0;
	}
	cout << ((k + 1) / 4);
	return 0;
}
