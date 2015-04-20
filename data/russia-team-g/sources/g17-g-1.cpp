#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{  long int n,m;
   int k,l;
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    cin>>n>>m;
    
    if((m-4)%4==0 ||(m-2)%4==0) cout<<"0";
    else
    {k=0;
    k=(n+2)/4;
    if(n!=3 && (n-3)%4==0) k=k+(m+2)/4;
    if((n-1)%4==0) k=k+(m/4);
    cout<<k;}
    
    
   
    
    
    
   // system("PAUSE");
    return EXIT_SUCCESS;
}
