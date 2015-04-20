#include <iostream>
#include <cstdio>
using namespace std;
long long a[300300],l,r,n,k,i,ans=0;
int main()
{
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    cin>>n>>k;
    for (i=0; i<n; i++)
       cin>>a[i];
    l=0; r=1;
    while (r<n)
    {
          if (a[r]-a[l]<=k)
          {   
              ans+=l;
              r++;
          }
          else l++;
    }
    cout<<ans<<endl;
}
                 
