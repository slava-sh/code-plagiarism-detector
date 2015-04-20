#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <string.h>
#include <set>


using namespace std;

int n, a, b, ans;
const int MAXN = 400100;
int f1[MAXN], f2[MAXN];
int F1[MAXN], F2[MAXN];

bool path[MAXN];
vector < vector < int > > g;

bool dfs(int v, int t, int p = -1)
{
	if (v == t)
	{
		path[t] = true;
		return true;
	}
	for (int i = 0; i < g[v].size(); ++i)
	{
		int to = g[v][i];
		if (to != p)
			if (dfs(to, t, v))
			{
				path[v] = true;
				return true;
			}
	}
	return false;
}

void df1(int v, int p = -1)
{
	F1[v] = f1[v] = max(f1[v], 1);
	int nx = -1;
	for (int i = 0; i < g[v].size(); ++i)
	{
		int to = g[v][i];
		if (to != p)
		{
			if (path[to] == false)
			{
				df1(to, v);
				if (!path[v] || p == -1)
					f1[v] = max(f1[v], f1[to] + 1);
				else
					if (p != -1)
						F1[v] = max(F1[v], f1[to] + 1 + f1[p]);
			}
			else
				nx = to;
		}
	}
	if(nx != -1 && nx != b - 1 && nx != p)
	{
		f1[nx] = f1[v] + 1;
		df1(nx, v);
	}
}

void df2(int v, int p = -1)
{
	F2[v] = f2[v] = max(f2[v], 1); 
	int nx = -1;
	for (int i = 0; i < g[v].size(); ++i)
	{
		int to = g[v][i];
		if (to != p)
		{
			if (path[to] == false)
			{
				df2(to, v);
				if(!path[v] || p == -1)
					f2[v] = max(f2[v], f2[to] + 1);
				else
					if (p != -1)
						F2[v] = max(F2[v], f2[to] + 1 + f2[p]);
			}
			else
				nx = to;
		}
	}
	if(nx != -1 && nx != a - 1 && nx != p)
	{
		f2[nx] = f2[v] + 1;
		df2(nx, v);
	}
	if(nx != -1)
		ans = max(ans, min(max(f2[v], F2[v]), max(f1[nx], F1[nx]))); 
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);
	cin >> n;
	g.resize(n + 10);
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	cin >> a >> b;
	dfs(a - 1, b - 1);
	df1(a - 1);
	memset(path, 0, sizeof(path));
	dfs(b - 1, a - 1);
	df2(b - 1);
	cout << ans << endl;
}