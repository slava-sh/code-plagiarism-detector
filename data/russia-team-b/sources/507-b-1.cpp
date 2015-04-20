#include <stdio.h>
#include <iostream>
#define ll long long
#define TASKNAME "che"
using namespace std;

const int maxn = 3*1e5+2;

int a[maxn];

int main() {
#ifdef SHAOLING
	freopen("input.txt", "r", stdin);
#else
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif

	int n, r;
	cin >> n >> r;
	for (int i = 0 ; i < n; i++)
		cin >> a[i];
	int j = 0;

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		j = max(i, j);
		while (j < n && a[j] - a[i] <= r)
			j++;
		ans += n - j;
	}
	cout << ans;
	return 0;
}