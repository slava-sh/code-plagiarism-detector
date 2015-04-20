#pragma comment(linker, "/STACK:0x04000000")
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, d;
int a[300010];

int main() {
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int r = 1;
	long long ans = 0 ;
	for (int l = 0; l < n - 1; l++) {
		while (r < n && a[r] - a[l] <= d) r++;
		ans += n - r;
	}
	cout << ans;
}