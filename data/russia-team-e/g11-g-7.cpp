//include<bebiachemi.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int n,d,mx,sm;
int a[1000000];
void prog()
{
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    cin>>n>>d;
    mx=0;
    sm=d;
    int i,j,k;
    j=0;
    for(i=0;i<n;i++)
    {
        cin>>k;
        if(k>mx)
            mx=k;
        if(k>2*d)
        {
            sm=sm+k-2*d;
            j++;
        }
    }
    if(j>=1)
        cout<<sm+d<<endl;
    else cout<<mx<<endl;
}
main()
{
    prog();
    //system("I.exe");
}
