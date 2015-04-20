#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
using namespace std;
long long a,n,d[300001],b=0,c,i,j,m,r,k;
queue<long long > q;
main()
{
freopen("che.in","r",stdin);
freopen("che.out","w",stdout);

cin>>n>>r;
for(i=0;i<n;i++){
cin>>d[i];
}
for(i=0;i<n;i++){
while(d[i]-d[a]>r){k+=n-i;a++;}

}
cout<<k;
      

}
