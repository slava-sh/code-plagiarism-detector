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
#define fname "sochi"

using namespace std;

   long long i,n,d,a[200001],now,b,mx,l,r;
   bool was;

int main()	{
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);

	cin>>n>>d;
	for(i = 1; i <= n; i++)
	{
	     cin>>a[i];
	}
	sort(a+1,a+n+1);
	mx = a[n];
	l = a[n]; r = a[n];
	now = a[n];
	for(i = n-1; i >= 1; i--)
	{
	    if (now-d <= 0 || a[i] <= 0) break;
	    if (l <= r)
	    {
	         now -= d;
	         r -= d;
	         if (r < d) break;
	         r = a[i] - d;
	         if (was == false)
             {
                    l = now;
             }
	         now += r;
             was = true;
	    }  else
	    {
	         now -= d;
	         l -= d;
	         if (l < d) break;
	         l = a[i] - d;
	         now += l;
	    }
	    mx = max(now,mx);
	}
	cout<<mx;

	return 0;
}

