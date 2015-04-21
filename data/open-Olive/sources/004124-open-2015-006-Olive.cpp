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

const int maxn = 5010;

int v[maxn];
int t[4 * maxn];

int go_sum(int it, int l, int r, int lm, int rm) {
	if (l == lm && r == rm) {
		return t[it];
	}

	int m = (l + r) / 2;

	if (rm <= m) {
		return go_sum(2 * it, l, m, lm, rm);
	} else if (lm > m) {
		return go_sum(2 * it + 1, m + 1, r, lm, rm);
	} else {
		return go_sum(2 * it, l, m, lm, m) + go_sum(2 * it + 1, m + 1, r, m + 1, rm);
	}
}

void change(int it, int l, int r, int pos) {
	if (l == r) {
		t[it] = 1;
	} else {
		int m = (l + r) / 2;

		if (pos <= m) {
			change(2 * it, l, m, pos);
		} else {
			change(2 * it + 1, m + 1, r, pos);
		}

		t[it] = t[2 * it] + t[2 * it + 1];
	}
}

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int ans = 0;
	int x = -1;
	int y = -1;

	for (int i = 0; i < n; i++) {
		memset(t, 0, sizeof t);
		
		for (int j = i + 1; j < n; j++) {
			if (v[i] > v[j]) {
				if (ans <= v[i] - v[j] - 1 && ans <= j - i - 1) {
					int f = go_sum(1, 1, n, v[j], v[i]);

					if (f >= ans) {
						ans = f;
						x = i + 1;
						y = j + 1;
					}
				}
				change(1, 1, n, v[j]);
			}
		}
	}

	printf("%d %d", x, y);

	return 0;
}
