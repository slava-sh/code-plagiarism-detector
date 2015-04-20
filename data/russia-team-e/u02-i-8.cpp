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
int a[1001001];
int main()
{
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    int n,k,i;
    __int64 s;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    s=a[n-1];
    int m=-1;
    for(i=n-2;i>=0;i--)

    if(s<s+a[i]-2*k && a[i]>=2*k) s+=a[i]-2*k;else
    {
        m=i;
        break;
    }
    if (m>=0 && s<s+a[m]-2*k) s+=a[i]-2*k;
   //if (s+a[i]-2*k>=s && a[i+1]>=3*k) s+=a[i]-2*k; else break;

    cout<<s;
return 0;
}

