/**
 * Copyright (c) 2014 Authors. All rights reserved.
 * 
 * FileName: F.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2014-11-18
 */
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
typedef pair<int, int> Pii;

const int inf = 0x3f3f3f3f;
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 500 + 5;

int n, m, mod;
int c[maxn];
int f[maxn][maxn];
bool vis[maxn][maxn];

inline int C(int a) { return a * (a - 1) / 2; }

int dp(int a, int b)
{
        if (vis[a][b]) return f[a][b];
        vis[a][b] = true;
        if (!a && !b) return f[a][b] = 1;
        f[a][b] = 0;
        if (a >= 2) f[a][b] = (f[a][b] +
                        (LL)C(a) * dp(a - 2, b) % mod) % mod;
        if (b >= 2) f[a][b] = (f[a][b] +
                        (LL)C(b) * dp(a + 2, b - 2) % mod) % mod;
        if (a && b) f[a][b] = (f[a][b] +
                        (LL)a * b % mod * dp(a, b - 1) % mod) % mod;
        return f[a][b];
}

int main()
{
        scanf("%d%d%d", &n, &m, &mod);
        rep(i,m) rep(j,n) {
                int x;
                scanf("%1d", &x);
                if (x) ++c[j];
        }
        int a = 0, b = 0;
        rep(i,n) {
                if (c[i] == 1) ++a;
                if (c[i] == 0) ++b;
        }
        printf("%d\n", dp(a, b));

        return 0;
}
