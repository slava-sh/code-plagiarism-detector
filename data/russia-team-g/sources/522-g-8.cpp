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
const int MAXN = 100;

int dx[6] = {3, 0, 1, 2, 4, 5};
int dy[6] = {4, 1, 5, 3, 2, 0};

int slow(int n, int m)
{
	int d[MAXN][MAXN][6];
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			for (int k = 0; k < 6; k++)
				d[i][j][k] = INF;
	d[0][0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 6; k++)
			{
				int i1 = i + 1;
				int j1 = j;
				if (i1 != n)
				{
				int k1 = dy[k];
				int tmp = 0;
				if (k1 == 2)
					tmp++;
				d[i1][j1][k1] = min(d[i1][j1][k1], d[i][j][k] + tmp);
				int i1 = i;
				int j1 = j + 1;
				}
				if (j1 != m)
				{
				int k1 = dx[k];
				int tmp = 0;
				if (k1 == 2)
					tmp++;
				d[i1][j1][k1] = min(d[i1][j1][k1], d[i][j][k] + tmp);
				}
			}
	int ans = INF;
	for (int k = 0; k < 6; k++)
		ans = min(ans, d[n - 1][m - 1][k]);
	return ans;
}

int main()
{
	freopen("prizes.in", "rt", stdin);
	freopen("prizes.out", "wt", stdout);
	
	int n, m;
	cin >> n >> m;
	//cout << slow(n, m);
	if (n > m)
		swap(n, m);
	if (n == 1)
		cout << (m + 1) / 4;
	else
		cout << (n + 1) / 4;
}