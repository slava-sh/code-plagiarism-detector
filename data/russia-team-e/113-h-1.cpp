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

const int MAXN = 5010;
const int MAXM = 100010;
const int INF = (int)1e9;

int n, m, s, t, c, ind;
int color[MAXN], d[MAXN], used[MAXN], p[MAXN];
int M[MAXN][MAXN];

void go()
{
	for (int i = 0; i < n + 2; ++i)
		d[i] = INF, p[i] = -1;
	for (int i = 0; i < n; ++i)
		if (color[i] == 1)
			d[i] = 0;
	for (int i = 0; i < n; ++i)
	{
		int cur = -1;
		for (int j = 0; j < n; ++j)
		{
			if ((cur == -1 || d[j] < d[cur]) && !used[j])
				cur = j;
		}
		if (d[cur] == INF)
			break;
		for (int j = 0; j < n; ++j)
		{
			if (cur == j || used[j] || M[cur][j] == -1) continue;
			if (d[j] > d[cur] + M[cur][j])
			{
				d[j] = d[cur] + M[cur][j];
				p[j] = cur;
			}
		}
		used[cur] = true;
	}

	ind = -1;
	for (int i = 0; i < n; ++i)
	{
		if (color[i] == 2 && (ind == -1 || d[i] < d[ind]))
			ind = i;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> color[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			M[i][j] = M[j][i] = -1;
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> t >> c;
		M[s - 1][t - 1] = c;
		M[t - 1][s - 1] = c;
	}
	go();
	if (d[ind] == INF)
		cout << -1 << endl;
	else
	{
		int x = ind;
		while (p[x] != -1 && color[p[x]] != 1)
			x = p[x];
		cout << p[x] + 1 << " " << ind + 1 << " " << d[ind] << endl;
	}
}