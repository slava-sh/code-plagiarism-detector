#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define FILENAME "sochi"
int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	int n, d;
	scanf("%d%d", &n, &d);
	int border_max1 = -1;
	int border_max2 = -1;
	int ans = 0;
	int max_once = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a > max_once)
			max_once = a;

		if (a <= d)
			continue;
		if (a < 3 * d) {
			if (a >= border_max1) {
				border_max2 = border_max1;
				border_max1 = a;
			} else
			if (a > border_max2)
				border_max2 = a;
			continue;
		}
		ans += a - 2 * d;
	}
	if (border_max1 == -1 && border_max2 == -1) {
		if (!ans)
			printf("%d\n", max_once);
		else
			printf("%d\n", max(max_once, ans + 2 * d));
	} else
	if (border_max2 == -1)
		printf("%d\n", max(max_once, ans + border_max1));
	else
		printf("%d\n", max(max_once, ans + border_max1 + border_max2 - 2 * d));
	return 0;
}