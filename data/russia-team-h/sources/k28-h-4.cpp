#include<cstdlib>
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

   int u,v,d[2000001],D[20001],i,s,n,m,w,a[20001],mn = INF, S, F,pos[2000001],sz,kol1,kol2;
   vector<int> q[200001],W[200001];
   bool was[200001];

   void update(int x)
{
      x /= 2;
      while(x > 0)
      {
            if (d[x*2] < d[x*2+1]) {pos[x] = pos[x*2]; d[x] = d[x*2];} else
            pos[x] = pos[x*2+1], d[x] = d[x*2+1];
            x /= 2;
      }
}
int main()	{
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);
	scanf("%d%d", &n, &m);
	//cin>>n>>m;
	sz = 1;
	while(sz < n) sz *= 2;

	for(i = 1; i <= n; i++)
	{
	    cin>>a[i], pos[i+sz-1] = i;
	    if (a[i] == 1) kol1++; else kol2++;
	}
	if (kol2 < kol1)
	{
	   for(i = 1; i <= n; i++)
	   if (a[i] == 1) a[i] = 2; else a[i] = 1;
	}

	for(i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
	    //cin>>u>>v>>w;
	    q[u].push_back(v);
	    q[v].push_back(u);
	    W[u].push_back(w);
	    W[v].push_back(w);
	}

	for(i = n+sz; i < sz * 2; i++) d[i] = INF, update(i);

	for(s = 1; s <= n; s++)
	 {
	     if (a[s] == 1)
        {
            u = s;
            for(i = 1; i <= n; i++) was[i] = false, D[i] = INF;
            d[u+sz-1] = 0;
            while(true)
        {
            was[u] =true;
          for(i = 0; i < q[u].size(); i++)
          {
               v = q[u][i];
               w = W[u][i];
               if (d[u+sz-1] + w <= d[v+sz-1] && was[v] == false) d[v+sz-1] = d[u+sz-1] + w, update(v+sz-1);
          }
          D[u] = d[u+sz-1];
          d[u+sz-1] = INF;
          update(u+sz-1);
          u = pos[1];
          if (d[u+sz-1] == INF) break;
        }
        for(i = 1; i <= n; i++)
            if (a[i] == 2)
           {
                 if (D[i] < mn) { mn = D[i]; S = s; F = i; }
           }
        }
	 }
	 if (mn == INF) printf("-1");//cout<<-1;
	 else
	 {
	    if (kol2 < kol1) swap(S,F);
	    printf("%d %d %d", S, F, mn);
	    //cout<<S<<" "<<F<<" "<<mn;
	 }
	return 0;
}

