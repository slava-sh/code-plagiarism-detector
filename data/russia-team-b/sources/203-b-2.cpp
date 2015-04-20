#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

#define ll long long

ll ans=0,f1,f2;
int l,n,r,i,x,rr,mid,a[500000];

int main()
{
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);
    cin>>n>>rr;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
    {
        l=1;
        r=i-1;
        x=a[i]-rr;
        while(r-l>1)
        {
            mid=(l+r)/2;
            if(a[mid]<x)l=mid;
                   else r=mid;
        }
        if(a[r]<=x)f1=r;
        if(a[l]<=x)f1=l; else continue;
        ans=ans+f1;
    }
    cout<<ans<<endl;
    return 0;
}
