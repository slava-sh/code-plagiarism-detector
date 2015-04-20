#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100010];

int main() {
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	int ans = 0;
	int n;
	int d;
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ans = max(ans, a[i]);
	}
	vector <int> v;
	for (int i = 0; i < n; i++) {
		if (a[i] > d) {
			v.push_back(a[i]);
		}
	}
	sort(v.begin(), v.end());
	if (v.size() == 0) {
		printf("%d", ans);
		return 0;
	}
	if (v.size() == 1) {
		printf("%d", max(ans, v[0]));
		return 0;
	}
	int nans = v[(int)v.size() - 1] + v[(int)v.size() - 2] - 2 * d;
	for (int i = 0; i < (int)v.size() - 2; i++) {
		if (v[i] >= 3 * d) {
			nans += v[i] - 2 * d;
		}
	}
	ans = max(ans, nans);
	nans = v[(int)v.size() - 1] - d;
	int pos = 0;
	while (pos + 1 != (int)v.size() - 1 && v[pos + 1] < 3 * d) {
		pos++;
	}
	nans += v[pos] - d;
	for (int i = pos + 1; i < (int)v.size() - 1; i++) {
		if (v[i] >= 3 * d) {
			nans += v[i] - 2 * d;
		}
	}
	ans = max(ans, nans);
	nans = 0;
	pos = 0;
	while (pos + 2 != v.size() && v[pos + 2] < 3 * d) {
		pos++;
	}
	nans = v[pos] + v[pos + 1] - 2 * d;
	for (int i = pos + 2; i < (int)v.size(); i++) {
		if (v[i] >= 3 * d) {
			nans += v[i] - 2 * d;
		}
	}
	printf("%d", max(ans, nans));
	return 0;
}
