#include <iostream>

#include <fstream>
using namespace std;
ifstream f1("che.in");
ofstream f2("che.out");

long long r,d[300001],i,j,ans,n,k;
main (){
       f1>>n>>r;ans=0;
       for (i=1;i<=n;i++)
       f1>>d[i];
       
       
       for (i=1;i<=n;i++)
       if (d[i]>r) {k=i;break;}
       
       
       
       for (i=1;i<n;i++){
           if (i>k) k=i+1;
        for (j=k;j<=n;j++){
        if (d[j]-d[i]>r) {ans=ans+n-j+1;break;}}
        
        }
       f2<<ans<<endl;
       }
        
