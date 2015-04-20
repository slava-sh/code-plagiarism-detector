
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
 
int main(int argc, char *argv[]) 
{
     freopen("che.in","r", stdin);                                                                                    
  freopen("che.out","w", stdout);
   
signed long n,r,d[300000],z;
int k=0,i,j;
cin>>n>>r;
d[n];
for(i=0;i<n;i++)
cin>>d[i];
for(i=0;i<n-1;i++)
for(j=1;j<n;j++)
if(d[j]-d[i]>r){k=k+(n-j);break;}
cout<<k;
 
 
    return EXIT_SUCCESS;
     
}
