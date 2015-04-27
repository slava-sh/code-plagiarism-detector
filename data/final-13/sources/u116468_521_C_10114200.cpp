#include <bits/stdc++.h>

#define R "%d"
#define RL "%I64d"
#define RD "%lf"
#define W "%.8lf"

#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Set(x, y) memset(x, y, sizeof(x))
#define Cpy(x, y) memcpy(x, y, sizeof(y))
#define All(x) x.begin(), x.end()
#define Sqr(x) ((x) * (x))
#define Sz(x) ((LL)x.size())

#define Mk make_pair
#define Pb push_back
#define Pk pop_back
#define Fr first
#define Se second

#define FOR(x, l, r) for (LL x = (l), end = (r); x <= end; ++x)
#define ROF(x, l, r) for (LL x = (l), end = (r); x >= end; --x)
#define Edge(x, y) for (LL x = g[y]; x; x = nt[x])

#define Read(x) ((x) = Get())
#define Lowbit(x) ((x) & (-x))
using namespace std;

typedef int LL;
typedef long long ll;
typedef double LD;
typedef long double real;

typedef map <LL, LL> MI;
typedef pair <LL, LL> PI;
typedef set <LL> SI;
typedef vector <LL> VI;

inline LL Get() {
    LL res = 0, q = 1;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
    if (ch == '-') q = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * q;
}

const LD eps = 1e-12, pi = M_PI;
const LL oo = (LL)2e9, mod = (LL)1e9 + 7;
const ll INF = (ll)1e17;

const LL N = (LL)1e5;
typedef LL arr[N + 10];

LL n, k, ans, cur;
char str[N + 10];
arr a, fac, inv, cal, pw;

LL C(LL n, LL r) {
    if (n < 0 || r < 0) return 0;
    if (r > n) return 0;
    return (ll)fac[n] * (ll)inv[r] % mod * (ll)inv[n - r] % mod;
}

LL main() {
#ifndef ONLINE_JUDGE
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
#endif

    scanf(R R "\n", &n, &k);
    scanf("%s", str + 1);
    FOR (i, 1, n) a[i] = str[i] - '0';
    fac[0] = inv[0] = inv[1] = pw[0] = 1;
    FOR (i, 1, n) fac[i] = (ll)fac[i - 1] * (ll)i % mod, pw[i] = (ll)pw[i - 1] * 10LL % mod;
    FOR (i, 2, n) inv[i] = (ll)(mod - mod / i) * (ll)inv[mod % i] % mod;
    FOR (i, 2, n) inv[i] = (ll)inv[i] * (ll)inv[i - 1] % mod;
    
    FOR (i, 1, n) {
        cur = ((ll)cur * 10LL % mod + (ll)a[i]) % mod, cal[i] = cur;
        if (n - i - 1 < k - 1) continue;
        (ans += (ll)cur * (ll)C(n - i - 1, k - 1) % mod) %= mod;
    }
    if (!k) return printf(R "\n", cal[n]), 0;
    FOR (i, 1, n) (cal[i] += cal[i - 1]) %= mod;
    
    cur = 0;
    ROF (i, n, 1) {
        cur = ((ll)cur + (ll)a[i] * (ll)pw[n - i] % mod) % mod;
        if (i - 1 < k) break;
        (ans += (ll)cur * (ll)C(i - 2, k - 1) % mod) %= mod;
    }
    
    FOR (i, 1, n - 2) {
        if (n - i < k) break;
        LL s1 = ((cal[n - 1] - cal[i]) % mod + mod) % mod, s2 = cal[n - i - 1];
        s1 = ((ll)s1 - (ll)s2 * (ll)pw[i] % mod) % mod;
        if (s1 < 0) s1 += mod;
        (ans += (ll)s1 * (ll)C(n - i - 2, k - 2) % mod) %= mod;
    }

    printf(R "\n", ans);
}
