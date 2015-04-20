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
    k=n-i-1;
    k=k/2+k%2;
    j=i+k;
    while (k>1)
    {
        k=k/2+k%2;
        if (b[j]-b[i]<=r)
            j+=k;
        else j-=k;
    }
    k=j;
    if(j<=2)
        j=1;
    else j-=2;
    while (j<k+2&&b[j]-b[i]<=r&&j<n)
        j++;
    if(b[j]-b[i]<=r)
        return 0;
    if(j>=n)
        return 0;
    else
        return(n-j);
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
