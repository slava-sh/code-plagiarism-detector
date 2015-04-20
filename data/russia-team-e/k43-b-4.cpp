#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
     #include<stdio.h>
using namespace std;
int main()
{
freopen("che.in","r",stdin);
freopen("che.out","w",stdout);
int n,r,ans=0,a[300009];
//cin>>n>>r;
scanf("%d%d",&n,&r);
for(int i=0;i<n;i++)
{
cin>>a[i];
}
sort(a,a+n);
int l;
int ans1=0;
for(int i=n-1;i>=0;i--)
{             
if(a[i]-a[0]>r)ans++;else{l=i; break;}
}
for(int i=1;l>=i;i++)
{
if(a[l+1]-a[i]>r)ans1++;
}

cout<<ans+ans1*ans;








}