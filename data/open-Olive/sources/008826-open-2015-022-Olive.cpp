#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAX = 15e3 + 11;

int n, a[MAX], inv[MAX][MAX];

int tree[4 * MAX];

bool was[MAX];

int query(int v, int l, int r, int ql, int qr)
{
	if(l == ql && r == qr)
		return tree[v];
	if(l >= qr || r <= ql)
		return 0;
	int mid = (l + r) / 2;
	int left = query(2 * v + 1, l, mid, ql, min(qr, mid));
	int right = query(2 * v + 2, mid, r, max(ql, mid), qr);
	return left + right;
}

void update(int v, int l, int r, int d, int x)
{
	if(d < l || d >= r)
		return;
	if(l == r - 1)
	{
		tree[v] = x;
		return;
	}
	int mid = (l + r) / 2;
	update(2 * v + 1, l, mid, d, x);
	update(2 * v + 2, mid, r, d, x);
	tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	scanf("%d", &n);
	int bad = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		inv[i][0] = i - 1;
		inv[i][1] = query(0, 0, MAX, 1 + 1, n + 1);
		int gg = i - 1;
		if(was[1])
			gg--;
		for(int j = 2; j <= n; j++)
		{
			/*if(!was[j])
				inv[i][j] = query(0, 0, MAX, j + 1, n + 1);
			else
				inv[i][j] = inv[i][j - 1] - 1;*/
			if(was[j])
				gg--;
			inv[i][j] = max(gg, 0);
		}
		update(0, 0, MAX, a[i], 1);
		bad += inv[i][a[i]];
		was[a[i]] = true;
	}
	int ind1 = -1, ind2 = -1;
	int ans = bad;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			int good = bad - inv[i][a[i]] + inv[j][a[i]];
			good = good - inv[j][a[j]] + inv[i][a[j]];
			if(ans > good)
			{
				ans = good;
				ind1 = i;
				ind2 = j;
			}
		}
	}
	printf("%d %d", ind1, ind2);
	return 0;
}
