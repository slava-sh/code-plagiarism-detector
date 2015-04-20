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

   long long i,n,d,q[200001],a,b,mx;

int main()	{
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);

	cin>>n>>d;
	for(i = 1; i <= n; i++)
	{
	     cin>>q[i];
	}
	sort(q+1,q+n+1);
	mx = q[n];
	a = q[n];
	for(i = n; i > 1; i--)
	{
	    a -= d;
	    b = q[i-1] - d;
	    if (a <= 0 || b <= 0) break;
	    a += b;
	    mx = max(a,mx);
	}
	cout<<mx;

	return 0;
}

