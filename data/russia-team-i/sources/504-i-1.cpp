#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100010];

int main() {
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	int n;
	int d;
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector <int> v;
	for (int i = 0; i < n; i++) {
		if (a[i] > d) {
			v.push_back(a[i]);
		}
	}
	sort(v.begin(), v.end());
	if (v.size() == 0) {
		printf("0");
		return 0;
	}
	if (v.size() == 1) {
		printf("%d", v[0]);
		return 0;
	}
	int ans = v[(int)v.size() - 1];
	int nans = 0;
	nans = v[0] + v[1] - 2 * d;
	for (int i = 2; i < (int)v.size(); i++) {
		if (v[i] >= 3 * d) {
			nans += v[i] - 2 * d;
		}
	}
	printf("%d", max(ans, nans));
	return 0;
}
