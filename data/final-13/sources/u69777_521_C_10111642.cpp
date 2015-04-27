#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define maxn 100010
#define mod 1000000007
#define each(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
char a[maxn];
int pre[maxn],n,m,v[maxn],fact[maxn],anti[maxn];
int Power(int p,int n)
{
    int ans=1;
    for(;n;n>>=1,p=(LL)p*p%mod)
        if(n&1)
            ans=(LL)ans*p%mod;
    return ans;
}
int inv(int p)
{
    return Power(p,mod-2);
}
int C(int n,int m)
{
    if(n<m)
        return 0;
    return (LL)fact[n]*anti[m]%mod*anti[n-m]%mod;
}
void read()
{
    scanf("%d %d %s",&n,&m,a+1);
    for(int i=1;i<=n;++i)
        pre[i]=((LL)pre[i-1]*10+a[i]-'0')%mod;
    if(m==0)
    {
        cout<<pre[n]<<endl;
        exit(0);
    }
    fact[0]=anti[0]=1;
    for(int i=1;i<=n;++i)
        fact[i]=(LL)fact[i-1]*i%mod,anti[i]=inv(fact[i]);
}
LL work()
{
    LL ans=0;
    int s1=0,s2=0;
    ans=(ans+(LL)pre[1]*C(n-1-1,m-1))%mod;
    ans=(ans+(LL)(pre[n]-(LL)pre[n-1]*10%mod+mod)*C(n-1-1,m-1))%mod;
    for(int i=2;i<n;++i)
        ans=(ans+(LL)(a[i]-'0')*C(n-1-2,m-2))%mod,s1=(s1+pre[i])%mod,s2=(s2+(LL)pre[i-1]*10)%mod;
    for(int i=2,t=10;i<n;++i,t=(LL)t*10%mod)
    {
        s1=(s1-pre[i]+mod)%mod;
        s2=(LL)(s2-(LL)pre[n-(i-1)-1]*t%mod+mod)%mod*10%mod;
        ans=(ans+(LL)(s1-s2+mod)*C(n-i-2,m-2))%mod;
        ans=(ans+(LL)pre[i]*C(n-i-1,m-1)+(LL)(pre[n]-(LL)pre[n-i]*((LL)t*10%mod)%mod+mod)*C(n-i-1,m-1))%mod;
    }
    return ans;
}
int main()
{
    read();
    cout<<work()<<endl;
    return 0;
}
