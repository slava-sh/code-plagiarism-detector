
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,k,a[1000001],l,r,i,j,p,q;
int main(){
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    freopen("fence.in","r",stdin);freopen("fence.out","w",stdout);
    cin>>n>>m;
    q=10000000;
    for (i=1;i<=n;i++){
        cin>>a[i];
        q=min(a[i],q);
        p+=a[i];
    }
    if(p<=m){cout<<q;return 0;}
    sort(a+1,a+n+1);
    l=0;
    r=m+1;
    while (l<r-1){
          k=(l+r)/2;
          p=0;
          q=0;
          for(i=1;i<=n;i++) p+=max(a[i]-a[i-1],k);
          if(p<=m)l=k;
          else r=k;
    }
    cout<<l;
}
