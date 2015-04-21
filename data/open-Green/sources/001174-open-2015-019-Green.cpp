#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long ansq (long long n, long long k) {
	if (k == 1) {
		return n / 2 + n % 2;
	}
	long long mx = n / 2 + n % 2;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			mx = min(mx, ansq(n / i, k - 1) * (i / 2 + i % 2));
			mx = min(mx, ansq(i, k - 1) * ((n / i) / 2 + (n / i) % 2));
		}
	}
	return mx;
}

int main () {
	long long n, k;
	cin >> n >> k;
	cout << ansq(n, k);
	return 0;
}