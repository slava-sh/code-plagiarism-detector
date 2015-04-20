#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int y;

long long int bs(vector<long long int> m,int x, int bg,int ed)
{
    int a = bg;
    int b = ed;
    int i=0;

    while (i<10000)
    {

    i++;
   // cout<<"trying "<<i<<"\n";
    //cout<<"a="<<a<<"b="<<b<<" a+b/2="<<(a+b)/2<<"\n";
    if (m[(a+b)/2]==x) return -1*(a+b)/2;
    if (m[(a+b)/2]<x) {a = (a+b)/2;};
    if (m[(a+b)/2]>x) {b=(a+b)/2;};
    if ((b-a)==1) {return b;};
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
    vector<long long int> a;

    cin>>n>>r;
    for (long long int i=0;i<n;i++)
    {
       cin>>x;
       a.push_back(x);
    }
    long long int k=0;

    for (long long int i=0;i<n;i++)
    {
        x=a[i]+r;
        if (x>a[n-1]) break;
        long long int b = bs(a,x,i-1,n );
        /*cout <<"lookinbg for "<<x<<"\n";
        cout<<b<<"\n";
        cout <<"so now we have +"<<n-b<<"\n";
        */if (b>0) k+=n-b;
            else k+=n+b-1;

    }
    cout<<k;
}
