#include<iostream>
#include<cstdlib>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#define ll long long
#define ld long double
#define cs(a) ((int)a.size())
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;
struct Vert {
	int l, r, cnt;
};
vector<Vert> tree;
int nn;
void merge(int x) {
	tree[x].l = tree[x * 2].l;
	tree[x].r = tree[x * 2 + 1].r;
	tree[x].cnt = tree[x * 2].cnt + tree[x * 2 + 1].cnt;
	if (tree[x * 2].r == tree[x * 2 + 1].l) {
		if ((tree[x * 2 + 1].l != -1) && (tree[x * 2].r != -1))
			tree[x].cnt--;
	}
}

void upd(int x, int w) {
	x += nn;
	tree[x].l = w;
	tree[x].r = w;
	tree[x].cnt = 1;
	x /= 2;
	while (x) {
		merge(x);
		x /= 2;
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (nn = 1; nn < n; nn *= 2);
	tree.resize(3 * nn);
	int t;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		tree[nn + i].l = t;
		tree[nn + i].r = t;
		tree[nn + i].cnt = 1;
	}
	for (int i = nn + n; i < cs(tree); ++i)
		tree[i].l = -1;
	for (int i = nn - 1; i > 0; --i) {
		merge(i);
	}
	int q;
	scanf("%d", &q);
	int t1, t2;
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", &t1, &t2);
		t1--;
		upd(t1, t2);
		printf("%d\n", tree[1].cnt);
	}
}