#include <iostream>

using namespace std;

struct tNode {
	int tl, tr, cnt;
	int curL, curR;
};

const int MAXN = 100000;
int n, a[MAXN];
tNode t[MAXN * 4];

void recount(int cur) {
	t[cur].tl = t[cur * 2].tl;
	t[cur].tr = t[cur * 2 + 1].tr;
	t[cur].cnt = t[cur * 2].cnt + t[cur * 2 + 1].cnt;
	t[cur].cnt -= (t[cur * 2].tr == t[cur * 2 + 1].tl);
}

void buildTree(int cur, int curL, int curR) {
	t[cur].curL = curL;
	t[cur].curR = curR;
	if (curL + 1 == curR) {
		t[cur].tl = t[cur].tr = a[curL];
		t[cur].cnt = 1;
		return;
	}
	buildTree(cur * 2, curL, (curL + curR) / 2);
	buildTree(cur * 2 + 1, (curL + curR) / 2, curR);
	recount(cur);
}

void updateTree(int cur, int p, int c) {
	if (t[cur].curL > p || t[cur].curR <= p)
		return;
	if (t[cur].curL + 1 == t[cur].curR) {
		t[cur].tl = t[cur].tr = c;
		t[cur].cnt = 1;
		return;
	}
	updateTree(cur * 2, p, c);
	updateTree(cur * 2 + 1, p, c);
	recount(cur);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	buildTree(1, 0, n);
	int q, p, c;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> p >> c;
		updateTree(1, p - 1, c);
		cout << t[1].cnt << endl;
	}
	cin >> n;
	return 0;
}