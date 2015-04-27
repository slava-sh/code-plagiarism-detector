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

int m, t, y, l, g, q, n, q1, q2, p1, p2, cnt, k, j, i, h, a[300001], d[300001];
pii p[300001];
map <int, int> mp[300001];
ll ans;

inline void solve()
{
    scanf ("%d%d", &n, &m);
    for (j = 1; j <= n; j++)
    {
        scanf ("%d%d", &q1, &q2);
        mp[q1][q2]++;
        mp[q2][q1]++;
        a[q1]++;
        a[q2]++;
    }
    for (j = 1; j <= n; j++)
    {
        p[j] = pii(a[j], j);
    }
    sort (p + 1, p + n + 1);
    for (j = 1; j <= n; j++)
    {
        if (!d[p[j].first])
        {
            d[p[j].first] = n - j + 1;
        }
    }
    for (j = n - 1; j > 0; j--)
    {
        if (!d[j])
        {
            d[j] = d[j + 1];
        }
    }
    d[0] = n - 1;
    for (j = 1; j <= n; j++)
    {
        if (a[j] >= m)
        {
            ans += ll(n - 1);
        }
        else
        {
            ans += ll(d[m - a[j]]);
            if (a[j] >= m - a[j])
            {
                ans--;
            }
            fors (w, mp[j])
            {
                q = (*w).first;
                if (a[q] - (*w).second < m - a[j] && a[q] >= m - a[j])
                {
                    ans--;
                }
            }
        }
    }
    cout << ans / 2;
}

inline void init()
{
    
}

inline void answer()
{
    
}

int main()
{
    //freopen ("input.txt","r",stdin); //freopen ("output.txt","w",stdout);
    //freopen ("olympiad.in","r",stdin); freopen ("olympiad.out","w",stdout);
    init();
    solve();
    answer();
    return 0;
}