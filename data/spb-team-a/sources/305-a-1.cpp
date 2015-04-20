#include <fstream>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	freopen("abcd.in", "r", stdin);
	freopen("abcd.out", "w", stdout);
	long n, a, b, c, d, x;
	cin >> n;
	for (long i = 1; i <= n; ++i) {
		cin >> x;
		a = x % 10;
		x /= 10;
		b = x % 10;
		x /= 10;
		c = x % 10;
		x /= 10;
		d = x % 10;
		x /= 10;
		if (((a * (b * b)) + (c * (d * d))) % 7 != 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	fclose(stdout);
	return 0;
}