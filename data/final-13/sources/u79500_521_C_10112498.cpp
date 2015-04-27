#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<vector>
#include<time.h>
using namespace std;
const long long MOD=1000000007;
long long f[100006];
long long dig[100006];
long long inv[100006];
long long ten[100006];
long long sum[100006];
long long add[100006];
long long ksm(long long a,long long n)
{
    long long ans=1;
    while(n)
    {
        if(n&1)
            ans=ans*a%MOD;
        a=a*a%MOD;
        n>>=1;
    }
    return ans;
}
long long C(long long n,long long m)
{
    if (n>=m)
        return f[n]*inv[n-m]%MOD*inv[m]%MOD;
    return 0;
}
char s[100006];
int main()
{
    f[0]=1;
    for (int i=1; i<=100005; ++i)
        f[i]=f[i-1]*i%MOD;
    for (int i=0; i<=100005; ++i)
        inv[i]=ksm(f[i],MOD-2);
    int n,k;
    while(~scanf("%d%d%s",&n,&k,s))
    {
        long long now=0;
        for(int i=0;i<n;++i)
            dig[i]=s[i]-'0';
        if (k==0)
        {
            for (int i=1; i<=n; ++i)
                now=(now*10+dig[i-1])%MOD;
            printf("%I64d\n",now);
            return 0;
        }
        long long ans=0;
        for (int i=1; i<n; ++i)
        {
            now=(now*10+dig[i-1])%MOD;
            ans=(ans+now*C(n-i-1,k-1))%MOD;
        }
        ten[0]=1;
        for (int i=1; i<=n; ++i)
            ten[i]=ten[i-1]*10%MOD;
        for (int i=n; i>=1; --i)
            sum[i]=ten[n-i]*(dig[i-1])%MOD;
        for (int i=n; i>=1; --i)
            sum[i]=(sum[i]+sum[i+1])%MOD;
        for (int i=2; i<=n; ++i)
            ans=(ans+sum[i]*C(i-2,k-1))%MOD;
        now=0;
        for (int i=2; i<n; ++i)
            now=(now+dig[i-1])%MOD;
        for (int i=n-1; i>=1; --i)
            sum[i]=ten[n-i-1]*(dig[i-1])%MOD;
        sum[n]=0;
        for (int i=n-1; i>=1; --i)
            sum[i]=(sum[i]+sum[i+1])%MOD;
        for (int i=n-1; i>=1; --i)
            add[i]=dig[i-1];
        for (int i=n-1; i>=1; --i)
            add[i]+=add[i+1];
        if (k>=2)
            for (int i=1; i<n-1; ++i)
            {
                ans=(ans+now*C(n-i-2,k-2))%MOD,now=((now-sum[n-i]+MOD)*10+add[i+2])%MOD;
            }
        printf("%I64d\n",ans);
    }
    return 0;
}
