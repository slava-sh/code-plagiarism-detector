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
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);
    int n,k,i,j,l=2,b[300001];
    long long s=0;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>b[i];
    for(i=0;i<n;i++)
    {
    for(j=l;j<n;j++)
    if(b[j]-b[i]>k){break;}
    s+=n-j;
    l=j-1;
    }
    cout<<s;
return 0;
}

