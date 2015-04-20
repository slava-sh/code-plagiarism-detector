//include<bebiachemi.h>
#include<stdio.h>
#include<iostream>
using namespace std;
long long b[1000000];
long long n,r;
long long sum;
long long sear(long long i)
{
    long long j,k;
    k=1;
    while(i+k<n)
        k*=2;
    j=i+k;
    while (k>0)
    {
        k/=2;
        if(j<n)
        {
        if (b[j]-b[i]<=r)
            j+=k;
        else j-=k;
        }
        else j-=k;
    }
    if(j<=1)
        j=0;
    else j-=1;
    while(b[j]-b[i]<=r&&j<n)
        j++;
    if(b[j]-b[i]>r||j>n)
        return(n-j);
    else return 0;
}
void babu()
{
    long long i;
    sum=0;
    for(i=0;i<n;i++)
        sum+=sear(i);
}
void inp()
{
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);
    cin>>n>>r;
    long long i;
    for(i=0;i<n;i++)
        cin>>b[i];
}
main()
{
    inp();
    babu();
    cout<<sum<<endl;
    //system("B.exe");
}
