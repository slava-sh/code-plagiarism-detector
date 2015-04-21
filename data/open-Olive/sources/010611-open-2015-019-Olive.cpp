#include <iostream>
#include <cstring>

using namespace std;

int a[100010];
int n;
long long rnd;

void ff () {
	rnd = (rnd * 1465182364) % 1000000009;
}

struct node {
	int key;
	int prior;
	int sz;
	node *l, *r;
	node () {
		prior = rnd; 
		ff();
		l = 0;
		r = 0;
		sz = 1;
	}
};

int sz (node *v) {
	if (v == 0) return 0;
	return v -> sz;
}

void upd (node *v) {
	if (v == 0) return;
	v -> sz = sz(v -> l) + sz(v -> r) + 1;
}

node *merge (node *root1, node *root2) {
	if (root1 == 0) return root2;
	if (root2 == 0) return root1;
	if (root1 -> prior < root2 -> prior) {
		root1 -> r = merge(root1 -> r, root2);
		upd(root1);
		return root1;
	} else {
		root2 -> l = merge(root1, root2 -> l);
		upd(root2);
		return root2;
	}
}

pair <node*, node*> split(node *root, int key) {
	if (root == 0) return make_pair(root, root);
	if (root -> key > key) {
		pair <node*, node*> pp = split(root -> l, key);
		root -> l = pp.second;
		upd(root);
		return make_pair(pp.first, root);
	} else {
		pair <node*, node*> pp = split(root -> r, key);
		root -> r = pp.first;
		upd(root);
		return make_pair(root, pp.second);
	}
}

node *insert(node *root, node *v) {
	if (v == 0) return root;
	if (root == 0) return v;
	if (v -> prior < root -> prior) {
		pair <node*, node*> pp = split(root, v -> key);
		v -> l = pp.first;
		v -> r = pp.second;
		upd(v);
		return v;
	}
	if (v -> key < root -> key) {
		root -> l = insert(root -> l, v);
	} else {
		root -> r - insert(root -> r, v);
	}
	upd(root);
	return root;
}

int ansq (node *root, int key) {
	if (root == 0) return 0;
	if (root -> key > key) {
		return ansq(root -> l, key);
	} else {
		return ansq(root -> r, key) + sz(root -> l) + 1;
	}
}

node mass[10000010];
int qwe;

node *nw (int key) {
	node *v = mass + qwe;
	qwe++;
	v -> key = key;
	v -> prior = rnd; 
	ff();
	v -> sz = 1;
	v -> l = 0;
	v -> r = 0;
	return v;
}

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
node *uk[5010];

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	srand(13);
	scanf("%d", &n);
	tr.pstr();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		uk[i] = nw(a[i]);
		ll[i] = tr.s(0, 1, n + 1, a[i], n + 1);
		rr[i] = (n - a[i] - (i - 1 - ll[i]));
		tr.upd(0, 1, n + 1, a[i]);
	}
	int anss = 0, ansi = -1, ansj = -1;
	for (int i = 1; i <= n; i++) {
		anss += ll[i] + rr[i];
	}
	int qwee = anss;
	for (int i = 1; i <= n; i++) {
		node *root = 0;
		for (int j = i + 1; j <= n; j++) {
			int ans = qwee;
			int qw = ansq(root, a[i]);
			int k1 = (j - i) - 1 - qw;
			ans += 2 * k1;
			ans -= 2 * ((j - i) - 1 - k1);
			k1 = ansq(root, a[j]);
			ans += 2 * k1;
			ans -= 2 * ((j - i) - 1 - k1);
			if (a[i] < a[j]) ans += 2;
			else ans -= 2;
			if (ans < anss) {
				anss = ans;
				ansi = i;
				ansj = j;
			}
			root = insert(root, uk[j]);
		}
	}
	printf("%d %d", ansi, ansj);
	return 0;
}