#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define LL long long
#define LD long double
#define SIZE 500000
#define FILENAME "fence"

using namespace std;

LL n, i, r, a[SIZE], ans, l, d;
LL minn = 10000000000, k;

int main() {
	freopen(FILENAME".in", "r", stdin);
	freopen(FILENAME".out", "w", stdout);
	cin >> n >> k;
	for (i = 0; i<n; i++){
		cin >> a[i];
		if (a[i] < minn)
			minn = a[i];
	}
	cout << min(minn, k/n);
}
	