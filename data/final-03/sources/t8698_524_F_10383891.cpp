#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair < int , int > pair;

const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = std::numeric_limits<double>::infinity();
const double EPS = 1e-8;

const int N = 1000179;
const ll MOD = 1000000007;
const ll P = 179;

std::string s;
int n;
int a[N * 2];
int sum[N], sumMinPref[N], sumMinSuff[N];
ll ppow[N * 2], h[N * 2];
ll hbr1[N * 2], hbr2[N * 2];

void computeHashes()
{
    ppow[0] = 1;
    for (int i = 1; i < N * 2; ++i)
        ppow[i] = (ppow[i - 1] * P) % MOD;
    h[0] = 0;
    for (int i = 0; i < n * 2; ++i)
        h[i + 1] = (h[i] * P + (a[i] + 2)) % MOD;

    hbr1[0] = 0;
    for (int i = 0; i < n * 2; ++i)
        hbr1[i + 1] = (hbr1[i] * P + 3) % MOD;
    hbr2[0] = 0;
    for (int i = 0; i < n * 2; ++i)
        hbr2[i + 1] = (hbr2[i] * P + 1) % MOD;
}

inline ll getHash(int p, int len)
{
    return (MOD + h[p + len] - (h[p]*ppow[len]) % MOD) % MOD;
}

ll getHashBr(int b1, int p, int b2, int len)
{
    ll ans = 0;
    if (len <= b1)
        return hbr1[len];
    ans = (hbr1[b1] * ppow[len - b1]) % MOD;
    len -= b1;
    if (len <= n)
        return (ans + getHash(p, len)) % MOD;
    ans += (getHash(p, n) * ppow[len - n]) % MOD;
    len -= n;
    return ans + hbr2[len];
}

int getLCP(int ab1, int ap, int ab2, int bb1, int bp, int bb2)
{
    int l = 0, r = n + ab1 + ab2;
    while (l < r)
    {
        int m = (l + r + 1) >> 1;
        if (getHashBr(ab1, ap, ab2, m) == getHashBr(bb1, bp, bb2, m))
            l = m;
        else
            r = m - 1;
    }
    return l;
}

int getIth(int b1, int p, int b2, int i)
{
    if (i < b1)
        return 1;
    i -= b1;
    if (i < n)
        return a[p + i];
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);

    std::cin >> s;
    n = s.length();
    for (int i = 0; i < n; ++i)
        a[i] = (s[i] == '(' ? 1 : -1);
    memcpy(a + n, a, n * sizeof(int));

    sum[0] = 0;
    for (int i = 0; i < n; ++i)
        sum[i + 1] = sum[i] + a[i];
    sumMinPref[0] = IINF;
    for (int i = 0; i <= n; ++i)
        sumMinPref[i + 1] = std::min(sumMinPref[i], sum[i]);
    sumMinSuff[n + 1] = IINF;
    for (int i = n; i >= 0; --i)
        sumMinSuff[i] = std::min(sumMinSuff[i + 1], sum[i]);

    computeHashes();

    int bestI = -1, bestB1 = N*10, bestB2 = N*10;
    for (int i = 0; i < n; ++i)
    {
        int currB1, currB2;
        int minX = 0;
        minX = std::min(minX, sumMinSuff[i] - sum[i]);
        minX = std::min(minX, sumMinPref[i + 1] + sum[n] - sum[i]);
        currB1 = -minX;
        currB2 = sum[n] + currB1;
        if (currB1 + currB2 > bestB1 + bestB2)
            continue;
    
        if (currB1 + currB2 < bestB1 + bestB2)
        {
            bestI = i;
            bestB1 = currB1;
            bestB2 = currB2;
            continue;
        }

        int lcp = getLCP(bestB1, bestI, bestB2, currB1, i, currB2);
        if (lcp == bestB1 + bestB2 + n)
            continue;

        if (getIth(currB1, i, currB2, lcp) > getIth(bestB1, bestI, bestB2, lcp))
        {
            bestI = i;
            bestB1 = currB1;
            bestB2 = currB2;
        }
    }

    for (int i = 0; i < bestB1; ++i) std::cout << '(';
    for (int i = 0; i < n; ++i) std::cout << (a[i + bestI] == 1 ? '(' : ')');
    for (int i = 0; i < bestB2; ++i) std::cout << ')';

    return 0;
}
