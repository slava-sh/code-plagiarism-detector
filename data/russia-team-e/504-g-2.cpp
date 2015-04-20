#include <cstdio>

using namespace std;

int main() {
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	if (n == 1) {
		printf("%d", (m + 1) / 4);
	} else if (m == 1) {
		printf("%d", (n + 1) / 4);
	} else if (n == 2 || m == 2) {
		printf("0");
	} else if (n == 3 || m == 3) {
		printf("1");
	} else {
		printf("1");
	}
	return 0;
}