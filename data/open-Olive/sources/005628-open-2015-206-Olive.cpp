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

typedef long long ll;

int n, cur;
int a[100500];
      


struct node {
	node * l;
	node * r;
	int sum;
	node () {
		l = r = NULL;
		sum = 0;
	}
	node (node * l, node * r) : l(l), r(r) {
		sum = l -> sum + r -> sum;
	}
	node (int sum) : sum(sum) {
		l = r = NULL;
	}
};

node * roots[5005];

struct FW {
	int fw[5005];
	void mem() {
		memset(fw, 0, sizeof(fw));
	}
	void update(int i, int d) {
		while (i <= n) {
			fw[i] += d;
			i |= (i + 1);
		}
	}
	int getSum(int r) {
		int res = 0;
		while (r > 0) {
			res += fw[r];
			r = (r & (r + 1)) - 1;
		}
		return res;
	}
};

node * build(int l, int r) {
	if (l == r) return new node(0);
	int mid = (l + r) >> 1;
	return new node(build(l, mid), build(mid + 1, r));
}

int getSum(node * ver, int l, int r, int pl, int pr) {
	if (pl > pr) return 0;
	if (l == pl && r == pr) return ver -> sum;
	int mid = (l + r) >> 1;
	return getSum(ver -> l, l, mid, pl, min(pr, mid)) + getSum(ver -> r, mid + 1, r, max(pl, mid + 1), pr);
}

node * update(node * ver, int l, int r, int pos) {
	if (l == r) return new node(1);
	int mid = (l + r) >> 1;
	if (pos <= mid) return new node(update(ver -> l, l, mid, pos), ver -> r);
		else return new node(ver -> l, update(ver -> r, mid + 1, r, pos));
}

                     
int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scf("%d", &n);
	for (int i = 1; i <= n; i++) scf("%d", &a[i]);
	int x, y;
	x = y = -1;                                                                    
	FW o;
	o.mem();
	int res = 0;
	roots[0] = build(1, n);
	for (int i = 1; i <= n; i++) {
		res += (o.getSum(n) - o.getSum(a[i]));
		o.update(a[i], 1);
		roots[i] = update(roots[i - 1], 1, n, a[i]);
	}
	int best = res;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			cur = res;
			cur += getSum(roots[j], 1, n, a[i] + 1, n);
			cur -= getSum(roots[i], 1, n, a[i] + 1, n);
			cur -= getSum(roots[j], 1, n, a[j] + 1, n);
			cur += getSum(roots[i], 1, n, a[j] + 1, n);
			if (cur < best) {
				best = cur;
				x = i;
				y = j;
			}	
		}
	prf("%d %d\n", x, y);
	return 0;
}