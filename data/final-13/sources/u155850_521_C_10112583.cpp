#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <ctime> 
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define f0(a) memset(a, 0, sizeof(a))
#define ll long long
const int maxn = (int)1e6;
const int mod = (int)1e9 + 7;
char s[maxn];
int n, k;
int sum[maxn], a[maxn];
int fac[maxn], ifac[maxn], pw[maxn];
int sval[maxn];

int modPow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        n >>= 1;
    }
    return res;
}

int C(int n, int k) {
    if (k < 0) return 0;
    if (k > n) return 0;
    int res = fac[n];
    res = 1ll * res * ifac[k] % mod;
    res = 1ll * res * ifac[n - k] % mod;
    return res;
}


int main() {
    scanf("%d%d\n", &n, &k);
    ifac[0] = fac[0] = 1;
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = 1ll * pw[i - 1] * 10 % mod;
        fac[i] = 1ll * fac[i - 1] * i % mod;
        ifac[i] = modPow(fac[i], mod - 2);
    }

    for (int i = 0; i < n; ++i) {
        a[i] = getchar() - '0';
    }

    for (int i = n - 1; i >= 0; --i) {
        sval[i] = sval[i + 1];
        sval[i] = (sval[i] + 1ll * pw[n - 1 - i] * a[i]) % mod;
    }

    if (k == 0) {
        cout << sval[0] << endl;
        return 0;
    }
    
    for (int i = 0; i < n; ++i) {
        sum[i] = a[i];
        if (i > 0) sum[i] += sum[i - 1];
    }
    int cur = 0, ans = 0;
    for (int l = 1; l < n && n - l - 2 >= 0; ++l) {
        
        if (l == 1) {
            cur = sum[n - 2] - sum[0];
            cur %= mod;
        } else {
            cur = cur * 10ll % mod;
            cur = (0ll + cur + (sum[n - 1] - sum[l - 1])) % mod;
            cur = (cur - sval[n - l] + mod) % mod;
            if (cur < 0) cur += mod;
        }
        ans = (ans + 1ll * cur * C(n - l - 2, k - 2)) % mod;
    }

    cur = 0;
    for (int i = 0; i + 1 < n && n - i - 2 >= 0; ++i) {
        cur = (cur * 10ll + a[i]) % mod;
        ans = (ans + 1ll * cur * C(n - i - 2, k - 1)) % mod;
    }

    for (int i = n - 1; i > 0; --i) {
        ans = (ans + 1ll * sval[i] * C(i - 1, k - 1)) % mod;
    }
    cout << ans << endl;

    return 0;
}
