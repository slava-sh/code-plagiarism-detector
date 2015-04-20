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
		d = x % 10;
		x /= 10;
		c = x % 10;
		x /= 10;
		b = x % 10;
		x /= 10;
		a = x % 10;
		if ((((a * 10 + b) * (a * 10 + b)) + ((c * 10 + d) * (c * 10 + d))) % 7 == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	fclose(stdout);
	return 0;
}