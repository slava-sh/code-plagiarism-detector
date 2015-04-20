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
int ans2=1000000000,ans3;
if(a<=2||n<=2){cout<<0;return 0;}
if(a>n)ans=n/3;else ans=a/3;   
if(a>n)
{
      if(n/3==0)ans2=(a*n-1)/3;else ans2=(n/3);
}

              if(a/3==0);ans2=min(a/3,ans2);	

ans=min(ans,ans2);
cout<<ans;
}