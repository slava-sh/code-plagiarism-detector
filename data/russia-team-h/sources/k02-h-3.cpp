#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <cstdio>
#include <cmath>

using namespace std;

#define maxn 400200


set < pair <long long, int> > s;

int x, y, i, j, from, odd, even, n, m, sz, u, v, c;
int clr[maxn], data[maxn], nxt[maxn], w[maxn], st[maxn];
long long  d[maxn], inf, ans;



void add(int u, int v, int c)
{
	++sz;
	data[sz] = v;
	nxt[sz] = st[u];
	w[sz] = c;
	st[u] = sz;
}           

int main()
{

	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);

        scanf("%d%d", &n, &m);

        for (i = 1; i <= n; i++)
        {
        	scanf("%d", &clr[i]);
        	if (clr[i] == 1)
        		odd++;
		else
		if (clr[i] == 2)
			even++;
        }


	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &c);
		//if (clr[u] != clr[v] || (clr[u] == 0 && clr[v] == 0))
		//{
			add(u, v, c);
			add(v, u, c);
//		}
	}

	inf = 1000*1000*1000;
	inf *= 1000;
	from = 1;
	if (even < odd)
		from = 2;

	ans = inf;
	

	for (i = 1; i <= n; i++)
		if (clr[i] == from)
		{
			for (j = 1; j <= n; j++)
				d[j] = inf;
			d[i] = 0;
			s.insert(make_pair(d[i], i));
			while (!s.empty())
			{
				u = s.begin() -> second;
				s.erase(s.begin());
				j = st[u ];
				while (j != 0)
				{
					int v = data[j];
					if (d[v] > d[u] + w[j])
					{
						s.erase(make_pair(d[v], v));
						d[v] = d[u] + w[j];
						s.insert(make_pair(d[v], v));
					}
					j = nxt[j];
				}
			}
			
			for (j = 1; j <= n; j++)
				if (clr[j] != from && clr[j] != 0)
					if (d[j] < ans)
					{
						ans = d[j];
						x = i;
						y = j;
					}
		}
	if (ans != inf)
		printf("%d %d %d", x, y, ans);
	else
		printf("%d", -1);

	return 0;
}