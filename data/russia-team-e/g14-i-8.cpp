
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
    for (i=2;i<=n;i++){
        if(a[i]<2*m) break;
        p+=a[i];
        p-=m*2;
        ans=max(ans,p);
    }
    cout<<ans;
}
