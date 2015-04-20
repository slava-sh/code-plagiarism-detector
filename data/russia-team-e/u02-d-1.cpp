#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<fstream>
#include<math.h>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
int a[100001],k,n;
bool f(int m)
    {
        int s=0,i;
    for(i=0;i<n;i++)
    {
        s+=m;
        if(a[i]>s)s=a[i];
        if(s>k)return 0;
    }
    return 1;
     }
int ff()
    {
    int s=0,i;
    int l=0,r,m;
    r=k;
    if(a[0]<r)r=a[0];
    while(l<=r)
    {
        m=(l+r)/2;
    if(f(m)){s=m;l=m+1;}else r=m-1;
    }
    return s;
    }
int main()
{
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);

    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int q=ff();
    cout<<q;
return 0;
}

