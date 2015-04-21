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

const int maxn = (int)1e6 + 10;

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

int go(int x, int y) {
	int cnt = 0;

	for (int i = x; i <= y; i++) {
		if (v[i] >= v[y] && v[i] <= v[x]) {
			cnt++;
		}
	}

	return cnt;
}

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	int ans = 0;
	int x = -1;
	int y = -1;
	
	int now = 0;

	vector <int> a;

	for (int i = 1; i <= n; i++) {
		if (now <= v[i]) {
			a.push_back(i);
			now = v[i];
		}
	}

	now = n + 1;

	vector <int> b;

	for (int i = n; i > 0; i--) {
		if (now >= v[i]) {
			b.push_back(i);
			now = v[i];
		}
	}

	int it = 0;

	for (int i = 0; i < (int)a.size(); i++) {
		it = 0;
		while (it < (int)b.size() && b[it] <= a[i]) {
			it++;
		}

		if (it == (int)b.size()) {
			break;
		}

		if (v[b[it]] >= v[a[i]]) {
			continue;
		}

		//if (i == (int)a.size() - 1) {
			while (it < (int)b.size()) {
				int f = go(a[i], b[it]);
				if (f > ans) {
					ans = f;
					x = a[i];
					y = b[it];
				}
				it++;
			}
		/*} else {
			while (it < (int)b.size()) {
				int f = go(a[i], b[it]);
				int f1 = go(a[i + 1], b[it]);

				if (f > f1) {
					if (f > ans) {
						ans = f;
						x = a[i];
						y = b[it];
					}
					it++;
				} else {
					break;
				}
			}
		}*/
	}

	cout << x << ' ' << y << endl;

	return 0;
}
