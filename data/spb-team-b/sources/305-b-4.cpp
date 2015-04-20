#include <fstream>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	long a[1393], n, k, i;
	cin >> n;
	for (i = 1; i <= n; ++i)
		cin >> a[i];
	i = 1;
	k = 0;
	while (i <= a[i]) {
		k++;
		i++;
	}
	cout << k << endl;
	i = 1;
	while (i <= k) {
		cout << i << " " << i << endl;
		i++;
	}
/*	long n, a, b, c, d, x, nod = 1;
	cin >> a >> b;
	long nok = a;
	long temp = 2;
	while (nok % b != 0) {
		nok += a;
	}
	while ((a > 1) && (b > 1)) {
		if (a % temp == 0) {
			a /= temp;
			if (b % temp == 0) {
				b /= temp;
				nod *= temp;
			}
			temp = 2;
		}
		else if (b % temp == 0) {
			b /= temp;
			temp = 2;
		}
		else
			temp++;
	}
//	fclose(stdout);
	cout << nod << " " << nok;
	return 0;*/
fclose(stdout);
	return 0;
}