#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
char s[100010];
int i,n,k;
long long B[100010],gB[100010],now,ans,bit[100010],sum[100010],Sum[100010];
const int MOD=1000000007;
long long C(int x,int y)
{
    if (x<y) return 0;
    return B[x]*gB[x-y]%MOD*gB[y]%MOD;
}
long long quick(long long a,int b)
{
    long long ans=1;
    while (b) {if (b&1) ans=ans*a%MOD; a=a*a%MOD; b/=2;}
    return ans;
}
int main()
{
    B[0]=1;
    for (i=1; i<=100005; i++) B[i]=B[i-1]*i%MOD;
    for (i=0; i<=100005; i++) gB[i]=quick(B[i],MOD-2);
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    if (k==0)
    {
        for (i=1; i<=n; i++) now=(now*10+s[i-1]-'0')%MOD;
        cout<<now;
        return 0;
    }
    for (i=1; i<n; i++)
    {
        now=(now*10+s[i-1]-'0')%MOD;
        ans=(ans+now*C(n-i-1,k-1))%MOD;
    }
    bit[0]=1;
    for (i=1; i<=n; i++) bit[i]=bit[i-1]*10%MOD;
    for (i=n; i>=1; i--) sum[i]=bit[n-i]*(s[i-1]-'0')%MOD;
    for (i=n; i>=1; i--) sum[i]=(sum[i]+sum[i+1])%MOD;
    for (i=2; i<=n; i++) ans=(ans+sum[i]*C(i-2,k-1))%MOD; now=0;
    for (i=2; i<n; i++) now=(now+s[i-1]-'0')%MOD;
    for (i=n-1; i>=1; i--) sum[i]=bit[n-i-1]*(s[i-1]-'0')%MOD;
    sum[n]=0;
    for (i=n-1; i>=1; i--) sum[i]=(sum[i]+sum[i+1])%MOD;
    for (i=n-1; i>=1; i--) Sum[i]=s[i-1]-'0';
    for (i=n-1; i>=1; i--) Sum[i]+=Sum[i+1];
    if (k>=2)
    for (i=1; i<n-1; i++)
    {
        ans=(ans+now*C(n-i-2,k-2))%MOD;
        now=((now-sum[n-i]+MOD)*10+Sum[i+2])%MOD;
    }
    cout<<ans;
    return 0;
}
