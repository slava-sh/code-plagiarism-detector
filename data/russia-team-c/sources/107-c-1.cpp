#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> anspath;
vector <int> tekpath;

const int MAXN = 200001;
vector <int> e[MAXN];
int d[MAXN];
int v0, w0;
int ap[MAXN];

void dfs(int v, int p)
{
	tekpath.push_back(v);
	if ((v == w0) && (p != v)) anspath = tekpath;
	for (int i = 0; i < e[v].size(); i++)
	{
		if (e[v][i] != p)
		{
			d[e[v][i]] = d[v] + 1;
			dfs(e[v][i], v);
		}
	}
	tekpath.pop_back();
}

int mxx = 0;

void dfs2(int v, int p, int d)
{
	mxx = max(mxx, d);
	tekpath.push_back(v);
	if ((v == w0) && (p != v)) anspath = tekpath;
	for (int i = 0; i < e[v].size(); i++)
	{
		if ((e[v][i] != p) && (ap[e[v][i]] == -1))
		{
			dfs2(e[v][i], v, d + 1);
		}
	}
	tekpath.pop_back();
}

int rs1[MAXN];

int main()
{
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i <= n; i++) ap[i] = -1;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	cin >> v0 >> w0;
	int a1 = 0, a2 = 0;
	d[v0] = 0;
	dfs(v0, v0);
	for (int i = 0; i <(int)anspath.size(); i++) ap[anspath[i]] = i;
	for (int i = 0; i <(int)anspath.size(); i++)
	{
		mxx = 0;
		dfs2(anspath[i], anspath[i], 0);
		ap[anspath[i]] = mxx;
	}
	rs1[0] = ap[anspath[0]];
	for (int i = 1; i + 1 <(int)anspath.size(); i++)
	{
		rs1[i] = max(rs1[i - 1], i + ap[anspath[i]]);
	}
	int res = 0, cur = 0;
	for (int i = (int)anspath.size() - 1; i > 0; i--)
	{
		cur = max(cur, ap[anspath[i]] + ((int)anspath.size() - 1 - i));
		res = max(res, min(cur, rs1[i - 1]));
	}
	cout << res + 1 << endl;
	return 0;
}
