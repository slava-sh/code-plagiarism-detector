#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int y;
  vector<long long int> a(300001);

long long int bs(int x, int bg,int ed)
{
    int aa= bg;
    int b = ed;
    int i=0;

    while (i<10000)
    {

    i++;
   // cout<<"trying "<<i<<"\n";
    //cout<<"a="<<a<<"b="<<b<<" a+b/2="<<(a+b)/2<<"\n";
    if (a[(aa+b)/2]==x) return -1*(aa+b)/2;
    if (a[(aa+b)/2]<x) {aa = (aa+b)/2;};
    if (a[(aa+b)/2]>x) {b=(aa+b)/2;};
    if ((b-aa)==1) {return b;};
    }
}
bool usl(long long int i,long long int j)
{
    return (true);
}


int main()
{
   freopen("che.in","r", stdin);
    freopen("che.out","w", stdout);

    long long int n,x;
    long long int r,t;


    cin>>n>>r;
    for (long long int i=0;i<n;i++)
    {
        x=0;
       scanf("%i", &x);
       //cin>>x;
      a[i]=x;
    }
    long long int k=0;

    for (long long int i=0;i<n;i++)
    {
        x=a[i]+r;
        if (x>a[n-1]) break;
        long long int b = bs(x,i-1,n );
        /*cout <<"lookinbg for "<<x<<"\n";
        cout<<b<<"\n";
        cout <<"so now we have +"<<n-b<<"\n";
        */if (b>0) k+=n-b;
            else k+=n+b-1;

    }
    cout<<k;
}
