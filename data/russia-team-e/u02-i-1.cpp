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
int main()
{
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    int n,k,i, a[100100];
    long long s;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    s=a[n-1];
    //m=s;
    for(i=n-2;i>=0;i--)
    {
    //if(m>=k && a[i]>=2*k)
    if (s+a[i]-2*k>=s) s+=a[i]-2*k; else break;
    }
    cout<<s;
return 0;
}

