#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long a[100000], n, l1, r1, l2, r2, l, r, m, il1, il2, ir1, ir2;

int b(int l, int r, int x) {
	if (l + 1 == r) {
		return r;
	}
	if (a[(l + r) / 2] < x) {
		return b((l + r) / 2, r, x);
	} else {
		return b(l, (l + r) / 2, x);
	}
}

void win(long long v1, long long v2) {
	if (v1 > (m + 1) / 2) {
		v1 = (m + 1) / 2;
	}
	if (v2 > m / 2) {
		v2 = m / 2;
	}
	if (v1 > v2) {
		cout << "Petya";
	}
	else {
		if (v1 < v2) {
			cout << "Vasya";
		}
		else {
			cout << "Draw";
		}
	}
}

int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> m >> l1 >> r1 >> l2 >> r2;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	l = 0;
	r = n + 1;
	il1 = b(-1, n + 1, l1);
	il2 = b(-1, n + 1, l2);
	ir1 = b(-1, n + 1, r1 + 1) - 1;
	ir2 = b(-1, n + 1, r2 + 1) - 1;
	if ((il1 > ir2) || (il2 > ir1)) {
		win(ir1 - il1 + 1, ir2 - il2 + 1);
		return 0;
	}
	if ((il1 <= il2) && (ir1 >= ir2)) {
		win(ir1 - il1 + 1 - (ir2 - il2 + 2) / 2, (ir2 - il2 + 1) / 2);
		return 0;
	}
	if ((il2 <= il1) && (ir2 >= ir1)) {
		win((ir1 - il1 + 2) / 2, ir2 - il2 + 1 - (ir1 - il1 + 1) / 2);
		return 0;
	}
	if (il1 > il2) {
		win((ir2 - il1 + 2) / 2 + (ir1 - ir2 + 1), (ir2 - il1 + 1) / 2 + (il1 - il2 + 1));
		return 0;
	}
	if (il1 < il2) {
		win((ir1 - il2 + 2) / 2 + (il2 - il1 + 1), (ir1 - il2 + 1) / 2 + (ir2 - ir1 + 1));
		return 0;
	}
}