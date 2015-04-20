#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

#define FNAME "dwarfs"
#define LL long long
#define ULL unsigned long long
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < n; i++)

int bad[300000], d1[300000], d2[300000], len1[300000], len2[300000], n, ans, u1, u2, x, y, max1;
vector <int> a[300000];
void dfs(int v, int p)
{
	d1[v] = d2[v] = 1;
	if (v == u2)
		bad[v] = 1;
	if (v != p)
		len1[v] = len1[p] + 1;
	forn(i, (int) a[v].size())
	{
		if (a[v][i] != p)
		{
			dfs(a[v][i], v);
			if (bad[a[v][i]])
			{
		//		printf("%d %d\n", v + 1, a[v][i] + 1);
				bad[v] = 1;
				len2[v] = len2[a[v][i]] + 1;
			}

		}
	}
	forn(i, (int) a[v].size())
	{
		if (a[v][i] == p)
			continue;
		if (bad[v] && !bad[a[v][i]])
		{
//			printf("%d %d\n", v + 1, a[v][i] + 1);
			if (v != u1 && v != u2)
				d2[v] = max(d2[v], d2[a[v][i]] + 1 + len2[v]);
			else if (v == u2)
				d2[v] = max(d2[v], d2[a[v][i]] + 1);
//			printf("%d %d\n", v + 1, a[v][i] + 1);			
            if (v != u2)
				d1[v] = max(d1[v], d1[a[v][i]] + 1 + len1[v]);
		}
		else if (!bad[v])
		{
			d2[v] = max(d2[v], d2[a[v][i]] + 1);
			d1[v] = max(d1[v], d1[a[v][i]] + 1);
		}
	}        

}

void dfs1(int v, int p)
{
		if (bad[v])
		{
		    max1 = max(max1, d1[p]);
//		    printf("%d %d %d\n", v + 1, p + 1, d1[p]);
		    if (v != u1)
				ans = max(ans, min(d2[v], max1));
		//	printf("%d %d %d %d\n", v + 1, d2[v], max1, bad[v]);
		}
	forn(i, (int) a[v].size())
	{
		if (a[v][i] != p)
				dfs1(a[v][i], v);
	}

}
int main()
{
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	scanf("%d", &n);
	forn(i, n - 1)
	{
		scanf("%d%d", &x, &y);
		x--, y--;
		a[x].pb(y);
		a[y].pb(x);
	}
	scanf("%d%d", &u1, &u2);
	u1--, u2--;
	d1[u1] = d2[u2] = 1;
	dfs(u1, u1);
	dfs1(u1, u1);
	//	puts("");

//	forn(i, n)
//	{
//		printf("%d %d %d %d\n", d1[i], d2[i], len1[i], len2[i]);
//		printf("%d\n", bad[i]);			
//	}
	printf("%d\n", ans);

	return 0;
}