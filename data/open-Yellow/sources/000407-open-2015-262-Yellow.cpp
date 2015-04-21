//#include "stdafx.h"
//#pragma comment(linker, "/STACK:67108864")
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <string>
#include <memory.h>

using namespace std;

struct segment_tree
{
	struct node
	{
		int pref;
		int diff;
		int suff;
	} t[400010];

	int *a;
	int n;

	segment_tree(int *a, int n) : a(a), n(n)
	{
		build(1, 0, n - 1);
	}

	void build(int v, int tl, int tr)
	{
		/*if (tl > tr)
		{
			t[v].diff = -1;
			return;
		}*/

		if (tl == tr)
		{
			t[v].pref = t[v].suff = a[tl];
			t[v].diff = 1;
			return;
		}

		int tm = (tl + tr) >> 1;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);

		t[v].diff = t[v * 2].diff + t[v * 2 + 1].diff;
		t[v].pref = t[v * 2].pref;
		t[v].suff = t[v * 2 + 1].suff;
		if (t[v * 2].suff == t[v * 2 + 1].pref) t[v].diff--;
	}

	int get_ans()
	{
		return t[1].diff;
	}

	void update(int v, int tl, int tr, int x, int val)
	{
		if (tl == tr)
		{
			t[v].diff = 1;
			t[v].pref = t[v].suff = val;
			return;
		}

		int tm = (tl + tr) >> 1;
		if (x <= tm)
			update(v * 2, tl, tm, x, val);
		else
			update(v * 2 + 1, tm + 1, tr, x, val);

		t[v].diff = t[v * 2].diff + t[v * 2 + 1].diff;
		t[v].pref = t[v * 2].pref;
		t[v].suff = t[v * 2 + 1].suff;
		if (t[v * 2].suff == t[v * 2 + 1].pref) t[v].diff--;
	}

	void update(int x, int val)
	{
		update(1, 0, n - 1, x, val);
	}
};

int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, a[100000];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	segment_tree tr(a, n);

	int q, p, c;
	scanf("%d", &q);

	while (--q >= 0)
	{
		scanf("%d%d", &p, &c);
		tr.update(p - 1, c);
		printf("%d\n", tr.get_ans());
	}

	return 0;
}