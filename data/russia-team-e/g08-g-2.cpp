#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
using namespace std;
long long a,n,d,b=0,c,i,j,m,r,k;

main()
{
freopen("prizes.in","r",stdin);
freopen("prizes.out","w",stdout);
cin>>n>>m;
if(min(n,m)==1){
                if(max(n,m)>=3)cout<<(max(n,m)-3)/4+1;
                else cout<<(max(n,m)-3)/4;
                }
else
{
                if(min(n,m)>=3)cout<<(min(n,m)-3)/4+1;
                else cout<<(min(n,m)-3)/4;
                }

}
