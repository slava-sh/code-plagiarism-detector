#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    long long a[100100],i,n,d,k1,k2,ans;
    cin>>n>>d;
    for (i=0; i<n; i++)
       cin>>a[i];
    sort(a,a+n);
    for (i=n-1; i>=0; i--)
    {
        if (a[i]>=2*d) k1=i;
        if (a[i]>=d) k2=i;
    }
    if (k2+2<k1) k1=k2-1;
    ans=(k2+1-n)*2*d;
    for (i=k2; i<n; i++) ans+=a[i];  
    cout<<ans<<endl;    
}
