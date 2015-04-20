#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

long long n, h, a[200000], b[200000], u[200000], ans;
const long long INF = 1000000000000000;

void f(long long v, long long i) {
	if (i > 0) {
		if (a[i] > v) {
			v = a[i];
		}
		if (v < 2) {
			u[i] = 1;
		}
		f(v - 1, i - 1);
	}
}

int main(){
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	b[0] = a[0];
	for (int i = 1; i < n; i++) {
		b[i] = b[i - 1] + a[i];
	}
	f(h, n - 1);
	ans = INF;
	for (int i = 0; i < n; i++) {
		if (u[i] == 1) {
			if (ans > (h * (h + 1)) / 2 - (b[i + h - 1] - b[i - 1])) {
				ans = (h * (h + 1)) / 2 - (b[i + h - 1] - b[i - 1]);
			}
		}
	}
	if (ans == INF) {
		cout << "-1";
	}
	else {
		cout << ans;
	}
	return 0;
}