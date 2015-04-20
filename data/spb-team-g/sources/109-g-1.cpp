#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000], b[100001], n;

int main(){
	freopen("merlin.in", "r", stdin);
	freopen("merlin.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	b[0] = a[0];
	for (int i = 1; i < n; i++) {
		b[i] = b[i - 1] + a[i];
	}
	if (a[n - 1] == a[0]) {
		cout << 0;
		return 0;
	}
	else {
		for (int i = n - 1; i > 0; i--) {
			if (b[n - 1] >= a[i - 1] * i) {
				cout << n - i;
				return 0;
			}
		}
	}
}