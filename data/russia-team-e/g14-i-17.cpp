
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long n,m,k,ans,a[1000001],l,r,i,j,p,q;
int main(){
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    freopen("sochi.in","r",stdin);freopen("sochi.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    p=a[1];
    ans=a[1];
    if(a[1]+a[2]-2*m<a[1]){cout<<a[1];return 0;}
    else ans=a[1]+a[2]-2*m;
    for (i=3;i<=n;i++){
        if(a[i-1]<3*m) break;
        p+=a[i];
        p-=m*2;
        if(p>ans) ans=p;
        else break;
    }
    cout<<ans;
    return 0;
}
