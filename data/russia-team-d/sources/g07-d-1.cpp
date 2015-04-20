#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

long long n,k,a[1000000],i,mi=1000000009,jami;

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
      
       k-=a[1];
       
       k=k/(n-1);
       cout<<min(k,mi)<<endl;

}
