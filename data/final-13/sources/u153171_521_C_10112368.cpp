#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
typedef __int64 ll;
const ll mod = 1000000007;
ll f[111111] = { 0 };
ll inv[111111] = { 0 };
ll ten[111111] = { 0 };
ll sum[111111] = { 0 };
char s[111111];
ll quickfind(ll x, ll y){
    ll result = 1;
    while (y){
        if (y & 1)result = result*x%mod;
        y >>= 1;
        x = x*x%mod;
    }
    return result;
}
ll C(int m, int n){
    if (n<0 || n>m)return 0;
    if (n == 0 || n == m)return 1;
    return f[m] * inv[n]%mod * inv[m - n]%mod;
}
int main(){
    f[1] = 1;
    for (int i = 2; i <= 100000; i++)
        f[i] = f[i - 1] * i%mod;
    for (int i = 1; i <= 100000; i++)
        inv[i] = quickfind(f[i], mod - 2);
    ten[0] = 1;
    for (int i = 1; i <= 100000; i++)
        ten[i] = ten[i - 1] * 10 % mod;
    int n, m;
    __int64 ans = 0;
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + s[i] - '0';
    for (int i = 0; i <n-1; i++)
        ans+=sum[n - i - 1]*C(n-i-2,m-1)%mod*ten[i]%mod,ans%=mod;
    for (int i = 1; i <= n; i++){
        ans += ten[n - i] * (s[i] - '0')%mod*C(i - 1, m)%mod;
        ans %= mod;
    
    }
        
    printf("%I64d\n", ans);
    return 0;
}