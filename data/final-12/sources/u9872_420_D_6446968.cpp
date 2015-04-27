#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <functional>
#include <cstring>
#include <set>
#include <map>
#include <ctime>
#include <cassert>
#include <cinttypes>

using namespace std;

const int N = 1000100;

int n, m;
int num[N];
int x[N], y[N];
bool used[N];
int f[N];

int mrand()
{
	return rand() ^ (rand() << 15);
} 

struct node
{
	int val;
	int pos;
	int sz;
	int l, r;
	int y;

	node() : val(0), pos(-1), sz(1), l(0), r(0), y(mrand()) { }
} tree[N];

void tupdate(int t)
{
	if (!t) return;
	tree[t].sz = 1;
	const int l = tree[t].l;
	const int r = tree[t].r;
	if (l)
		tree[t].sz += tree[l].sz;
	if (r)
		tree[t].sz += tree[r].sz;

}

inline int merge(int l, int r)
{
	if (!l) return r;
	if (!r) return l;
	if (tree[l].y > tree[r].y)
	{
		tree[l].r = merge(tree[l].r, r);
		tupdate(l);
		return l;
	} else {
		tree[r].l = merge(l, tree[r].l);
		tupdate(r);
		return r;
	}
}

inline void split(int t, int sz, int& l, int &r)
{
	if (!t)
	{
		l = r = 0;
		return;
	}
	const int tl = tree[t].l;
	const int tr = tree[t].r;
	const int tl_sz = tl ? tree[tl].sz : 0;
	if (tl_sz >= sz)
	{
		r = t;
		split(tl, sz, l, tree[t].l);
	} else {
		l = t;
		split(tr, sz - tl_sz - 1, tree[t].r, r);
	}
	tupdate(l);
	tupdate(r);
}

void update(int i, int val)
{
	for (; i < N; i = (i | (i + 1)))
		f[i] += val;
}

int sum(int i)
{
	int ret = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1)
		ret += f[i];
	return ret;
}

void read()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
		scanf("%d %d", x + i, y + i);
}

inline void dfs(int u)
{
	if (!u) return;
	if (tree[u].val != -1)
		num[tree[u].pos] = tree[u].val;
	dfs(tree[u].l);
	dfs(tree[u].r);
}

bool go()
{
	int root = 0;
	for (int i = 1; i <= n; ++i)
	{
		tree[i].val = -1;
		tree[i].l = tree[i].r = 0;
		tree[i].sz = 1;
		tree[i].pos = i;
		root = merge(root, i);
	}
	for (int i = 0; i < m; ++i)
	{
		int l, r, mid;
		split(root, y[i] - 1, l, r);
		split(r, 1, mid, r);
		if (tree[mid].val != -1 && tree[mid].val != x[i])
			return false;
		if (tree[mid].val == -1 && used[x[i]])
			return false;
		tree[mid].val = x[i];
		used[x[i]] = true;
		l = merge(mid, l);
		root = merge(l, r);
	}
	dfs(root);
	for (int i = 1, j = 1; i <= n; ++i)
	{
		if (num[i]) continue;
		while (j < n && used[j])
			++j;
		if (j == n + 1) return false;
		num[i] = j;
		++j;
	}
	return true;
}

bool check()
{
	return true;
	int root = 0;
	for (int i = 1; i <= n; ++i)
	{
		tree[i].val = num[i];
		tree[i].l = tree[i].r = 0;
		tree[i].sz = 1;
		root = merge(root, i);
	}
	for (int i = 0; i < m; ++i)
	{
		int l, r, mid;
		split(root, y[i] - 1, l, r);
		split(r, 1, mid, r);
		if (tree[mid].val != x[i])
			return false;
		l = merge(mid, l);
		root = merge(l, r);
	}
	return true;
}

void print()
{
	for (int i = 1; i <= n; ++i)
		printf("%d ", num[i]);
	printf("\n");
}

int main()
{
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	read();
	if (go() && check())
		print();
	else
		cout << -1 << endl;
	return 0;
}