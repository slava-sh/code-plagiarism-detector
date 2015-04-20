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
ans=(n/3);
if(n/3==0)ans+=(n-1)/3;
cout<<ans;
}