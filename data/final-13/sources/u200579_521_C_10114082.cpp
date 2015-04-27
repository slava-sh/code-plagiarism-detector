#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

const int MOD = 1000000007;
const int N = 100010;

int pow(int nr, int p) {
    int rez = 1;

    while(p) {
        if(p & 1)
            rez = (1LL * rez * nr) % MOD;
        nr = (1LL * nr * nr) % MOD;
        p /= 2;
    }

    return rez;
}

int n, k, rez, fact[N], invfact[N], p10[N], sum[N], sum2[N];
char a[N];

int comb(int n, int k) {
    if(k > n)
        return 0;
    int rez = (1LL * fact[n] * invfact[k]) % MOD;
    rez = (1LL * rez * invfact[n - k]) % MOD;

    return rez;
}

int main() {
    int i;
    //freopen("ttt", "r", stdin);

    cin >> n >> k;
    cin.get();
    cin.getline(a + 1, N);
    for(i = 1; i <= n; ++i)
        a[i] -= '0';

    if(k == 0) {
        int rez = 0;
        for(i = 1; i <= n; ++i)
            rez = (1LL * rez * 10 + a[i]) %MOD;
        cout << rez;
        return 0;
    }

    fact[0] = fact[1] = 1;
    for(i = 2; i < N; ++i)
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    for(i = 0; i < N; ++i)
        invfact[i] = pow(fact[i], MOD - 2);

    p10[0] = 1;
    for(i = 1; i < N; ++i)
        p10[i] = (1LL * p10[i - 1] * 10) % MOD;

    sum[n - 1] =sum2[n- 1] = a[n - 1];
    int rc = a[n - 1];
    for(i = n - 2; i > 1; --i) {
        sum[i] = (sum[i + 1] + a[i]) % MOD;

        rc = (1LL * rc + 1LL * p10[n - 2 - i + 1] * a[i]) % MOD;
        sum2[i] = rc;
    }

    int r1 = 0, r2 = 0, sc = 0;

    for(i = 1; i < n; ++i) {
        r1 = (1LL * r1 * 10 + 1LL * a[i]) % MOD;
        r2 = (1LL * r2 + 1LL * p10[i - 1] * a[n - i + 1]) % MOD;

        rez = (1LL * rez + 1LL * (r1 + r2) * comb(n - i - 1, k - 1)) % MOD;

        sc = (1LL * (sc - sum2[n - i + 1]) * 10 + 1LL * sum[i + 1]) % MOD;
        if(sc < 0)
            sc += MOD;

        rez = (1LL * rez + 1LL * sc * comb(n - i - 2, k - 2)) % MOD;
    }

    cout << rez;

    return 0;
}
