#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
using namespace std;
long long a[10000],n,d,b=0,c,i,j,m,r,k;

main()
{
freopen("sochi.in","r",stdin);
freopen("sochi.out","w",stdout);

cin>>n>>d;
c=0;
m=0;
for(i=0; i<n; i++)
{
         cin>>k;
         if(k-d>=0&&c==0){m+=k-d; c++;} else
         {
         if(k-2*d>=0&&c!=0&&c!=n-1){m+=k-2*d;j=d; c++;} else
 {
         if(k-d>=0&&c==n-1){m+=k-d; c++;j=0;}
}
}
}
cout<<m+j;
}



