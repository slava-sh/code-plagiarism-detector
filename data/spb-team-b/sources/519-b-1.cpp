// b.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int n, a[1000], i, j = 0;
int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	i = 0;
	while (a[i] >= i + 1) {
		j++;
		i++;
	}
	cout << j << endl;
	for (i = 1; i <= j; i++) {
		cout << i << " " << i << endl;
	}
	return 0;
}

