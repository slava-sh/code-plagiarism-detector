#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
using namespace std;
long long a[10000],n,d,b=0,c,i,j,m,r,k[10000];
main()
{
freopen("sochi.in","r",stdin);
freopen("sochi.out","w",stdout);

cin>>n>>d;
c=0;
m=0;
r=n;
for(i=0; i<n; i++)cin>>k[i];
sort(k,k+n);
for(i=0; i<n; i++)
{
         
         if(k[i]-d>0&&c==0){m+=k[i]-d; c++;} else
         {
         if(k[i]-2*d>0&&c!=0&&c!=r-1){m+=k[i]-2*d; c++;} else
 {
         if(k[i]-d>0&&c==r-1){m+=k[i]-d; c++; break;} else r--;
}
}
}
cout<<m;
}




