#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
freopen("prizes.in","r",stdin);
freopen("prizes.out","w",stdout);
long long ans;
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
      // if(a+1/4!=0)ans=a/4;ans=(a*n-1)/4 ;
//	if(n+1/4!=0)ans=min(ans,n/4);
//	ans=min(ans,min(a,n)/4);
ans=min(a+2,n+2)/4;
if((a+2/4)!=0)ans=min(ans,a+2/4);else ans=min((a*n+2)/4,ans);
if((n+2/4)!=0)ans=min(ans,n+2/4);


cout<<ans;
			
}