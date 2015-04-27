#pragma comment(linker, "/stack:64000000")
#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>
#include <string>
#include <deque>
#include <queue>
#include <ctime>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <cmath>
using namespace std;

typedef long long li;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb push_back
#define pii pair <int, int>
#define mp make_pair

template <typename X> inline X abs (const X &a) {return a < 0? -a: a;}
template <typename X> inline X sqr (const X &a) {return a * a;}

const int INF = INT_MAX / 2;
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100 * 1000 + 13;

vector <int> a;
int ans[N];
int sz = 0; 

inline bool f (int cnt)
{
    int ans = 0;
    for (int i = cnt; i < sz (a) - cnt; i++)
    {
        int idx = min (cnt, int (lower_bound (all (a), a[i]) - a.begin()));
        
        if (idx <= ans)
            continue;

        idx = int (upper_bound (all (a), a[i]) - a.begin());
        if (sz (a) - idx < cnt - ans)
            continue;

        ans++;
    }

    return ans >= cnt;
}

inline void print (int cnt)
{
    int res = 0;
    int first = 0;
    int last = sz (a) - cnt;

    for (int i = cnt; i < sz (a) - cnt; i++)
    {
        int idx = int (lower_bound (all (a), a[i]) - a.begin());
        
        if (min (idx, cnt) <= res)
            continue;
        
        ans[sz++] = a[first];
        first++;

        idx = int (upper_bound (all (a), a[i]) - a.begin());
        if (sz (a) - idx < cnt - res)
            continue;

        ans[sz++] = a[last];
        last = max (last + 1, idx);

        ans[sz++] = a[i];

        res++;
    }

    for (int i = 0; i < sz / 3; i++)
    {
        sort (ans + 3 * i, ans + 3 * (i + 1));
        ford (j, 3)
        {
            printf ("%d ", ans[3 * i + j]);
        }

        printf ("\n");
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int n;

    cin >> n;   

    a.resize (n);

    forn (i, n)
    {
        scanf ("%d", &a[i]);
    }

    sort (all (a));

    int lf = 1, rg = n / 3;

    while (rg - lf > 5)
    {
        int mid = (lf + rg) >> 1;

        if (f (mid))
        {
            lf = mid;
        }
        else
        {
            rg = mid;
        }
    }

    int res = 0;

    for (int i = rg; i >= lf; i--)
    {
        if (f (i))
        {
            cout << i << endl;
            print (i);
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}