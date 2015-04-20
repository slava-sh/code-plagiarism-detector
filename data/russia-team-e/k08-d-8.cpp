#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <ctime>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#define ll long long
#define MAXN 100000
#define INF 10000000000
#define pb push_back
#define pob pop_back
#define sz size()
#define eps 1e-6
#define fname ""
#define pof pop_front
#define mp make_pair
#define pus empty()
using namespace std;
long long a[200005],n,m,mini=INF,sum=0,maxi=-INF,r,l,k;
bool ok(int ras)
{
//	
	for (int i=1;i<n;i++)
	{
		k=a[i]+ras;
	}
//	cout<<k<<"\n";
	if (k<=m)
	return true;
	return false;
}

int main ()
{
 freopen("fence.in","r",stdin);
 freopen("fence.out","w",stdout);
cin>>n>>m;
for (int i=1;i<=n;i++)
{
	cin>>a[i];
	sum+=a[i];
	if (a[i]>maxi)
	{
		maxi=a[i];
	}
}
sort(a+1,a+n+1);
if (n==1)
{
	cout<<a[1];
	return 0;
}
if (m>=sum)
{
	cout<<mini;
	return 0;
}
if (maxi>m)
{
	cout<<-1;
	return 0;
}
mini=INF;
r=m/n;
l=1;
ll mid;
while (r>l)
{
	mid=(r+l)/2;
//	cout<<mid<<"\n";	
	if (ok(mid))
	{
		l=mid+1;
	}	
	else
	r=mid-1;
}
if (ok(r))
{
	cout<<r;
	return 0;
}
else
cout<<l;
return 0;
}
