#include <cstdio>

using namespace std;

int a[3000010];

int main() {
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	int n;
	int re;
	scanf("%d %d", &n, &re);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	a[n] = 2000000000 + 2;
	long long ans = 0;
	for (int i = 0; i < n - 1; i++) {
		int l = i + 1;
		int r = n;
		while (l != r) {
			int m = (l + r) / 2;
			if (a[m] - a[i] <= re) {
				l = m + 1;
			} else {
				r = m;
			}
		}
		ans += n - l;
	}
	printf("%lld", ans);
	return 0;
}
