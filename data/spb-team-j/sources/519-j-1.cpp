// j.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int n, h, i, a[200000], x = 1, j, z = 0, b = 0, bm;
int main()
{
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	cin >> n >> h;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i = 0; i < n; i++) {
		if ((a[i] == 0) || (a[i] == 1)) {
			for (j = 1; (j < h) && (x == 1); j++) {
				if (a[i + j] <= j + 1) {
					x = 1;
				}
				else {
					x = 0;
				}
			}
			if (x == 1) {
				
				for (j = 0; j < h; j++) {
					b = b + j + 1 - a[i + j];
				}
				if ((bm >= b) || (z == 0)) {
					bm = b;
				}
				z = 1;
			}
		}
	}
	if (z == 0) {
		cout << -1;
	}
	else {
		cout << 3;
	}
	return 0;
}

