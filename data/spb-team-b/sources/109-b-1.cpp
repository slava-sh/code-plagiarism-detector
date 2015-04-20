#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long a[1000], b[1000], n, m;

int main(){
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > i + 1) {
			a[i] = i + 1;
		}
	}
	m = 0;
	for (int i = 0; i < n; i++) {
		if (m < a[i]) {
			m = a[i];
		}
	}
	cout << m << "\n";
	for (int i = 0; i < m; i++) {
		cout << i + 1 << " " << i + 1 << "\n";
	}
	return 0;
}