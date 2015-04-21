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

using namespace std;

const int maxn = (int)2e4 + 10;

char s[maxn];
int z[maxn];

int main() {
	int d;

	scanf("%d", &d);
	scanf("%s", s);
	int len = strlen(s);

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

	printf("2\na\nb\n");

	return 0;
}
