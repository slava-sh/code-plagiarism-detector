// d.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int n, m, x[1000], i, j;
long long l[1000], r[1000], q, re;
int main()
{
	freopen("dunes.in", "r", stdin);
	freopen("dunes.out", "w", stdout);
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> l[i] >> r[i] >> x[i];
	}
	for (j = 0; j < m; j++) {
		cin >> q;
		re = 0;
		for (i = 0; i < n; i++) {
			if ((q >= l[i]) && (q <= r[i])) {
				if ((q - l[i]) % 2 == 0) {
					re = re + x[i];
				}
				else {
					re = re - x[i];
				}
			}
		}
		cout << re << endl;
	}
	return 0;
}

