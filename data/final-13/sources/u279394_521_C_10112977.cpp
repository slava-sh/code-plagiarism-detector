#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 8, mod = 1e9 + 7;
typedef int Real;
#define int long long
int n, K; 
char s[maxn]; 
long long fac[maxn], inv[maxn], sum[maxn], a[maxn];
long long ans;

inline long long Pow(long long x, int q) {
    long long r = 1;
    while (q) {
        if (q & 1) (r *= x) %= mod;
        q >>= 1; (x *= x) %= mod;
    }
    return r;
}

inline long long C(int n, int k)
    {return n < k ? 0 : fac[n] * inv[k] % mod * inv[n - k] % mod;}

Real main() {
	cin >> n >> K;
    scanf("%s", s);
    if (K == 0) {
		for (int i = 0; i < n; i++)
			ans = (ans * 10 + s[i] - '0') % mod;
			printf("%d\n", ans); return 0;
	}
    inv[0] = fac[0] = 1;
    {
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod, inv[i] = Pow(fac[i], mod - 2);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + (a[i] = s[i - 1] - '0');
    }
    for (int k = 1; k < n; k++) {
        ans += Pow(10, k - 1) * a[n - k + 1] % mod * C(n - k, K) % mod;
    }
    for (int k = 1; k < n; k++) {
        ans += Pow(10, k - 1) * sum[n - k] % mod * C(n - k - 1, K - 1) % mod;
    }
    cout << ans % mod << endl;
}
