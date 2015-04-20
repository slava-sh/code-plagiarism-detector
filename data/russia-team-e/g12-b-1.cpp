#include <iostream>

#include <fstream>
using namespace std;
ifstream f1("che.in");
ofstream f2("che.out");

long long r,d[300001],i,j,ans,n;
main (){
       f1>>n>>r;ans=0;
       for (i=1;i<=n;i++)
       f1>>d[i];
       for (i=1;i<n;i++)
        for (j=i+1;j<=n;j++){
        if (d[j]-d[i]>r) {ans=ans+n-j+1;break;}}
        
       f2<<ans<<endl;
       }
        
