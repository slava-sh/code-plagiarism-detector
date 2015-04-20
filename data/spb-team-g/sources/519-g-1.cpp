// g.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int n, i, j, x = 1;
long long a[100000], b, c;
int main()
{
	freopen("merlin.in", "r", stdin);
	freopen("merlin.out", "w", stdout);
	cin >> n;
	for (i = 0; i < n; i++){
		cin >> a[i];
	}
	for (j = 0; j < n - 1; j++) {
		for (i = 0; i < n - 1 - j; i++) {
			if (a[i] < a[i + 1]) {
				b = a[i];
				a[i] = a[i + 1];
				a[i + 1] = b;
			}
		}
	}
		for (j = 0; (j < n) && (x == 1); j++) {
			b = 0;
			for (i = 0; i < j; i++) {
				b = b + a[i];
			}
			c = 0;
			for (i = j + 1; i < n; i++) {
				c = c + a[j] - a[i];
			}
			if (b >= c) {
				x = 0;
			}
			else {
				x = 1;
			}
		}
		cout << j - 1;
	
	return 0;
}

