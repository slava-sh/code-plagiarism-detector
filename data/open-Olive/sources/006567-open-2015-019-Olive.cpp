#include <iostream>

using namespace std;

int a[100010];
int n;

int f () {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] < a[j]) ans++;
		}
		for (int j = i + 1; j <= n; j++) {
			if (a[i] > a[j]) ans++;
		}
	}
	return ans;
}

int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int s = f(), ansi = -1, ansj = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int q = f();
			if (q < s) {
				s = q;
				ansi = i;
				ansj = j;
			}
		}
	}
	cout << ansi << " " << ansj;
	return 0;
}