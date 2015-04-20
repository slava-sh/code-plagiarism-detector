#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
using namespace std;
long long a[10000],n,d,b=0,c,i,j,m,r,k,x;

main()
{
freopen("fence.in","r",stdin);
                               freopen("fence.out","w",stdout);
cin>>n>>k;
for(i=0; i<n; i++)
{
         cin>>a[i];
}

sort(a,a+n);
x=a[0];

if(k/n<x)x=k/n;
cout<<x;

}
