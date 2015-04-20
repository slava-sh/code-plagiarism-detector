#include<cstdlib>
#include<time.h>
#include<cstdio>
#include<stdio.h>
#include<map>
#include<ctime>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>

#define y1 google
#define INF 2147483647
#define fname "secure"

using namespace std;

const int N = 6000, M = 100500;
int n, m, col[N], x[M], y[M], z[M], ans = INF, d[N], i, j, pr[N], p, t;

int main()	{
	srand(time(NULL));
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);
	scanf("%d%d", &n, &m);
	t = clock();
	for (i = 1; i <= n; i++)	{
		scanf("%d", &col[i]);
		if (col[i] != 1)
			d[i] = INF;
	}
	for (i = 1; i <= m; i++)
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
	for (t = 1; t <= n; t++)
		for (i = 1; i <= m; i++)	{
			if (col[x[i]] == 1 && col[y[i]] != 1)
				if (d[y[i]] > d[x[i]] + z[i])   {
                    d[y[i]] = d[x[i]] + z[i];
                    pr[y[i]] = pr[x[i]];
                    if (pr[x[i]] == 0)
                        pr[y[i]] = x[i];
				}
			if (col[x[i]] != 1 && col[y[i]] == 1)
				if (d[x[i]] > d[y[i]] + z[i])   {
                    d[x[i]] = d[y[i]] + z[i];
                    pr[x[i]] = pr[y[i]];
                    if (pr[y[i]] == 0)
                        pr[x[i]] = y[i];
				}
			if (col[x[i]] != 1 && col[y[i]] == 0 && d[y[i]] != INF)
				if (d[x[i]] > d[y[i]] + z[i])   {
                    		d[x[i]] = d[y[i]] + z[i];
                    		pr[x[i]] = pr[y[i]];
                            if (pr[y[i]] == 0)
                                pr[x[i]] = y[i];
				}
			if (col[x[i]] == 0 && col[y[i]] != 1 && d[x[i]] != INF)
				if (d[y[i]] > d[x[i]] + z[i])   {
                    		d[y[i]] = d[x[i]] + z[i];
                    		pr[y[i]] = pr[x[i]];
                    		if (pr[x[i]] == 0)
                                    pr[y[i]] = x[i];
				}
		  if (((double)(clock())-t) / CLOCKS_PER_SEC >= 1.95) goto w; 
		}
		

		w:;
	for (i = 1; i <= n; i++)
		if (col[i] == 2)
			if (d[i] < ans) {
                p = i;
                ans = d[i];
            }
	if (ans == INF)
		printf("-1");
	else
		printf("%d %d %d", pr[p], p, ans);
	return 0;
}

