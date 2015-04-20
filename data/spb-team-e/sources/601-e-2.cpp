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
	if (m >= n) {
		if (res1 + B % 2 == res2) {
			cout << "Draw\n";
		} else if (res1 + B % 2 > res2) {
			cout << "Petya\n";
		} else {
			cout << "Vasya\n";
		}
	} else if (m > B){
		if (m % 2 == 1) {
			if (res1 + B / 2 + B % 2 >= m / 2 + 1) {
				cout << "Petya\n";
			} else {
				cout << "Vasya\n";
			}
		} else {
			if (B / 2 + res1 + B % 2 >= m / 2) {
				if (res1 + B % 2 > res2 && res2 + B / 2 < m / 2) {
					cout << "Vasya\n";
				} else {
					cout << "Draw\n";
				}
			} else {
				cout << "Vasya\n";
			}
		}				
	} else {
		if (m % 2 == 0) {
			cout << "Draw\n";
	 	} else {
	 		cout << "Petya\n";
	 	}
	}	
	
				
		 	

		 	
return 0;
}