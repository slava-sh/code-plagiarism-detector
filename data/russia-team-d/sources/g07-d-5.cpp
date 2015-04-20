#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define LL long long 
using namespace std;

LL n,k,a[1000000],i,mi=1000000009,jami,m[1000000],lef,rig,mid,k1;
 LL check(LL z)
   {
      if (a[1]+(n-1)*z > k1) return 0;
      LL jam=a[1];
      for (int l=2;l<=n;l++)
       {
        if (a[i] > jam+k)
          jami=a[i]; else
          jam+=k;
       }
      if (jam <= k1) return 1; else return 0;
   }     

main()
{
 freopen ("fence.in","r",stdin);
 freopen ("fence.out","w",stdout);  
 
      
  cin>>n>>k; k1=k;
   
   for (i=1;i<=n;i++)
    {
     cin>>a[i]; 
     if (a[i]<mi) mi=a[i]; 
     jami+=a[i];
    }
      if (jami<=k) {cout<<mi<<endl; return 0;}

 sort (a+1,a+n+1);
       
        m[1]=a[1];

      for (i=2;i<=n;i++)
          m[i]=a[i]-a[i-1];

        k-=a[n];
        
            lef=0;rig=mi;
             
              while (lef+1<rig)
               {
                  mid=(lef+rig)/2;
                  if (check(mid)==1) lef=mid; else rig=mid;
               }        
                   while (check(rig)==0) rig--;

 cout<<min(rig,mi)<<endl;
}
