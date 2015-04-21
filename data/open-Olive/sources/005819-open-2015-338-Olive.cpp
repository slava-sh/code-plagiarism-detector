#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 4000 * 1000 + 100;
int rmq[MAXN];
int id[MAXN];
int ad[MAXN];

struct sob
{
	int tm, id;
};

int db[MAXN], dbc = 0;
int ub[MAXN], ubc = 0;
int dl[MAXN], dr[MAXN], ul[MAXN], ur[MAXN];
int a[MAXN];

bool cmp(sob s1, sob s2)
{
	if (s1.tm < s2.tm) return true;
	if (s1.tm > s2.tm) return false;
	return ((s1.id < 0) && (s2.id > 0));
}

int lv, rv, val;
sob sb[MAXN];
int sbc = 0;

void create_rmq(int v, int l, int r)
{
	rmq[v] = ad[v] = 0, id[v] = l;
	if (l != r)
	{
		create_rmq(v * 2 + 1, l, (l + r) / 2);
		create_rmq(v * 2 + 2, (l + r) / 2 + 1, r);
	}
}

void modify_rmq(int v, int l, int r)
{
	if ((lv <= l) && (r <= rv))
	{
		ad[v] += val;
		rmq[v] += val;
		return;
	}
	int md = (l + r) / 2;
	if (lv <= md) modify_rmq(v * 2 + 1, l, md);
	if (rv > md) modify_rmq(v * 2 + 2, md + 1, r);
	if (rmq[v * 2 + 1] >= rmq[v * 2 + 2]) rmq[v] = rmq[v * 2 + 1] + ad[v], id[v] = id[v * 2 + 1];
	else rmq[v] = rmq[v * 2 + 2] + ad[v], id[v] = id[v * 2 + 2];
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		a[i] = n - a[i];
		if ((dbc == 0) || (a[i] < a[db[dbc - 1]])) db[dbc++] = i;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if ((ubc == 0) || (a[i] > a[ub[ubc - 1]])) ub[ubc++] = i;
	}
	reverse(ub, ub + ubc);
	int ans = 1, al = -2, ar = -2;
	create_rmq(0, 0, ubc - 1);
	for (int i = 0; i < n; i++)
	{
		int lg = 0, rg = dbc;
		while (lg < rg)
		{
			int md = (lg + rg) / 2;
			if (a[db[md]] <= a[i]) rg = md;
			else lg = md + 1;
		}
		dl[i] = lg;
		lg = -1, rg = dbc - 1;
		while (lg < rg)
		{
			int md = (lg + rg + 1) / 2;
			if (db[md] <= i) lg = md;
			else rg = md - 1;
		}
		dr[i] = lg;
		lg = 0, rg = ubc;
		while (lg < rg)
		{
			int md = (lg + rg) / 2;
			if (ub[md] >= i) rg = md;
			else lg = md + 1;
		}
		ul[i] = lg;
		lg = -1, rg = ubc - 1;
		while (lg < rg)
		{
			int md = (lg + rg + 1) / 2;
			if (a[ub[md]] >= a[i]) lg = md;
			else rg = md - 1;
		}
		ur[i] = lg;
		if ((dl[i] <= dr[i]) && (ul[i] <= ur[i]))
		{
			sb[sbc].tm =dl[i];
			sb[sbc].id = i + 1;
			sbc++;
			sb[sbc].tm = dr[i] + 1;
			sb[sbc].id = - (i + 1);
			sbc++;
		}
	}
	sort(sb, sb + sbc, cmp);
	for (int i = 0; i < sbc; i++)
	{
		int v;
		if (sb[i].id > 0) v = sb[i].id - 1, val = 1;
		else v = -sb[i].id - 1, val = -1;
		lv = ul[v], rv = ur[v];
		modify_rmq(0, 0, ubc - 1);
		if (rmq[0] > ans) ans = rmq[0], al = db[sb[i].tm], ar = ub[id[0]];
	}
	cout << al + 1 << " " << ar + 1 << endl;
	return 0;
}