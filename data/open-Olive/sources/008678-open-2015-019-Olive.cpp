#include <iostream>
#include <cstring>

using namespace std;

int a[100010];
int n;

struct der {
	int tr[20010];
	void pstr () {
		memset(tr, 0, sizeof(tr));
	}
	void upd (int idx, int l, int r, int uk) {
		if (l + 1 == r) {
			tr[idx]++;
			return;
		}
		int m = (l + r) / 2;
		if (uk < m) upd(idx * 2 + 1, l, m, uk);
		else upd (idx * 2 + 2, m, r, uk);
		tr[idx] =tr[idx * 2 + 1] + tr[idx * 2 + 2];
	}
	int s (int idx, int l, int r, int ll, int rr) {
		if (ll <= l && r <= rr) {
			return tr[idx];
		}
		if (rr <= l || r <= ll) {
			return 0;
		}
		int m = (l + r) / 2;
		int s1 = s(idx * 2 + 1, l, m, ll, rr),
			s2 = s(idx * 2 + 2, m, r, ll, rr);
		return s1 + s2;
	}
};

int ll[5010];
int rr[5010];
der tr;

int main () {
	scanf("%d", &n);
	tr.pstr();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		ll[i] = tr.s(0, 1, n + 1, a[i], n + 1);
		rr[i] = (n - a[i] - (i - 1 - ll[i]));
		tr.upd(0, 1, n + 1, a[i]);
	}
	int anss = 0, ansi = -1, ansj = -1;
	for (int i = 1; i <= n; i++) {
		anss += ll[i] + rr[i];
	}
	int qwe = anss;
	for (int i = 1; i <= n; i++) {
		tr.pstr();
		for (int j = i + 1; j <= n; j++) {
			int ans = qwe;
			int k1 = tr.s(0, 1, n + 1, a[i], n + 1);
			ans += 2 * k1;
			ans -= 2 * ((j - i) - 1 - k1);
			k1 = tr.s(0, 1, n + 1, 1, a[j]);
			ans += 2 * k1;
			ans -= 2 * ((j - i) - 1 - k1);
			if (a[i] < a[j]) ans += 2;
			else ans -= 2;
			if (ans < anss) {
				anss = ans;
				ansi = i;
				ansj = j;
			}
			tr.upd(0, 1, n + 1, a[j]);
		}
	}
	printf("%d %d", ansi, ansj);
	return 0;
}