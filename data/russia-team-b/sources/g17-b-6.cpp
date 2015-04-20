#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
 
int main(int argc, char *argv[]) 
{
//freopen("che.in","r", stdin);                                                                                    
//freopen("che.out","w", stdout);
   
long int n,r;
int k=0,i,j;
cin>>n>>r;
long int d[n];
for(i=0;i<n;i++)
cin>>d[i];
if(d[n-1]-d[0]<r) cout<<k;
else
{
for(i=0;i<n-1;i++)
for(j=1;j<n;j++)
{
if(d[j]-d[i]>r){k=k+(n-j);}}
cout<<k;
}
    system("pause");
    return EXIT_SUCCESS;
     
}
