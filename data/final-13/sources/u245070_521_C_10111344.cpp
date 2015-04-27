#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

typedef long long ll;
const ll mod = (long long)1e9 + 7;
const int maxn = 200005;
int n, k,a[maxn];
ll mi[maxn], fac[maxn], inv[maxn],sum[maxn];

ll pw(ll x, ll y) {
    if (y == 0) return 1;
    ll s = pw(x, y>>1);
    s=s*s%mod;
    if (y&1)s=s*x%mod;
    return s;
}

ll c(int n, int m) {
    if (n < 0 || m < 0)  return 0;
    if (n < m) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main()  {
    scanf("%d%d", &n, &k);
    mi[0] = 1;
    for (int i = 1; i <= n; i ++)  mi[i] = 1ll * mi[i - 1] * 10 % mod;
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i ++)
        fac[i] = fac[i - 1] * i % mod, inv[i] = inv[i - 1] * pw(i, mod - 2) % mod;
    sum[0] = 0;
    for (int i = 1; i <= n; i ++)  {
        char c=getchar();
        while (c<'0'||c>'9')c=getchar();
        a[i]=c-'0';
        sum[i] = (sum[i - 1] + a[i]) % mod;
    }

    ll ans = 0;
    for (int j = 0; j <= n - 1; j ++)  {
        if (1 > n - j - 1)  continue;
        ans += mi[j] * c(n - 2 - j, k - 1) % mod * sum[n - j - 1] % mod;
        if (ans >= mod)  ans -= mod;
    }
    for (int i = 1; i <= n; i ++)  {
        ans += 1ll * a[i] * mi[n - i] % mod * c(i - 1, k) % mod;
        if (ans >= mod) ans -= mod;
    }
    cout << ans << endl;
    return 0;
}