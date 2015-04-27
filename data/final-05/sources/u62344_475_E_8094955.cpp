#include <cmath>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <bitset>
#include <memory.h>
#include <functional>
#include <queue>
#include <fstream>
#include <ctime>
#include <deque>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <cctype> 
#include <numeric>
#include <iomanip>
#include <assert.h>
using namespace std;
#define sqr(_) ((_)*(_))

typedef long long LL;

typedef pair<int, int> Pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int)(x).size())

const int MAXN = 2000 + 10;

int n, m, N, Tohka, cur, f[MAXN], st[MAXN], size[MAXN], cnt[MAXN], h[MAXN], DFN[MAXN], Low[MAXN];
struct Graph
{
	int id, next, flag;
}g[MAXN * MAXN];
vector<int> e[MAXN];
int idx, stk[MAXN], top, s, t;

void Add(int tot, int x, int y)
{
	g[tot].id = y, g[tot].next = st[x], st[x] = tot, g[tot].flag = 1;
}
void Tarjan(int x, int fa)
{
	DFN[x] = Low[x] = ++idx;
	stk[++top] = x;
	for (int i = st[x]; i != -1; i = g[i].next)
		if (i != fa)
			if (!DFN[g[i].id])
				Tarjan(g[i].id, i ^ 1),
				Low[x] = min(Low[x], Low[g[i].id]);
			else
			Low[x] = min(Low[x], DFN[g[i].id]);
	if (Low[x] >= DFN[x])
	{
		for (++N; stk[top] != x; f[stk[top]] = N, ++cnt[N], --top);
		f[x] = N; --top, ++cnt[N];
		cur += sqr(cnt[N]);
	}
}
void DFS(int x, int fa)
{
	size[x] = cnt[x];
	for (int i = 0; i < SZ(e[x]); ++i)
		if (e[x][i] != fa)
			DFS(e[x][i], x),
			size[x] += size[e[x][i]];
	s += (size[x] - cnt[x]) * cnt[x];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
	
	scanf("%d%d", &n, &m);
	memset(st, -1, sizeof(st));
	for (int i = 1; i <= m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		Add(i * 2, x, y);
		Add(i * 2 + 1, y, x);
	}
	Tarjan(1, 0);
	for (int i = 1; i <= n; ++i)
		for (int j = st[i]; j != -1; j = g[j].next)
			if (f[i] != f[g[j].id])
				e[f[i]].pb(f[g[j].id]);
	for (int i = 1; i <= N; ++i)
	{
		s = 0, t = 0;
		DFS(i, 0);
		memset(h, 0, sizeof(h));
		h[0] = 1;
		for (int j = 0; j < SZ(e[i]); ++j)
		{
			for (int k = n - cnt[i]; k >= size[e[i][j]]; --k)
				h[k] |= h[k - size[e[i][j]]];
		}
		for (int k = 1; k <= n - cnt[i]; ++k)
			t = max(t, h[k] * k * (n - cnt[i] - k));
		Tohka = max(Tohka, cur + s + t);
	}
	cout << Tohka << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

