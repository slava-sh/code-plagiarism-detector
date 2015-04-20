#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    long long a[100100],i,d,n,ans;
    cin>>n>>d;    
    for (i=0; i<n; i++)
       cin>>a[i];
    sort(a,a+n);
    if (a[n-1]<d)
    {
        cout<<a[n-1]<<endl;
        return 0;
    }
    ans=2*d;
    for (i=n-1; i>=0; i--)
       if (a[i]>=2*d) ans+=a[i]-2*d;
       else break;
    if ((i>=0) && (a[i]>=d)) ans+=a[i]-d;
    if ((i>=1) && (a[i-1]>=d)) ans+=a[i]-d;
    cout<<ans<<endl;  
    return 0;    
}
