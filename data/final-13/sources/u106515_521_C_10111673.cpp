#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define ll long long
#define pp 1000000007
#define N 110000
char str[N];
int n,k;
ll b[N],e[N],c[N],a[N];
ll C(int n,int m){
   return b[n]*e[n-m]%pp*e[m]%pp;
}
ll ksm(ll a,int b){
   ll ans=1;
   while(b){
     if(b&1)ans=ans*a%pp;
     a=a*a%pp;
     b/=2;
   }
   return ans;
}
int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",str+1);
    if(k==0){
      long long ans=0;
      for(int i=1;i<=n;i++)ans=(ans*10+str[i]-'0')%pp;
      cout<<ans<<endl;
      return 0;
    }
    b[0]=1;
    for(int i=1;i<=n;i++)b[i]=b[i-1]*i%pp;
    for(int i=0;i<=n;i++)e[i]=ksm(b[i],pp-2);
    for(int i=1;i<=n;i++)a[i]=a[i-1]+str[i]-'0';
    c[0]=1;
    for(int i=1;i<=n;i++)c[i]=c[i-1]*10%pp;
    ll ans=0;
    for(int i=0;n-1-i>=k;i++){
      ans=(ans+a[n-i-1]*c[i]%pp*C(n-1-i-1,k-1)%pp)%pp;
      ans=(ans+(ll)(str[n-i]-'0')*c[i]%pp*C(n-1-i,k)%pp)%pp;
    }
    cout<<ans<<endl;
    return 0;
}
