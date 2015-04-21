#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <iterator>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define scf scanf
#define prf printf

using namespace std;

int n, q;
int pos, data;
int a[100500];

struct node {
	int pref, suf;
	int cnt;
} tree[4 * 100500];

void makeMerge(int ver) {
	tree[ver].pref = tree[ver + ver].pref;
	tree[ver].suf = tree[ver + ver + 1].suf;
	tree[ver].cnt = tree[ver + ver].cnt + tree[ver + ver + 1].cnt;
	if (tree[ver + ver].suf == tree[ver + ver + 1].pref) tree[ver].cnt--;
}

void build(int ver, int l, int r) {
	if (l == r) {
		tree[ver].pref = tree[ver].suf = a[l];
		tree[ver].cnt = 1;
		return;
	} 
	int mid = (l + r) >> 1;
	build(ver + ver, l, mid);
	build(ver + ver + 1, mid + 1, r);
	makeMerge(ver);
}

void update(int ver, int l, int r, int pos, int data) {
	if (l == r) {
		tree[ver].pref = tree[ver].suf = data;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) update(ver + ver, l, mid, pos, data);
		else update(ver + ver + 1, mid + 1, r, pos, data);
	makeMerge(ver);
}

int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scf("%d", &n);
	for (int i = 1; i <= n; i++) scf("%d", &a[i]);
	build(1, 1, n);
	scf("%d", &q);
	while (q--) {
		scf("%d%d", &pos, &data);
		update(1, 1, n, pos, data);
		prf("%d\n", tree[1].cnt);
	}
	return 0;
}