//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define DOW(i,a,b) for(int i = (a); i >= (b); --i)
#define RESET(c, val) memset(c, val, sizeof(c))
#define FOREACH(it, c) for (typeof(c.begin()) it = c.begin(); it != c.end(); it ++)
#define maxn 505

int f[2][maxn][maxn];
int C[maxn][maxn];
int mod;
int n, m;
string s;
int s1 = 0, s0 = 0;
int a[1000];

long long cal(int m, int n, int s0, int s1) {
    int t = 0;
    f[t][s0][s1] = 1;
    FOR(i, 0, n - 1) {
        t = 1 - t;
        FOR(j, 0, m) FOR(z, 0, m)
            f[t][j][z] = 0;
        FOR(j, 0, m) FOR(z, 0, m)
            if (f[1 - t][j][z] != 0) {
                if (j >= 2) {
                    f[t][j - 2][z + 2] = (1LL * f[t][j - 2][z + 2] 
                        + 1LL * f[1 - t][j][z] * C[j][2]) % mod;
                }
                if (z >= 2) {
                    f[t][j][z - 2] = (1LL * f[t][j][z - 2] 
                        + 1LL * f[1 - t][j][z] * C[z][2]) % mod;
                }
                if (j >= 1 && z >= 1) {
                    f[t][j - 1][z] = (1LL * f[t][j - 1][z] 
                        + ((1LL * f[1 - t][j][z] * C[j][1]) % mod) * C[z][1]) % mod;
                }
            }
    }
    return f[t][0][0];
}

int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> mod;
    
    RESET(C, 0);
    FOR(i, 0, 500) C[i][0] = 1;
    FOR(i, 1, 500) FOR(j, 1, 3)
        C[i][j] = (0LL + C[i - 1][j] + C[i - 1][j - 1]) % mod;

    RESET(a, 0);
    FOR(i, 1, m) {
        cin >> s;
        FOR(j, 0, n - 1) a[j] += s[j] == '1';
    }
    FOR(j, 0, n - 1) {
        if (a[j] > 2) {
            cout << 0; return 0;
        }
        s1 += a[j] == 1;
        s0 += a[j] == 0;
    }
    cout << cal(n, n - m, s0, s1);
    return 0;
}