#include <cstdio>
#include <set>
#include <map>

using namespace std;

int main() {
	int n;
	//CHAAAAAAAAAAAAAAAAAAAAAANGE!!!!v
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
		for (int j = 1; j <= 3; j++) {
			int val = 0;
			for (int k = 0; k < j; k++) {
				val *= 10;
				val += str[k] - '0';
			}
			if (M.find(val) != M.end()) {
				mn = val;
				pos = j;
				break;
			}
		} 
		if (mn == -1 || str[pos] == '0') {
			printf("Incorrect\n");
			continue;
		}
		for (int j = 3; j <= 5; j++) {
			int val = 0;
			for (int k = pos; k < pos + j; k++) {
				val *= 10;
				val += str[k] - '0';
			}
			if (M[mn].find(val) != M[mn].end()) {
				reg = val;
				pos += j;
				break;
			}
		}
		//NEED TO DEBUG
		int val = 0;
		if (reg == -1 || str[pos] == '0') {
			printf("Incorrect\n");
			continue;
		}
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
	return 0;
}
