// a.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char a, b, c, d;
long long t, i, a1, b1, c1, d1;
int main()
{
	freopen("abcd.in", "r", stdin);
	freopen("abcd.out", "w", stdout);
	cin >> t;
	for (i = 1; i <= t; i++) {
		cin >> a >> b >> c >> d;
		a1 = a - '0';
		b1 = b - '0';
		c1 = c - '0';
		d1 = d - '0';
		if ((((10 * a1 + b1)*(10 * a1 + b1)) + ((10 * c1 + d1)*(10 * c1 + d1))) % 7 == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

