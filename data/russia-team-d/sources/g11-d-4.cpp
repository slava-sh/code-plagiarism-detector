//include<bebiachemi.h>
#include<stdio.h>
#include<iostream>
using namespace std;
long long n,m;
long long a[1000000];
void anlz()
{
    long long i,j,k,mn,s,ss;
    j=0;
    k=m;
    mn=m;
    for(i=0;i<n;i++)
    {
        s=k/(n-i);
        if(s>a[i])
            s=a[i];
        if(mn<s)
            s=mn;
        if(a[i]-j<=s)
        {
            k-=s;
            j=m-k;
            if(s<mn)
                mn=s;
        }
        else
        {
            k-=a[i]-j;
            ss=a[i]-j;
            j=m-k;
            if(j>m)
                ss-=j-m;
            if(ss<mn)
                mn=ss;
        }
    }
    if(mn<0)
        mn=0;
    cout<<mn<<endl;
}
void srt(long long s, long long b, long long k, long long p)
{
    if(p>0&&b-s>1)
    {
    long long i,j,w;
    j=s;
    for(i=s;i<b;i++)
        if(a[i]<k)
        {
            w=a[j];
            a[j]=a[i];
            a[i]=w;
            j++;
        }
    srt(s,j,k-p,p/2);
    srt(j,b,k+p,p/2);
    }
}
void inp()
{
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    long long i;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>a[i];
    i=1;
    while(i<n)
        i*=2;
    srt(0,n,i,i/2);
}
main()
{
    inp();
    anlz();
    //system("D.exe");
}
