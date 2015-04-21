#pragma comment(linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <ctime>

using namespace std;

const int maxn = (int)2e4 + 10;

char s[maxn];
int len;
int z[maxn];
int z1[maxn];
int sz;
int d;
int beg;

int ch = 0;

void go(int pos, int cnt) {
	if (pos == len) {
		printf("2\n");
		for (int i = 0; i < cnt; i++) {
			printf("%c", s[i]);
		}
		printf("\n");
		for (int i = beg; i < beg + sz; i++) {
			printf("%c", s[i]);
		}
		exit(0);
	}

	if (sz == 0) {
		if (z[pos] >= cnt) {
			go(pos + cnt, cnt);
		} else {
			beg = pos;
			for (int l = 0, r = 0, i = pos + 1; i < len; i++) {
				z1[i] = 0;
				if (i < r) {
					//z1[i] = min(z1[i - l + pos], r - i);
				}

				while (i + z1[i] < len && s[pos + z1[i]] == s[i + z1[i]]) {
					z1[i]++;
				}

				if (i + z1[i] > r) {
					l = i;
					r = i + z1[i];
				}
			}

			for (int i = 1; i <= d; i++) {
				sz = i;
				go(pos + sz, cnt);
			}
		}
	} else {
		if (z[pos] >= cnt) {
			go(pos + cnt, cnt);
		}
		
		if (z1[pos] >= sz) {
			go(pos + sz, cnt);
		}
	}
}



int main() {
	scanf("%d", &d);
	scanf("%s", s);
	len = strlen(s);

	if (d >= len) {
		printf("1\n%s", s);
		return 0;
	}

	for (int l = 0, r = 0, i = 1; i < len; i++) {
		if (i < r) {
			z[i] = min(z[i - l], r - i);
		}

		while (i + z[i] < len && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}

		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}

	for (int i = 1; i < len; i++) {
		if (i + z[i] == len && i <= d && len % i == 0) {
			printf("1\n");
			for (int j = 0; j < i; j++) {
				printf("%c", s[j]);
			}
			return 0;
		}
	}

	if (2 * d >= len) {
		printf("2\n");
		for (int i = 0; i < d; i++) {
			printf("%c", s[i]);
		}
		printf("\n");
		for (int i = d; i < len; i++) {
			printf("%c", s[i]);
		}
		return 0;
	}

	for (int i = 1; i <= d; i++) {
		sz = 0;
		go(i, i);
	}

	printf("3\na\nb\nc");

	return 0;
}
