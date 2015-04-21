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

struct point {
	int sum;
	int l;
	int r;

	point(): sum(0), l(0), r(0) {

	}

	point(int sum, int l, int r): sum(sum), l(l), r(r) {

	}
};

point mas[(int)3e7];
int position = 0;

int my_new(int sum, int l, int r) {
	mas[position] = point(sum, l, r);
	return position++;
}

void build(int t, int l, int r) {
	if (l == r) {
		
	} else {
		mas[t].l = my_new(0, -1, -1);
		mas[t].r = my_new(0, -1, -1);

		int m = (l + r) / 2;

		build(mas[t].l, l, m);
		build(mas[t].r, m + 1, r);
	}
}

int change(int t, int l, int r, int pos) {
	if (l == r) {
		return my_new(1, -1, -1);
	} else {
		int m = (l + r) / 2;

		if (pos <= m) {
			int f = change(mas[t].l, l, m, pos);
			return my_new(mas[mas[t].r].sum + mas[f].sum, f, mas[t].r);
		} else {
			int f = change(mas[t].r, m + 1, r, pos);
			return my_new(mas[mas[t].l].sum + mas[f].sum, mas[t].l, f);
		}
	}
}

int go_sum(int t, int l, int r, int lm, int rm) {
	if (l == lm && r == rm) {
		return mas[t].sum;
	} else {
		int m = (l + r) / 2;

		if (rm <= m) {
			return go_sum(mas[t].l, l, m, lm, rm);
		} else if (lm > m) {
			return go_sum(mas[t].r, m + 1, r, lm, rm);
		} else {
			return go_sum(mas[t].l, l, m, lm, m) + go_sum(mas[t].r, m + 1, r, m + 1, rm);
		}
	}
}

int tr[maxn];
int n;

int go(int x, int y) {
	if (x > y) {
		return 0;
	}

	if (v[x] < v[y]) {
		return 0;
	}

	if (x == y) {
		return 0;
	}

	return go_sum(tr[y], 1, n, v[y], v[x]) - go_sum(tr[x - 1], 1, n, v[y], v[x]);

	/*int cnt = 0;

	for (int i = x; i <= y; i++) {
		if (v[i] >= v[y] && v[i] <= v[x]) {
			cnt++;
		}
	}

	return cnt;*/
}

int main() {
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

	build(tr[0], 1, n);

	for (int i = 1; i <= n; i++) {
		tr[i] = change(tr[i - 1], 1, n, v[i]);
	}

	now = n + 1;

	vector <int> b;

	for (int i = n; i > 0; i--) {
		if (now >= v[i]) {
			b.push_back(i);
			now = v[i];
		}
	}

	reverse(b.begin(), b.end());

	int it = 0;

	for (int i = 0; i < (int)a.size(); i++) {
		while (it < (int)b.size() && b[it] <= a[i]) {
			it++;
		}

		if (it == (int)b.size()) {
			break;
		}

		if (v[b[it]] >= v[a[i]]) {
			continue;
		}

		if (i == (int)a.size() - 1) {
			while (it < (int)b.size()) {
				int f = go(a[i], b[it]);
				if (f > ans) {
					ans = f;
					x = a[i];
					y = b[it];
				}
				it++;
			}
		} else {
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
		}
	}

	cout << x << ' ' << y << endl;

	return 0;
}
