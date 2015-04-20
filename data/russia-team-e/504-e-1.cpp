#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

set <int> code[1000];

int main() {
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int c, k;
		scanf("%d %d", &c, &k);
		for (int j = 0; j < k; j++) {
			int t;
			scanf("%d", &t);
			code[c].insert(t);
		}
	}
	int m;
	scanf("%d\n", &m);
	for (int i = 0; i < m; i++) {
		if (i != 0) {
			printf("\n");
		}
		char num[15];
		scanf("%s", &num);
		int t1 = 0;
		bool ok = false;
		for (int i1 = 1; i1 <= 3 && !ok; i1++) {
			t1 = 10 * t1 + (num[i1 - 1] - '0');
			int t2 = (num[i1] - '0') * 10 + (num[i1 + 1] - '0');
			for (int i2 = 3; i2 <= 5 && !ok; i2++) {
				t2 = 10 * t2 + (num[i1 + i2 - 1] - '0');
				if (code[t1].count(t2) != 0 && num[i1 + i2] != '0') {
					ok = true;
					int count = 11 - i1 - i2;
					if (count == 3) {
						printf("+%d(%d)", t1, t2);
						printf("%c%c%c", num[i1 + i2], num[i1 + i2 + 1], num[i1 + i2 + 2]);
					} else if (count == 4) {
						printf("+%d(%d)", t1, t2);
						printf("%c%c-%c%c", num[i1 + i2], num[i1 + i2 + 1], num[i1 + i2 + 2], num[i1 + i2 + 3]);
					} else if (count == 5) {
						printf("+%d(%d)", t1, t2);
						printf("%c%c%c-%c%c", num[i1 + i2], num[i1 + i2 + 1], num[i1 + i2 + 2], num[i1 + i2 + 3], num[i1 + i2 + 4]);
					} else if (count == 6) {
						printf("+%d(%d)", t1, t2);
						printf("%c%c-%c%c-%c%c", num[i1 + i2], num[i1 + i2 + 1], num[i1 + i2 + 2], num[i1 + i2 + 3], num[i1 + i2 + 4], num[i1 + i2 + 5]);
					} else if (count == 7) {
						printf("+%d(%d)", t1, t2);
						printf("%c%c%c-%c%c-%c%c", num[i1 + i2], num[i1 + i2 + 1], num[i1 + i2 + 2], num[i1 + i2 + 3], num[i1 + i2 + 4], num[i1 + i2 + 5], num[i1 + i2 + 6]);
					}
				}
			}
		}
		if (!ok) {
			printf("Incorrect");
		}
	}
}

/*2
7 3
981
3517
812
351 3
34712
1234
963
8
79818266456
35196328463
78122472557
01234567890
73517960326
35134712239
35112342013
78120203040
*/