#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#define N 100010
#define MOD 1000000007
using namespace std;
typedef double D;
typedef long long LL;
int n, m, num[N], fac[N], inv[N], sum[N], tmp, tmp2, ans, bas[N];
char s[N];
int pow(int x, int y)
{
    int res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (LL)res * x % MOD;
        x = (LL)x * x % MOD;
        y >>= 1;
    }
    return res;
}
int C(int x, int y)
{
    if(y > x)
        return 0;
    return (LL)fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}
int main()
{
    //freopen("1.in", "r", stdin);
    scanf("%d%d", &n, &m);
    getchar();
    gets(s + 1);
    for(int i = 1; i <= n; ++i)
        num[i] = s[i] - '0', sum[i] = sum[i - 1] + num[i];
    fac[0] = 1, bas[0] = 1;
    for(int i = 1; i <= n + 1; ++i)
        fac[i] = (LL)fac[i - 1] * i % MOD, bas[i] = (LL)bas[i - 1] * 10 % MOD;
    inv[n + 1] = pow(fac[n + 1], MOD - 2);
    inv[0] = 1;
    for(int i = n; i >= 1; --i)
        inv[i] = (LL)inv[i + 1] * (i + 1) % MOD;
    for(int i = 0; i < n; ++i)
    {
        tmp = n - 1 - i;
        if(i > 0)
        {
            tmp2 = (LL)sum[i] * C(n - tmp - 2, m - 1) % MOD * bas[tmp] % MOD;
            ans = (ans + tmp2) % MOD;
        }
        tmp2 = (LL)num[i + 1] * C(n - tmp - 1, m) % MOD * bas[tmp] % MOD;
        ans = (ans + tmp2) % MOD;
    }
    printf("%d\n", ans);
}
