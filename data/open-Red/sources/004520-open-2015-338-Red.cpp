#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <climits>
#include <queue>
#include <sstream>
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 400001;

vector <int> e[MAXN];

int a[MAXN], b[MAXN], t[MAXN];
int lg[MAXN], rg[MAXN];

int es[MAXN];
int f[MAXN];
int q[MAXN], qb, qe;
vector <int> p[MAXN];
int cm;

void ad(int vl, int nd)
{
	f[vl] = nd;
	q[qe++] = vl;
}

inline int get_p(int id, int v)
{
	int cr = v;
	while (f[cm - e[id][cr]] != MAXN)
	{
		cr = p[id][cr];
	}
	int cr2 = v, cr3;
	while (cr2 != cr)
	{
		cr3 = p[id][cr2];
		p[id][cr2] = cr;
		cr2 = cr3;
	}
	return cr;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, d;
	scanf("%d%d%d", &n, &m, &d);
	cm = 2 * m - 1;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a[i], &b[i], &t[i]);
		a[cm - i] = b[i], b[cm - i] = a[i], t[cm - i] = t[i];
		e[a[i]].push_back(cm - i);
		e[b[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		es[i] = e[i].size();
		e[i].push_back(-1);
		p[i].resize(es[i] + 1);
		int cr = 0;
		for (int j = 0; j < es[i];  j++)
		{
			while ((t[e[i][cr]] <= t[e[i][j]] + d) && (cr < es[i]))
			{
				lg[e[i][cr]] = j;
				cr++;
			}
			rg[e[i][j]] = cr - 1;
		}
	}
	int quest;
	scanf("%d", &quest);
	for (int qid = 0; qid < quest; qid++)
	{
		qb = 0, qe = 0;
		for (int i = 0; i <= cm + 1; i++) f[i] = MAXN;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= es[i]; j++) p[i][j] = j;
		}
		int stt, fin;
		scanf("%d%d", &stt, &fin);
		for (int i = 0; i < es[stt]; i++)
		{
			ad(cm - e[stt][i], 1);
		}
		while (qb < qe)
		{
			int v = q[qb++];
			int ver = b[v];
			if (ver == stt) continue;
			int stc = get_p(ver, lg[v]);
			int cur;
			for (cur = stc; cur <= rg[v]; cur++)
			{
				if (f[cm - e[ver][cur]] != MAXN) break;
				ad(cm - e[ver][cur], f[v] + 1);
			}
			for (int i = stc; i < cur; i++) p[ver][i] = p[ver][cur];
		}
		int ans = MAXN;
		for (int i= 0; i < es[fin]; i++)
		{
			ans = min(ans, f[e[fin][i]]);
		}
		if (ans == MAXN) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}