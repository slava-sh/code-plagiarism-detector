#include <cstdio>
#include <set>
#include <map>

using namespace std;

int main() {
	int n;
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	scanf("%d", &n);
	map <int, set <int> > M;
	for (int i = 0; i < n; i++) {
		int m, k;
		scanf("%d%d", &k, &m);
		for (int j = 0; j < m; j++) {
			int t;
			scanf("%d", &t);
			M[k].insert(t);
		}
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		char str[15];
		scanf("\n%s", str);
		if (str[0] == '0') {
			printf("Incorrect\n");
			continue;
		}
		int mn = -1, pos = -1, reg = -1;
		bool flag = false;
		for (int j = 1; j <= 3; j++) {
			int val = 0;
			for (int k = 0; k < j; k++) {
				val *= 10;
				val += str[k] - '0';
			}
			if (M.find(val) != M.end()) {
				mn = val;
				pos = j;
				reg = -1;
				if (str[pos] == '0') {
					mn = -1;
				}
				if (mn != -1) {
					for (int p = 3; p <= 5; p++) {
						int val = 0;
						for (int k = pos; k < pos + p; k++) {
							val *= 10;
							val += str[k] - '0';
						}
						if (!flag && M[mn].find(val) != M[mn].end()) {
							if (str[pos + p] == '0') {
								break;
							}
							reg = val;
							flag = true;
							pos += p;
							int val = 0;
							for (int k = pos; k < 11; k++) {
								val *= 10;
								val += str[k] - '0';
							}
							if (11 - pos == 3) {
								printf("+%d(%d)%d\n", mn, reg, val);
							}
							if (11 - pos == 4) {
								printf("+%d(%d)%02d-%02d\n", mn, reg, val / 100, val % 100);
							}
							if (11 - pos == 5) {
								printf("+%d(%d)%03d-%02d\n", mn, reg, val / 100, val % 100);
							}
							if (11 - pos == 6) {
								printf("+%d(%d)%02d-%02d-%02d\n", mn, reg, val / 10000, val % 10000 / 100, val % 100);
							}
							if (11 - pos == 7) {
								printf("+%d(%d)%03d-%02d-%02d\n", mn, reg, val / 10000, val % 10000 / 100, val % 100);
							}
						}
					}
				}
			}
		} 
		if (!flag) {
			printf("Incorrect\n");
			continue;
		}
	}
	return 0;
}