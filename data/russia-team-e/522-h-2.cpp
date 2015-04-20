#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cassert>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define sqr(x) ((x) * (x))
#define forn(i, n) for (int i = 0; i < n; i++)

const int INF = (int)1e9;
int ans = INF, ansa, ansb;

void upd_ans(int len, int a, int b)
{
	if (len < ans)
	{
		ans = len;
		ansa = a;
		ansb = b;
	}
}

vector<bool> u;
vector<vector<pair<int, int> > > g;
vector<int> color;

bool dfs(int v, int tmp)
{
	u[v] = true;
	if (color[v] == 1 - tmp)
		return true;
	for (int i = 0; i < sz(g[v]); i++)
	{
		int to = g[v][i].fr;
		if (u[to])
			continue;
		if (dfs(to, tmp))
			return true;
	}
	return false;
}

int main()
{
	freopen("secure.in", "rt", stdin);
	freopen("secure.out", "wt", stdout);
	
	int n, m;
	cin >> n >> m;
	color.resize(n);
	int cnt1 = 0, cnt2 = 0;
	forn(i, n)
	{
		cin >> color[i];
		color[i]--;
		if (color[i] == 0)
			cnt1++;
		if (color[i] == 1)
			cnt2++;
	}
	int tmp;
	vector<int> start;
	if (cnt1 <= cnt2)
	{
		tmp = 0;
		forn(i, n)
			if (color[i] == 0)
				start.pb(i);
	}
	if (cnt1 > cnt2)
	{
		tmp = 1;
		forn(i, n)
			if (color[i] == 1)
				start.pb(i);
	}
	g.resize(n);
	forn(i, m)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		g[a].pb(mp(b, c));
		g[b].pb(mp(a, c));
	}
	for (int z = 0; z < sz(start); z++)
	{
		int s = start[z];
		u.assign(n, false);
		if (!dfs(s, tmp))
			continue;
		vector<int> d(n, INF);
		set<pair<int, int> > q;
		d[s] = 0;
		q.insert(mp(0, s));
		while (!q.empty())
		{
			int v = q.begin() -> sc;
			if (color[v] == 1 - tmp)
			{
				upd_ans(q.begin() -> fr, s, v);
				break;
			}
			q.erase(q.begin());
			for (int i = 0; i < sz(g[v]); i++)
			{
				int to = g[v][i].fr;
				int len = g[v][i].sc;
				if (d[v] + len < d[to])
				{
					q.erase(mp(d[to], to));
					d[to] = d[v] + len;
					q.insert(mp(d[to], to));
				}
			}
		}
	}
	if (ans == INF)
		cout << -1;
	else
	{
		if (tmp == 1)
			swap(ansa, ansb);
		cout << ansa + 1 << ' ' << ansb + 1 << ' ' << ans;
	}
}