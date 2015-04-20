#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int a[100002];

int main()
{
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    int n,k,i,j,sum=0,t=-1;
    cin>>n>>k;
    for (i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (i=1;i<=n;i++)
    if (sum+a[i]<=k) sum+=a[i]; else {t=k-sum; break;}
    if (t==-1) t=k-sum;
    cout<<min(a[1],t);
    return 0;
}
