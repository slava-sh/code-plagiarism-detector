#include <iostream>

using namespace std;

const int MAXN = 5000;
int n, a[MAXN], p[MAXN][MAXN];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i) {
		for (int j = i - 1; j >= 0; --j)
			p[i][j] = p[i][j + 1] + (a[i] < a[j]) - (a[i] > a[j]);
		for (int j = i + 1; j < n; ++j)
			p[i][j] = p[i][j - 1] + (a[i] > a[j]) - (a[i] < a[j]);
	}
	int ans = 0, l = -2, r = -2;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (p[i][j] + p[j][i] - 1 > ans) {
				ans = p[i][j] + p[j][i] - 1;
				l = i, r = j;
			}
	cout << l + 1 << ' ' << r + 1 << endl;
	cin >> n;
	return 0;
}