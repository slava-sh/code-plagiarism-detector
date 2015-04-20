//include<bebiachemi.h>
#include<stdio.h>
#include<iostream>
using namespace std;
long long n,m;
void pragrama()
{
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    cin>>n>>m;
    long long k;
    if(n>m)
    {
        k=m;
        m=n;
        n=k;
    }
    m=(n+1)/4;
    cout<<m<<endl;
}
main()
{
    pragrama();
   // system("G.exe");
}
