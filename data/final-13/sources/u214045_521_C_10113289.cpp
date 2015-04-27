#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#define MAXN 100010
#define mod 1000000007
using namespace std;
int n,k;
char s[MAXN];
long long ans,num;
long long a[MAXN],b[MAXN];
inline long long pow(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
inline void init()
{
    a[0]=b[0]=1;
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]*i%mod;
        b[i]=b[i-1]*pow(i,mod-2)%mod;
    }
}
inline long long C(int n,int m)
{
    if(m>n)
        return 0;
    return a[n]*b[m]%mod*b[n-m]%mod;
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    init();
    ans=C(n-1,k)*(s[n]-'0')%mod;
    for(i=n-1;i;i--)
    {
        num=(num+C(i-1,k-1)*pow(10,n-1-i)%mod)%mod;
        ans=(ans+(num+C(i-1,k)*pow(10,n-i)%mod)%mod*(s[i]-'0'))%mod;
    }
    printf("%I64d\n",ans);
    return 0;
}