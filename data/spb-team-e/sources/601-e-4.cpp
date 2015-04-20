#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
		int n, m, l1, r1, l2, r2, res1 = 0, res2 = 0;
	cin >> n >> m >> l1 >> r1 >> l2 >> r2;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a >= l1 && a <= r1) {
			res1++;
		}
		if (a >= l2 && a <= r2) {
			res2++;
		}
	}
	int B = res1 + res2 - n;
	res1 -= B, res2 -= B;
	if (m <= B) {
		if (m % 2 == 1) {
			cout << "Petya\n";
		} else {
			cout << "Draw\n";
		}
	} else if (m >= n) {
	cout << "1\n";
		if (res1 + B % 2 == res2) {
			cout << "Draw\n";
		} else if (res1 + B % 2 > res2) {
			cout << "Petya\n";
		} else {
			cout << "Vasya\n";
		}
	} else {
		if (B % 2 == 0) {
			int x = (m - B) / 2.0;
			if (x <= res1) {
				cout << "Petya\n";
			} else {
				cout << "Vasya";
			}
		} else {
			if (B / 2 + 1 + res1 >= m && res1 + 1 > res2) {
				cout << "Petya\n";
		 	} else if (B / 2 + 1 == res2) {
		 		cout << "Draw\n";
		 	} else {
		 		cout << "Vasya\n";
		 	}
		}
	}
return 0;
}
