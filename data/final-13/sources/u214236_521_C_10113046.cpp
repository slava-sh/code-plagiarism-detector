#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define mod 1000000007
#define N 101111
typedef long long LL;
LL T[N], C[N], CC[N], H[N], AC[N];
LL n, k;
char p[N];
LL power(long long a, LL b) {
    long long res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return (int)res;
}
void Prepare() {
    H[0] = 1;
    for (LL i = 1; i <= n + 10; i++)
        H[i] = H[i-1] * 10 % mod;
    C[k] = 1;
    CC[k+1] = 1;
    for (LL i = k + 1; i <= n; i++)
        C[i] = C[i - 1] * i % mod * power(i-k, mod-2) % mod;
    for (LL i = k+2; i <= n; i++)
        CC[i] = CC[i-1] * i % mod * power(i-(k+1), mod-2) % mod;
    if (k == 0) {
        for (LL i = 0; i <= n; i++)
            C[i] = 1;
        for (LL i = 0; i <= n; i++)
            CC[i] = i;
    }
    for (LL i = 0; i <= n; i++) {
        T[i] = C[i];
        C[i] = C[i] * H[n - i - 2] % mod;
    }
    AC[0] = C[0];
    for (LL i = 1; i <= n; i++)
        AC[i] = (AC[i-1] + C[i]) % mod;
}
LL C2(LL l) {
    if (l < 0) return 0;
    return CC[l];
}
LL Ask(LL l, LL r) {
    if (r < l) return 0;
    if (l <= 0) return AC[r];
    return (AC[r] - AC[l-1]) % mod;
}
int main() {
    scanf("%I64d%I64d", &n, &k);
    scanf("%s", p + 1);
    k--;
    //k==0; !!!
    for (LL i = 1; i <= n; i++)
        p[i] -= '0';
    for (LL i = 1; i <= n/2; i++)
        swap(p[i], p[n-i+1]);
    Prepare();
    if (k == -1) {
        LL res = 0;
        for (LL i = 1; i <= n; i++) {
            res += H[i-1] * p[i] % mod;
            res %= mod;
        }
        printf("%I64d\n", res);
        return 0;
    }
    LL res = 0;
    for (LL i = 1; i < n; i++) {
        res += Ask(n-i, n-2)* p[i] % mod;
        res %= mod;
        res += C2(n-i) * H[i-1] % mod * p[i] % mod;
        res %= mod;
    }
    for (LL i = 2; i <= n; i++) {
        res += T[i-2] * H[n-i] % mod * p[n] % mod;
        res %= mod;
    }
    printf("%I64d\n", (res+mod)%mod);
    return 0;
}