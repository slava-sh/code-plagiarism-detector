#include <iostream>
#include <stdio.h>
using namespace std;


long long i,ri,r,a[400000],ans,n;
main()
{
      freopen ("che.in","r",stdin);
      freopen ("che.out","w",stdout);
  cin>>n>>r;
   
   for (i=1;i<=n;i++)
   cin>>a[i];
   ri=1;
       
    for (i=1;i<n;i++)
     {
       while (a[ri]-a[i]<=r && ri<n) ri++;
       if (a[ri]-a[i]>r) ans+=n-ri+1;
     }
     cout<<ans<<endl;
}
