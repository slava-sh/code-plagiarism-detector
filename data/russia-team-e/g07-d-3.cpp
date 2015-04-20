#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

long long n,k,a[1000000],i,mi=1000000009,jami,m[1000000],lef,rig,mid;
 long long check(long long z)
   {
     long long l,res=0;
      
      for (l=1;l<=n;l++)
        res+=max(0LL,z-m[l]);
     if (res<=k) return 1; else return 0;   
   }     

main()
{
 freopen ("fence.in","r",stdin);
 freopen ("fence.out","w",stdout);  
 
      
  cin>>n>>k;
   
   for (i=1;i<=n;i++)
    {
     cin>>a[i]; 
     if (a[i]<mi) mi=a[i]; 
     jami+=a[i];
    }
      if (jami<=k) {cout<<mi<<endl; return 0;}

 sort (a+1,a+n+1);
       
    
     sort (a+1,a+n+1);
        m[1]=a[1];

      for (i=2;i<=n;i++)
          m[i]=a[i]-a[i-1];

        k-=a[n];
        
            lef=0;rig=1000000000;
             
              while (lef+1<rig)
               {
                  mid=(lef+rig)/2;
                  if (check(mid)==1) lef=mid; else rig=mid;
               }        
                   while (check(rig)==0) rig--;

 cout<<min(rig,mi)<<endl;
 //system ("pause");               
}
