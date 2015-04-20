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

   int u,v,d[200001],D[200001],i,s,n,m,w,a[200001],mn = INF, S, F;
   vector<int> q[200001],W[200001];
   bool was[200001];

int main()	{
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);

	cin>>n>>m;

	for(i = 1; i <= n; i++) cin>>a[i];

	for(i = 1; i <= m; i++)
	{
	    cin>>u>>v>>w;
	    q[u].push_back(v);
	    q[v].push_back(u);
	    W[u].push_back(w);
	    W[v].push_back(w);
	}

	for(s = 1; s <= n; s++)
	 {
	     if (a[s] == 1)
        {
            u = s;
            for(i = 1; i <= n; i++) was[i] = false, D[i] = INF, d[i] = INF;
            d[u] = 0;
            while(true)
        {
            was[u] =true;
          for(i = 0; i < q[u].size(); i++)
          {
               v = q[u][i];
               w = W[u][i];
               if (d[u] + w <= d[v] && was[v] == false) d[v] = d[u] + w;
          }
          D[u] = d[u];
          d[u] = INF;
          for(i = 1; i <= n; i++)
          if (d[i] < d[u]) u = i;
          if (d[u] == INF) break;
        }
        for(i = 1; i <= n; i++)
            if (a[i] == 2)
           {
                 if (D[i] < mn) { mn = D[i]; S = s; F = i; }
           }
        }
	 }
	 if (mn == INF) cout<<-1; else
	 cout<<S<<" "<<F<<" "<<mn;

	return 0;
}

