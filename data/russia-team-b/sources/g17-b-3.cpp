#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) 
{
   freopen("che.in","r", stdin);                                                                                    
freopen("che.out","w", stdout);
  
long int n,r,d[300000];
int k=0,i,j;
cin>>n>>r;
d[n];
for(i=0;i<n;i++)
cin>>d[i];
for(i=0;i<n-1;i++)
for(j=1;j<n;j++)
{
if(d[n-1]-d[0]<1) break;
if(d[j]-d[i]>r){k=k+(n-j);break;}}
cout<<k;


    return EXIT_SUCCESS;
    
}
