#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

const int N = 100 * 1000 + 13;
int m, k;
int a[N];
pt qq[N];

int b[N];

inline void gen()
{
    k = rand() % 5 + 2;
    m = rand() % 5 + 1;

    forn(i, m)
        a[i] = 1, b[i] = a[i];

    int sum = 0;
    forn(i, m)
        sum += a[i];

    while(sum < k)
    {
        int pos = rand() % m;
        a[pos]++, b[pos]++;

        sum++;
    }

    forn(i, k - 1)
    {
        int t = rand() % m;
        int r;

        if (b[t] > 0)
        {
            b[t]--;
            r = 0;
        }
        else
        {
            r = 1;
            int pos = rand() % m;
            while(b[pos] == 0)
                pos = rand() % m;
            b[pos]--;
            t = pos;
        }

        if (rand() % 4 <= 2)
            t = -1;

        qq[i] = mp(t + 1, r);
    }

    cerr << "GEN" << endl;
    cerr << k << " " << m << endl;
    forn(i, m)
        cerr << a[i] << " ";
    cerr << endl;
    forn(i, k - 1)
        cerr << qq[i].ft << " " << qq[i].sc << endl;
}

inline bool read()
{
    //gen();
    //return true;

    if (scanf ("%d%d", &k, &m) != 2)
        return false;

    forn (i, m)
        assert(scanf ("%d", &a[i]) == 1);

    forn (i, k - 1)
    {
        int t, r;
        assert(scanf ("%d%d", &t, &r) == 2);

        qq[i] = mp(t, r);
    }

    return true;
}

int used[N], u = 0;
set<pt> q;

inline int getMinId ()
{
    assert(!q.empty());

    return q.begin()->sc;
}

inline int mark (int cnt)
{
    int ans = 0;

    while (!q.empty())
    {
        if (q.begin()->ft <= cnt)
        {
            int id = q.begin()->sc;

            if (used[id] != u)
            {
                used[id] = u;
                ans++;
            }
        }
        else
            break;

        q.erase(q.begin());
    }

    return ans;
}

int last[N];

int used_naive[N];

inline void calc(int idx)
{
    if (idx == k - 1)
    {
        forn(i, m)
            if (a[i] == 0)
                used_naive[i] = true;

        return;
    }

    int t = qq[idx].ft, r = qq[idx].sc;
    t--;
    
    if (r == 0)
    {

        if (t != -1)
        {
            if (a[t] == 0)
                return;

            a[t]--;
            calc(idx + 1);
            a[t]++;
        }
        else
        {
            forn(i, m)
                if (a[i] > 0)
                {
                    a[i]--;
                    calc(idx + 1);
                    a[i]++;
                }
        }
    }
    else
    {
        bool has = false;
        forn(i, m)
            if (a[i] == 0)
            {
                has = true;
                break;
            }

        if (!has)
            return;

        if (t != -1)
        {
            if (a[t] == 0)
                return;

            a[t]--;
            calc(idx + 1);
            a[t]++;
        }
        else
        {
            forn(i, m)
                if (a[i] > 0)
                {
                    a[i]--;
                    calc(idx + 1);
                    a[i]++;
                }
        }
    }
}

inline bool naive()
{
    forn(i, m)
        used_naive[i] = false;
    forn(i, m)
        a[i] = b[i];

    calc(0);

    forn(i, m)
        if (used_naive[i] != (used[i] == u))
        {
            cerr << i + 1 << endl;
            return false;
        }

    return true;
}

inline void solve()
{
    forn(i, m)
        b[i] = a[i];

    forn (i, m)
        last[i] = -1;

    ford (i, k - 1)
    {
        if (qq[i].ft == 0)
            continue;

        if (last[ qq[i].ft - 1 ] == -1)
            last[ qq[i].ft - 1 ] = i;
    }

    q.clear();
    u++;

    forn (i, m)
        if (last[i] == -1)
            q.insert(mp(a[i], i));

    int cnt = 0;
    int it = 0;

    forn (i, k - 1)
    {
        int t = qq[i].ft, r = qq[i].sc;

        t--;

        if (r == 1)
        {
            if (cnt == 0)
            {
                int id = getMinId();

                assert(a[id] <= it);

                cnt += mark(it);

                it -= a[id];
            }
        }

        if (t >= 0)
        {
            assert(used[t] != u);

            a[t]--;

            if (a[t] > 0)
            {
                if (q.count(mp(a[t] + 1, t)))
                {
                    q.erase(mp(a[t] + 1, t));
                    q.insert(mp(a[t], t));
                }
            }
            else
            {
                used[t] = u;
                cnt++;
            }
        }
        else
            it++;

        if (t >= 0 && last[t] == i && used[t] != u)
            q.insert(mp(a[t], t));
    }

    mark(it);

    forn (i, m)
        if (used[i] == u)
            putchar('Y');
        else
            putchar('N');
    puts("");

    //assert(naive());
}

int main()
{
#ifdef SU2_PROJ
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif

    cout << setprecision(25) << fixed;
    cerr << setprecision(10) << fixed;

    srand(int(time(NULL)));

    int testCnt;
    assert(scanf ("%d", &testCnt) == 1);

    forn (test, testCnt)
    {
        assert(read());
        solve();
    }

#ifdef SU2_PROJ
    cerr << "TIME: " << clock() << endl;
#endif

    return 0;
}
