#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <utility>
#include <ctime>
#include <memory.h>
#include <cctype>
#include <cstdlib>

using namespace std;

#pragma comment (linker, "/STACK:64000000")

#define y0 qwe
#define y1 asd
#define sz size()
#define pb push_back
#define fors(w,s) for(map <int, int> :: iterator w = s.begin(); w != s.end(); w++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ull unsigned long long
#define vi vector <int>
#define vvi vector <vi>
#define inf 2000000000
#define mod 1000000007
#define ll long long
#define maxint 2139062143 //2147483647
#define maxll 9223372036854775807
#define fi first
#define se second
#define eps 1e-9
#define doubleinf 1000000000000000.0

int m, t[100500], y, l, g, q, n, q1, q2, p1, p2, cnt, k, j, i, h, a[100500];
bool b[100500], u[100500], f[100500];
char c[100500];

inline void solve()
{
    scanf ("%d%d\n", &n, &m);
    for (j = 1; j <= m; j++)
    {
        scanf ("%c %d\n", &c[j], &a[j]);
        if (c[j] == '+')
        {
            b[a[j]] = 1;
        }
        else
        {
            if (!b[a[j]])
            {
                k++;
                f[a[j]] = 1;
            }
        }
    }
    for (j = 1; j <= m; j++)
    {
        if (c[j] == '+')
        {
            if (k || t[a[j]] < j - 1)
            {
                u[a[j]] = 1;
            }
            k++;
            f[a[j]] = 1;
        }
        else
        {
            if (k == 1)
            {
            }
            else
            {
                u[a[j]] = 1;
            }
            k--;
            f[a[j]] = 0;
        }
        t[a[j]] = j;
    }
    k = 0;
    for (j = 1; j <= n; j++)
    {
        if (!u[j] && t[j] && t[j] < m && !f[j])
        {
            u[j] = 1;
        }
        if (!u[j])
        {
            k++;
        }
    }
    printf ("%d\n", k);
    for (j = 1; j <= n; j++)
    {
        if (!u[j])
        {
            printf ("%d ", j);
        }
    }
}

inline void init()
{
    
}

inline void answer()
{
    
}

int main()
{
   // freopen ("input.txt","r",stdin); freopen ("output.txt","w",stdout);
    //freopen ("olympiad.in","r",stdin); freopen ("olympiad.out","w",stdout);
    init();
    solve();
    answer();
    return 0;
}