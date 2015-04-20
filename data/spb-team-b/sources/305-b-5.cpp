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
	return 0;
}