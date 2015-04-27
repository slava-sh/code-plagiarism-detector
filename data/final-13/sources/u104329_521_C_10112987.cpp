#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5+9;
const long long mod = 1e9+7;
char s[N];
int a[N],n,m;
long long p[N];
long long exGcd(long long a,long long b,long long &x,long long &y){
    long long r,t;
    if(b==0){
       x=1;
       y=0;
       return a;
   }
   r=exGcd(b,a%b,x,y);
   t=x;
   x=y;
   y=t-a/b*y;
   return r;
}
long long Rev(long long a,long long b){
    long long x,y;
    exGcd(a,b,x,y);
    if(x<0) x+=mod;
    return x;
}
long long C(int n,int m){
    if(m>n) return 0;
    if(m==n||m==0) return 1;
    return p[n]*Rev(p[m]*p[n-m]%mod,mod)%mod;
}
long long A[N],B[N];
long long po[N];
long long f[N];
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        a[i]=s[i]-'0';
    }
    p[0]=1;
    po[0]=1;
    for(int i=1;i<N;i++){
        p[i]=p[i-1]*i%mod;
        po[i]=po[i-1]*10%mod;
    }
    if(m==0){
        long long ans=0;
        for(int i=1;i<=n;i++) ans=(ans*10+a[i])%mod;
        printf("%d\n",(int)ans);
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++)
        {
            A[i]=(A[i-1]*10+a[i])%mod;
        }
        for(int i=n;i>=1;i--)
        {
            B[i]=(B[i+1]+a[i]*po[n-i])%mod;
        }
        long long ans=0;
        for(int i=1;i<n;i++)
        {
            ans+=A[i]+B[i+1];
            ans%=mod;
        }
        printf("%d\n",(int)ans);
        return 0;
    }
    for(int i=0;i<=n;i++)
    {
        if(i) f[i]=f[i-1];
        f[i]+=C(n-2-i,m-1)*po[i]%mod;
        f[i]%=mod;
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=a[1]*po[i-1]%mod*C(n-i-1,m-1)%mod;
        ans%=mod;
    }
    ans+=a[n]*C(n-1,m);
    ans%=mod;
    for(int i=2;i<n;i++){
        long long tmp=f[n-1-i]*a[i]%mod+C(i-1,m)*a[i]%mod*po[n-i]%mod;
        tmp%=mod;
        ans+=tmp;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
