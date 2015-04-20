#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{ freopen("Input.txt","r", stdin);
  freopen("Output.txt","w", stdout);
  
long int n,r,d[300000];
int k=0,i,j;
cin>>n>>r;

for(i=0;i<n;i++)
cin>>d[i];
for(i=0;i<n-1;i++)
for(j=1;j<n;j++)
if(d[j]-d[i]>r)k++;
cout<<k;
//printf("%.6f",ans);
 // system("PAUSE");
    return EXIT_SUCCESS;
    
}
