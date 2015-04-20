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
    if(n>1)
    {
    if(n<3)
        cout<<0<<endl;
    else
        cout<<1<<endl;
    }
    if(n==1)
        cout<<(n+1)/4<<endl;
}
main()
{
    pragrama();
    //system("G.exe");
}
