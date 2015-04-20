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
long long a[200005],n,m,mini=INF,sum=0,maxi=-INF,r,l,k,mid;
bool ok(int ras)
{
	k=a[1];
	for (int i=2;i<=n;i++)
	{
		k+=ras;
	}
//	cout<<k<<"\n";
	if (k<=m)
	{
		return true;
	}
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
	if (a[i]<mini)
	{
		mini=a[i];
	}
}
sort(a+1,a+n+1);
if (maxi>m)
{
	cout<<0;
	return 0;
}
if (m>=sum)
{
	cout<<mini;
	return 0;
}

if (n==1)
{
	cout<<min(a[1],m);
	return 0;
}
r=a[n];
l=1;
while (r>l+1)
{
	mid=(r+l)/2;
//	cout<<mid<<"\n";	
	if (ok(mid))
	{
		l=mid;
	}	
	else
	r=mid;
}
if (ok(r))
{
	cout<<r;
	return 0;
}
cout<<l;
return 0;
}
