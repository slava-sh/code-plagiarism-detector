#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long p = 1000000007;
int z[1010];

int main() {
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
	int n;
	scanf("%d", &n);
	vector <int> v(n, -1);
	v[0] = 0;
	long long ans = 2;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		z[i] = x;
		if (i == 0 && z[i] > 0) {
			printf("0");
			return 0;
		}
		if (i == 0 || x == -1) {
			continue;
		}
		if (i + x > n) {
			printf("0");
			return 0;
		}
		for (int j = 0; j < x; j++) {
			if (v[j] == -1) {
				if (v[i + j] != -1) {
					v[j] = v[i + j];
				}
			}
			if (v[i + j] == -1) {
				if (v[j] != -1) {
					v[i + j] = v[j];
				}
			}
			if (v[j] != v[i + j]) {
				printf("0");
				return 0;
			}
		}
		if (i + x != n) {
			if (v[x] == -1) {
				if (v[i + x] != -1) {
					v[x] = (v[i + x] + 1) % 2;
				}
			}
			if (v[i + x] == -1) {
				if (v[x] != -1) {
					v[i + x] = (v[x] + 1) % 2;
				}
			}
			if (v[x] == v[i + x]) {
				printf("0");
				return 0;
			}
		}
	}
	for (int i = 1; i < n; i++) {
		if (v[i] == -1) {
			v[i] = 0;
			ans = (ans * 2) % p;
		}
		if (z[i] == -1) {
			continue;
		}
		for (int j = 0; j < (int)z[i]; j++) {
			v[i + j] = v[j];
		}
		if (i + z[i] != n) {
			v[i + z[i]] = (v[z[i]] + 1) % 2;
		}
	}
	printf("%lld", ans);
	return 0;
}
