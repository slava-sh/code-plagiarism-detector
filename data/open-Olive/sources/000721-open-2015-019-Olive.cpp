#include <iostream>

using namespace std;

int a[1000010];
int b[1000010];

int main () {
	int n;
	int ss = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = abs(i - a[i]);
		ss += b[i];
	}
	int anss = ss, ansi = -1, ansj = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ss -= b[i] + b[j];
			ss += abs(j - a[i]) + abs(i - a[j]);
			if (ss < anss) {
				ansi = i;
				ansj = j;
				anss = ss;
			}	
			ss -= abs(j - a[i]) + abs(i - a[j]);
			ss += b[i] + b[j];
		}
	}
	cout << ansi << " " << ansj;
	return 0;
}