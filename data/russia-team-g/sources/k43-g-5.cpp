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
if(a<=2||n<=2){cout<<0;return 0;}
if(a>n)ans=n/3;else ans=a/3;
cout<<ans;
}