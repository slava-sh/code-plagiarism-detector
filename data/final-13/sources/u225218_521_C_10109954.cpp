#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 100100
#define MOD 1000000007
using namespace std;
int n,k;
long long ans;
long long fac[M],inv[M];
char s[M];
void Linear_Shaker()
{
    int i;
    fac[0]=1;
    for(i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%MOD;
    inv[1]=1;
    for(i=2;i<=n;i++)
        inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
    inv[0]=1;
    for(i=1;i<=n;i++)
        (inv[i]*=inv[i-1])%=MOD;
}
long long Quick_Power(long long x,int y)
{
    long long re=1;
    while(y)
    {
        if(y&1) (re*=x)%=MOD;
        (x*=x)%=MOD; y>>=1;
    }
    return re;
}
long long C(int n,int m)
{
    if(n<m) return 0;
    return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
void Cheat()
{
    int i;
    long long temp=1;
    for(i=0;i<n;i++,(temp*=10)%=MOD)
        (ans+=(s[n-i]-'0')*temp)%=MOD;
    cout<<ans<<endl;
}
int main()
{
    int i;
    cin>>n>>k;
    scanf("%s",s+1);
    if(k==0)
    {
        Cheat();
        return 0;
    }
    Linear_Shaker();
    long long temp=0;
    for(i=0;i<n;i++)
    {
        if(i>=1) (temp+=Quick_Power(10,i-1)*C(n-i-1,k-1) )%=MOD;
        (ans+=(s[n-i]-'0')*(temp+Quick_Power(10,i)*C(n-i-1,k)%MOD) )%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}
