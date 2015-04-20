#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long a[100100],i,d,n,ans;
int main()
{
 //   freopen("sochi.in", "r", stdin);
   // freopen("sochi.out", "w", stdout);
    
    cin>>n>>d;    
    for (i=0; i<n; i++)
       cin>>a[i];
    sort(a,a+n);
    ans=a[n-1];
    for (i=n-2; i>=0; i--)
       if (a[i]>2*d) ans+=a[i]-2*d;
    cout<<ans<<endl;  
    return 0;    
}
