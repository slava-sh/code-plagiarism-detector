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

#define FNAME "binary"
#define LL long long
#define ULL unsigned long long
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < n; i++)

int n, a[1005], z[1005], ans = 1, boo = 0, MOD = (int) 1e9 + 7, used[1005][1005], used1[1005], color = 0, boo0, boo1, col[1005], color2, d[1005], used2[1005][1005], bad[1005][1005], used5[1005];
vector <int> c[1005];

void dfs (int v)
{
	used1[v] = 1;
	c[color].pb(v);
	col[v] = color;
	for (int i = 0; i < n; i++)
		if (used1[i] == 0 && used[v][i])
			dfs(i);
}

void dfs2 (int v)
{
	used5[v] = 1;
	for (int i = 0; i < color; i++)
	{
		if (used5[i] == 1 && bad[v][i])
		{
			if (d[i] == d[v])
			{
				puts("0");
				exit(0);
			}
		}
		if (used5[i] == 0 && bad[v][i])
		{
			if (d[i] == d[v])
			{
				puts("0");
				exit(0);
			}
			d[i] = 3 - d[v];
			dfs2(i);
		}
	}
}

int main()
{
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &z[i]);
	if (z[0] != 0 && z[0] != -1)
	{
		puts("0");
		return 0;
	}
	for (int i = 0; i < n; i++)
		a[i] = -1;
	a[0] = 0;
	for (int i = 1; i < n; i++)
	{
		if (z[i] == -1)
			continue;
		if (z[i] > n - i)
		{
			puts("0");
			return 0;
		}
		if (z[i] == 0)
		{
			if (a[i] != -1 && a[i] != 1 - a[0])
			{
		    	puts("0");
		    	return 0;
			}
			if (a[i] == -1)
				a[i] = 1 - a[0];
		}
		for (int j = i; j < i + z[i]; j++)
		{
			if (a[j] != -1 && a[j] != a[j - i])
			{
		    	puts("0");
		    	return 0;
			}
			used[j][j - i] = 1;
			used[i - j][j] = 1;
		}
		if (i + z[i] != n)
		{
			if (a[z[i]] != -1 && a[i + z[i]] != -1 && a[z[i]] == a[i + z[i]])
			{
				puts("0");
				return 0;
			}
			if (a[z[i]] != -1)
				a[i + z[i]] = 1 - a[z[i]];
			if (a[i + z[i]] != -1)
				a[z[i]] = 1 - a[i + z[i]];
			if (a[z[i]] == -1 && a[i + z[i]] == -1)
			{
				used2[z[i]][i + z[i]] = 1;
				used2[i + z[i]][z[i]] = 1;
				//printf("%d %d\n", z[i], i + z[i]);
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (used1[i] == 0)
		{
			dfs(i);
			color++;
		}

		
	for (int i = 0; i < color; i++)
   	{
   		boo0 = 0;
   		boo1 = 0;
   		for (int j = 0; j < (int) c[i].size(); j++)
   		{
   		//	printf("%d ", c[i][j]);
   			if (a[c[i][j]] == 0)
   				boo0 = 1;
   			if (a[c[i][j]] == 1)
   				boo1 = 1;
   		}
   		//puts("");
   		if (boo0 * boo1 == 1)
   		{
   			puts("0");
   			return 0;
   		}
   		if (boo0)
   			d[i] = 1;
   		if (boo1)
   			d[i] = 2;
   		if (boo0 == 0 && boo1 == 0)
   			d[i] = 3;		
   	}
   	ans = 1;
   	for (int i = 0; i < n; i++)
   		for (int j = 0; j < n; j++)
   			if (used2[i][j])
   			{
   				bad[col[i]][col[j]] = 1;
   				bad[col[j]][col[i]] = 1;
   			}
   	/*printf("%d\n", color);
  	for (int i = 0; i < color; i++)
  	{
	  	for (int j = 0; j < color; j++)
	  		printf("%d ", bad[i][j]);
   		puts("");
   	}*/
   	for (int i = 0; i < color; i++)
   		if (bad[i][i])
   		{
   			puts("0");
   			return 0;
   		}
  	//for (int i = 0; i < color; i++)
	//	printf("%d\n", d[i]);
   	for (int i = 0; i < color; i++)
   		if (used5[i] == 0 && d[i] != 3)
   		{
   			dfs2(i);
			color2++;
		}
	for (int i = 0; i < color; i++)
   		if (used5[i] == 0 && d[i] == 3)
   		{
   			d[i] = 1;
   			dfs2(i);
			color2++;
			//printf("%d\n", ans);
			ans = (ans * 2) % MOD;
			//printf("%d\n", ans);
		}
	ans = (ans * 2) % MOD;
	printf("%d\n", ans);
	return 0;
}