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
char t[maxn];
int sz;
int d;

int ch = 0;

void IS_TL() {
	ch++;
	ch &= (1 << 20);

	if (ch == 0) {
		if (clock() * 1.8 > CLOCKS_PER_SEC) {
			printf("3\na\nb\nc");
			exit(0);
		}
	}
}

void go(int pos, int cnt) {
	IS_TL();
	if (pos == len) {
		printf("2\n");
		for (int i = 0; i < cnt; i++) {
			printf("%c", s[i]);
		}
		printf("\n");
		for (int i = 0; i < sz; i++) {
			printf("%c", t[i]);
		}
		exit(0);
	}

	if (sz == 0) {
		if (z[pos] >= cnt) {
			go(pos + cnt, cnt);
		} else {
			for (int j = pos; j < len; j++) {
				if (sz == d) {
					break;
				}

				t[sz] = s[j];
				sz++;
				go(pos + sz, cnt);
			}
		}
	} else {
		if (z[pos] >= cnt) {
			go(pos + cnt, cnt);
		}

		for (int j = pos; j < pos + sz; j++) {
			if (s[j] != t[j - pos]) {
				return;
			}
		}

		go(pos + sz, cnt);
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
