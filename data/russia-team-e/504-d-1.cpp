#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	int l = 0, r = k;
	vector <int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	while (l != r) {
		int m = (l + r + 1) / 2;
		long long numb = 0;
		bool yes = true;
		for (int i = 0; i < n; i++) {
			if (v[i] < m) {
				yes = false;
				break;
			} else {
				numb += v[i] - min(numb, (long long)(v[i] - m));
			}
		}
		if (!yes) {
			r = m - 1;
		} else if (numb > k) {
			r = m - 1;
		} else {
			l = m;
		}
	}
	printf("%d", l);
	return 0;
}
