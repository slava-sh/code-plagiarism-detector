#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <queue>
#include <list>
#include <memory.h>
#include <complex>
#include <numeric>
using namespace std;
#pragma comment(linker, "/STACK:256000000")
#define mp make_pair
#define pb push_back
#define all(C) (C).begin(), (C).end()
#define sz(C) (int)(C).size()
#define PRIME 1103
#define PRIME1 31415
#define INF ((1ll << 30) - 1)
#define MOD 1000000007
#define FAIL ++*(int*)0
#define EPS 1e-8
#define IT 10000
template<class T> T sqr(T a) {return a * a;}
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pi64;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<int64> vi64;
typedef vector<vi64> vvi64;
typedef vector<pi64> vpi64;
typedef vector<vpi64 > vvpi64;
typedef vector<pii> vpii;
typedef vector<vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vector<pair<int, int > > > vvpii;
typedef vector<vector<vector<pair<int, int > > > > vvvpii;
typedef complex<double> cd;
//------------------------------------------------------------

int n, m, mod;
int dp[501][501];
int64 C[501][501];

int rec(int r, int64 c2)
{
    if(r == n)
        return 1;

    if(c2 > n)
        return 0;

    if(dp[r][c2] != -1)
        return dp[r][c2];

    int res = 0;

    int64 q = r * 2;
    int64 c0 = n - q + c2;
    int64 c1 = q - c2 * 2;

    if(c0 >= 1 && c1 >= 1)
        res = (res + rec(r + 1, c2 + 1) * c0 * c1) % mod;

    if(c1 >= 2)
        res = (res + rec(r + 1, c2 + 2) * C[c1][2]) % mod;

    if(c0 >= 2)
        res = (res + rec(r + 1, c2) * C[c0][2]) % mod;

    return dp[r][c2] = res;
}

int main()
{
#ifdef __APPLE__
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d%d", &n, &m, &mod);

    C[0][0] = 1;
    for(int i = 1; i <= 500; ++i)
    {
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }

    vi q(n, 0);
    int c2 = 0;
    for(int i = 0; i < m; ++i)
    {
        string s;
        cin >> s;

        for(int j = 0; j < n; ++j)
        {
            if(s[j] == '1')
            {
                ++q[j];
                c2 += q[j] == 2;
            }
        }
    }

    memset(dp, -1, sizeof dp);
    int res = rec(m, c2);

    cout << res << endl;
    return 0;
}

