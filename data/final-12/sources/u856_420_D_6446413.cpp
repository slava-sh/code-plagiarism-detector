#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 1000000;

int ans[N];
bool used[N];

struct Node {
	int pos;
	int x;
	int size;
	int priority;
	Node *l, *r;
	Node(int pos1) {
		pos = pos1;
		x = -1;
		priority = rand();
		size = 1;
		l = NULL;
		r = NULL;
	}	
};

void dfs(Node *nd) {
	if (nd == NULL) {
		return;
	}
	dfs(nd->l);
	ans[nd->pos] = nd->x;
	dfs(nd->r);
}

Node *splitter = new Node(-1);
Node *root = NULL;

int getSize(Node *n) {
	return n == NULL ? 0 : n->size;
}

void update(Node *n) {
	n->size = 1 + getSize(n->l) + getSize(n->r);
}

Node* merge(Node *l, Node *r) {
	if (l == NULL) {
		return r;
	}
	if (r == NULL) {
		return l;
	}
	if (l->priority > r->priority) {
		l->r = merge(l->r, r);
		update(l);
		return l;
	} else {
		r->l = merge(l, r->l);
		update(r);
		return r;
	}
}

// size(splitter->l) == sz
Node* split(Node *root, int sz) {
	if (root == NULL) {
		splitter->l = NULL;
		splitter->r = NULL;
		return splitter;
	}
	int leftSize = getSize(root->l);
	Node *x = NULL;
	if (sz <= leftSize) {
		x = split(root->l, sz);
		root->l = x->r;
		x->r = root;
	} else {
		x = split(root->r, sz - leftSize - 1);
		root->r = x->l;
		x->l = root;
	}
	update(root);
	update(x);
	return x;
}

int main() {	
	int n, m;
	srand(294384);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		Node *nd = new Node(i);
		root = merge(root, nd);
	}
	for (int i = 0; i < m; i++) {
		int x, pos;
		scanf("%d%d", &x, &pos);
		--x;
		--pos;
		split(root, pos);
		Node *a = splitter->l;
		Node *b = splitter->r;
		split(b, 1);
		b = splitter->l;
		Node *c = splitter->r;
		if (b->x >= 0 && b->x != x) {
			printf("%d\n", -1);
			return 0;
		}
		if (b->x < 0 && used[x]) {
			printf("%d\n", -1);
			return 0;
		}
		used[x] = true;
		b->x = x;
		root = merge(b, merge(a, c));
	}
	dfs(root);
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (ans[i] < 0) {
			while (j < n && used[j]) {
				++j;
			}
			used[j] = true;
			ans[i] = j;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i] + 1);
	}
	printf("\n");
	return 0;
}
