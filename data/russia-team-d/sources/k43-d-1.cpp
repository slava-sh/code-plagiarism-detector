#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
freopen("fence.in","r",stdin);
freopen("fence.out","w",stdout);
int n,k,ans=1000000000,a[100000];
cin>>n>>k;
for(int i=0;i<n;i++)
{
cin>>a[i];
ans=min(ans,a[i]);
}
if(k/n<ans)cout<<k/n;else cout<<ans;

}