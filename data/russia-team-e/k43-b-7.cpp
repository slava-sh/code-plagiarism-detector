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
cin>>a[0];
for(int i=1;i<n;i++)
{
scanf("%d",&a[i]);
	for(int j=0;j<i;j++)if(a[i]-a[j]>r)ans++;else break;

}         
cout<<ans;


}