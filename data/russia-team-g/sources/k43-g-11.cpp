#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
freopen("prizes.in","r",stdin);
freopen("prizes.out","w",stdout);
int ans;
int n,a;
cin>>n>>a;
if(n==1||a==1)
{
cout<<(a*n+1)/4;
return 0;
}
if(n==2||a==2)
{
cout<<0;
return 0;
}
       if(a/3!=0)ans=a/3;ans=(a*n-1)/3 ;
	if(n/3!=0)ans=min(ans,n/3);
	ans=min(ans,min(a,n)/3);
cout<<ans;
			
}