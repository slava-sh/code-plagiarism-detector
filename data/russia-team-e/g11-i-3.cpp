//include<bebiachemi.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,d,mx,sm;
int a[1000000];
void prog()
{
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    cin>>n>>d;
    mx=0;
    sm=d*2;
    int i,j,k,p,pp;
    j=0;
    for(i=0;i<n;i++)
    {
        cin>>k;
        a[i]=k;
        if(k>mx)
            mx=k;
        if(k>=3*d)
        {
            sm=sm+k-2*d;
            j++;
        }
    }
    p=-1;
    pp=-1;
    for(i=0;i<n;i++)
        if(a[i]>2*d&&a[i]<3*d)
            if(p<0||a[i]>a[p])
                p=i;
    for(i=0;i<n;i++)
        if(a[i]>2*d&&a[i]<3*d)
            if(pp<0||a[i]>a[pp])
                if(i!=p)
                    pp=i;
    if(p>=0)
    {
        sm+=a[p]-2*d;
        j++;
    }
    if(pp>=0)
    {
        sm+=a[pp]-2*d;
        j++;
    }

    if(j>1)
        cout<<sm<<endl;
    else cout<<mx<<endl;
}
main()
{
    prog();
   // system("I.exe");
}
