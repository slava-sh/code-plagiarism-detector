/**
 * @author - liyan30 @ 2015-03-02 16:28
 * @brief - From sky to the sea.
 **/

#include <bits/stdc++.h>

using namespace std;

// SELF TEMPLATE CODE BGEIN

#define LOG(level, fmt, arg...) \
    printf("[" #level "] [Line:%d] " fmt"\n", __LINE__, ##arg);

#define NOTICE(fmt, arg...) LOG(NOTICE, fmt, ##arg)
#define FATAL(fmt, arg...) LOG(FATAL, fmt, ##arg)

#define DEBUG(x) do { \
    stringstream ss; \
    ss << #x << ": " << x; \
    NOTICE("%s", ss.str().c_str()) \
} while(0)

#define SZ(x) ((int)((x).size()))
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repcase int t, Case = 1; for (cin >> t; t; --t)

template<class T> inline void to_min(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void to_max(T &a, const T b) { if (b > a) a = b; }

// SELF TEMPLATE CODE END

const int MOD = 1000000007;
const int MAXN = 1000000 + 10;

long long mul(long long a, long long b) {
    return a * b % MOD;
}

long long fmul(long long a, int p) {
    long long ret = 1LL;
    while (p) {
        if (p & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return ret;
}

long long get_inv(long long x) {
    return fmul(x, MOD - 2);
}

long long fac[MAXN], base[MAXN];
char buf[MAXN];
long long valsum[MAXN];
int len, k;

long long get_com(int x, int y) {
    return mul(fac[x], mul(get_inv(fac[y]), get_inv(fac[x - y])));
}

int main() {
    fac[0] = 1;
    repf (i, 1, MAXN - 1) {
        fac[i] = mul(fac[i - 1], i);
    }
    base[0] = 1;
    repf (i, 1, MAXN - 1) {
        base[i] = mul(base[i - 1], 10);
    }

    while (scanf ("%d%d", &len, &k) != EOF) {
        scanf ("%s", buf);
        if (k == 0) {
            int ret = 0;
            rep (i, len) {
                ret = (mul(ret, 10) + (buf[i] - '0')) % MOD;
            }
            printf ("%d\n", ret);
            continue;
        }
        valsum[0] = 0;
        for (int i = 0; len - 2 - i >= k - 1; ++i) {
            valsum[i + 1] = mul(base[i], get_com(len - 2 - i, k - 1));
            valsum[i + 1] += valsum[i];
            valsum[i] %= MOD;
        }
        int ret = 0;
        rep (i, len) {
            int maxi = min(len - 2 - i, len - 2 - (k - 1));
            // NOTICE("i %d -> maxi %d", i, maxi);
            ret += mul(valsum[maxi + 1], buf[i] - '0');
            ret %= MOD;
            if (i >= k) {
                ret += mul(mul(get_com(i, k), buf[i] - '0'), base[len - 1 - i]);
                ret %= MOD;
            }
        }

        printf ("%d\n", ret);
    }

    return 0;
}