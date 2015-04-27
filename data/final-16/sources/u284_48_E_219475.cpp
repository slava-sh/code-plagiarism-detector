//Solution by Ali-Amir Aldan
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define pb push_back
#define mp make_pair
#define S second
#define F first

typedef long long ll;
typedef double ld;

using namespace std;

int h, t, R, n, m;
bool win[999][999], cycle[999][999];
int d[999][999], minval[999][999], maxval[999][999];
int hg[999], tg[999];
int qx[9999999], qy[9999999];

void dfs (int heads, int tails)
{
//	printf ("here heads = %d tails = %d\n", heads, tails);
	if (heads + tails > R) return;
	if (heads + tails == 0) return;
	if (d[heads][tails]) return;
	d[heads][tails] = 1;

	int to = min (heads, n), v, nh, nt;

	for (int i = 0; i < to; i++)
	{
		dfs (heads - i - 1 + hg[i], tails + tg[i]);
		nh = heads - i - 1 + hg[i]; nt = tails + tg[i];
		if (nh + nt > R)
			maxval[heads][tails] = max (maxval[heads][tails], 1);
		else
		{
			win[heads][tails] |= win[nh][nt];
			cycle[heads][tails] |= cycle[nh][nt];
			if (d[nh][nt] == 1) cycle[nh][nt] = 1;
			maxval[heads][tails] = max (maxval[heads][tails], maxval[nh][nt] + 1);
		}
	}

	to = n + min (tails, m);

	for (int i = n; i < to; i++)
	{
		dfs (heads + hg[i], tails - i + n - 1 + tg[i]);
		nh = heads + hg[i]; nt = tails + tg[i] - i + n - 1;
		if (nh + nt > R)
			maxval[heads][tails] = max (maxval[heads][tails], 1);
		else
		{   
			win[heads][tails] |= win[nh][nt];
			cycle[heads][tails] |= cycle[nh][nt];
			if (d[nh][nt] == 1) cycle[nh][nt] = 1;
			maxval[heads][tails] = max (maxval[heads][tails], maxval[nh][nt] + 1);
		}
	}

//	printf ("left %d %d\n", heads, tails);
	d[heads][tails] = 2;
}

int main ()
{
	#ifndef ONLINE_JUDGE
		freopen ("input", "r", stdin);
		freopen ("output", "w", stdout);
	#endif

	scanf ("%d%d%d", &h, &t, &R);
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d%d", &hg[i], &tg[i]);

	scanf ("%d", &m);
	for (int i = n; i < n + m; i++)
		scanf ("%d%d", &hg[i], &tg[i]);

	win[0][0] = 1;
	dfs (h, t);

	if (win[h][t])
	{
		printf ("Ivan\n");
		memset (d, 127, sizeof (d));
		d[0][0] = 0;

		int r = 1;

		for (int l = 0, x, y; l < r; l++)
		{
		 	for (int i = 0; i < n; i++)
		 	{
				x = qx[l] + i + 1 - hg[i]; y = qy[l] - tg[i];
				if (x < 0 || y < 0 || i + 1 > x || x + y > R || d[x][y] < 1000000000) continue;
				d[x][y] = d[qx[l]][qy[l]] + 1;
				qx[r] = x; qy[r++] = y;
		 	}
		 	for (int i = n; i < n + m; i++)
		 	{
		 	 	x = qx[l] - hg[i]; y = qy[l] + i - n + 1 - tg[i];
				if (x < 0 || y < 0 || i - n + 1 > y || x + y > R || d[x][y] < 1000000000) continue;
				d[x][y] = d[qx[l]][qy[l]] + 1;
				qx[r] = x; qy[r++] = y;
		 	}
		}
		printf ("%d\n", d[h][t]);

	}
	else
	if (cycle[h][t])
		puts ("Draw");
	else
		printf ("Zmey\n%d\n", maxval[h][t]);

	return 0;
}
