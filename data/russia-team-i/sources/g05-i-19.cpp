#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long a[100100],i,d,n,ans;
int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    cin>>n>>d;    
    for (i=0; i<n; i++)
       cin>>a[i];
    sort(a,a+n);
    ans=0;
    for (i=n-1; i>=0; i--)
       if (a[i]>=3*d) ans+=a[i]-2*d;
       else break;   
    if ((i>=0) && (a[i]>=2*d)) ans+=a[i]-2*d;
    if ((i>=1) && (a[i-1]>=2*d)) ans+=a[i-1]-2*d;    
    if (ans==0) cout<<a[n-1]<<endl;
    else cout<<ans+2*d<<endl;  
    return 0;    
}
