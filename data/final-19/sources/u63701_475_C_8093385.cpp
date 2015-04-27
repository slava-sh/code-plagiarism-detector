#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<string>
#include<stdio.h>

#define forn(i, n)	for(int i = 0; i < n; i++)
#define ll long long

using namespace std;

const int md = 1000000007;
const int maxn = 1100;
const ll inf = 2020202020202020202LL;
ll s;
int n, m, a[maxn][maxn], c[maxn][maxn], clr[maxn][maxn], ans;
char x;
void rct(int l, int r, int cx, int cy)
	{
		forn(i, n)
			forn(j, m)
				clr[i][j] = 0;
		for (int i = cx; i < cx + l; i++)
			for (int j = cy; j < cy + r; j++)
				clr[i][j] = 1;
		int f = 1;
		while (f)
			{
				f = 0;
				if ((r + cy) < m)
				if (a[cx][r + cy] == 1)
					{
						for (int i = cx; i < cx + l; i++)
							clr[i][r + cy] = 1;
						cy++;
						f = 1;
					}
				if (((l + cx) < n) && (f == 0))
				if (a[l + cx][cy] == 1)
					{
						for (int j = cy; j < cy + r; j++)
							clr[l + cx][j] = 1;
						cx++;
						f = 1;
					}
			}
		forn(i, n)
			forn(j, m)
				if (a[i][j] != clr[i][j])
					ans = 0;
		if (ans == 1)
			if (s > l * r)
				s = l * r;
	}
void ch()
	{
		ans = 1;
		int tx = -1, ty = -1, tx2 = -1, ty2, tx3 = -1, ty3;
		forn(i, n)
			forn(j, m)
				if ((tx == -1) && (a[i][j] == 1))
					{
						tx = i;
						ty = j;
					}
		a[tx][m] = 0;
		a[n][ty] = 0;
		for (int j = ty; j <= m; j++)
			if (tx2 == -1)
			if (a[tx][j] == 0)
				{
					tx2 = tx;
					ty2 = j - 1;
				}
		for (int i = tx; i <= n; i++)
			if (tx3 == -1)
			if (a[i][ty] == 0)
				{
					tx3 = i - 1;
					ty3 = ty;
				}
		for (int i = tx; i <= tx3; i++)
			for (int j = ty; j <= ty2; j++)
				if (a[i][j] == 0)
					ans = 0;
		int d = 1;
		for (int i = tx; i <= tx3; i++)
			if (a[i][ty2 + 1] == 1)
				if (d < (tx3 - i + 1))
					d = tx3 - i + 1;
		rct(d, ty2 - ty + 1, tx, ty);
	}
int main()	
{
	s = inf;
	ans = 1;
	cin>>n>>m;
	forn(i, n)
		forn(j, m)
			{
				cin>>x;
				if (x == 'X')
					a[i][j] = 1;
				else
					a[i][j] = 0;
				c[j][i] = a[i][j];
			}
	ch();
	swap(n, m);
	forn(i, n)
		forn(j, m)
			{
				a[i][j] = c[i][j];
		}
	ans = 1;
	ch();
	if (s != inf)
		cout<<s;
	else
		cout<<"-1";
	return 0;
}
