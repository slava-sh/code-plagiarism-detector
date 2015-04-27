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
#define TASK "kebab"
//------------------------------------------------------------
int n, m, mod;
int s;
int d[2][502][502];
int colum[502];
vvi gr;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m >> mod;
    for(int i = 0; i < m; ++i)
    {
        string st;
        cin >> st;
        for(int j = 0; j < n; ++j)
            if (st[j] == '1')
                colum[j]++;
    }
    int p = n - m;
    int q = 0;
    d[q][p][0] = 1;
    for(int i = 0; i < n; ++i)
    {
        q ^= 1;
        for(int j = 0; j <= p; ++j)
            for(int r = 0; r <= p; ++r)
                d[q][j][r] = 0;
        for(int j = 0; j <= p; ++j)
        {
            for(int r = 0; r <= p; ++r)
            {
                if (!d[q ^ 1][j][r])
                    continue;
                if (colum[i] == 2)
                {
                    d[q][j][r] += d[q ^ 1][j][r];
                    d[q][j][r] %= mod;
                    continue;
                }
                if (colum[i] == 1)
                {
                    if (j)
                    {
                        d[q][j - 1][r + 1] += (j *(int64) (d[q ^ 1][j][r])) % mod;
                        d[q][j - 1][r + 1] %= mod;
                    }
                    if (r)
                    {
                        d[q][j][r - 1] += (r *(int64) (d[q ^ 1][j][r])) % mod;
                        d[q][j][r - 1] %= mod;
                    }
                }
                if (colum[i] == 0)
                {
                    if (j > 1)
                    {
                        d[q][j - 2][r + 2] += (j * (j - 1) / 2 * (int64) (d[q ^ 1][j][r])) % mod;
                        d[q][j - 2][r + 2] %= mod;
                    }
                    if (r > 1)
                    {
                        d[q][j][r - 2] += (r * (r - 1) / 2 * (int64) (d[q ^ 1][j][r])) % mod;
                        d[q][j][r - 2] %= mod;
                    }
                    if (j && r)
                    {
                        d[q][j - 1][r] += (r * j *(int64) d[q ^ 1][j][r]) % mod;
                        d[q][j - 1][r] %= mod;
                    }
                }
            }
        }
    }
    cout << d[q][0][0];
}