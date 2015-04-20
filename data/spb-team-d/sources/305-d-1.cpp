#include <fstream>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long tmp[1393];
int main() {
	freopen("dunes.in", "r", stdin);
	freopen("dunes.out", "w", stdout);
	long a[1393][3], n, m, ans[1393];
	cin >> n >> m;
	for (long i = 0; i < n; ++i)
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	for (long i = 0; i < m; ++i)
		cin >> ans[i];
	for (long i = 0; i < m; ++i) {
		for (long j = 0; j < n; ++j) {
			if (ans[i] >= a[j][0]) {
				if (ans[i] <= a[j][1]) {
					if ((ans[i] - a[j][0]) % 2 == 0) {
						tmp[ans[i]] += a[j][2];
					}
					else {
						tmp[ans[i]] -= a[j][2];
					}

				}
			}
		}
	}
	for (long i = 0; i < m; ++i)
		cout << tmp[ans[i]] << endl;

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