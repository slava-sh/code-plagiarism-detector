#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
using namespace std;
long long a,n,d[300001],b=0,c,i,j,m,r,k;

main()
{
freopen("che.in","r",stdin);
freopen("che.out","w",stdout);

cin>>n>>r;
for(i=0;i<n;i++){
cin>>d[i];}
a=0;
for(i=0; i<n; i++)
{
         k=i;
         while(d[i]+r>=d[k]&&k<n)k++;
         a=a+n-k;
}
cout<<a;
}




