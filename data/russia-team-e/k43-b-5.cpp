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
            for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
	if(a[j]-a[i]>r)ans++;
cout<<ans;







}