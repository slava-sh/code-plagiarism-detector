#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
freopen("fence.in","r",stdin);
freopen("fence.out","w",stdout);
int n,k,ans=1000000000,a[100009],r=0,an=0;
cin>>n>>k;
for(int i=0;i<n;i++)
{
cin>>a[i];

if(an==0)r+=a[i];
if(k<=r)an=1;

ans=min(ans,a[i]);
}

if(an==1)cout<<k/n;else cout<<ans;

}