#ifdef MG
#define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X &a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X &a) { return a * a; }
template<typename X, typename Y> inline ostream& operator<< (ostream& out, const pair <X, Y>& p) { return out << '(' << p.x << ", " << p.y << ')'; }
template<typename X> inline ostream& operator<< (ostream& out, const vector<X>& p) { forn(i, sz(p)) { if (i != 0) out << ' '; out << p[i]; } return out; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = acosl(ld(-1));

const int N = 2 * 100 * 1000 + 13;

int n, m;
char a[N], b[N];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2) return false;

    gets(a);
    
    gets(a);
    gets(b);    
    
    //forn(i, n) a[i] = char(rand() % 26 + 'a');
    //forn(i, m) b[i] = char(rand() % 26 + 'a');

    return true;
}

const int M = 2;
const int mods[M] = { INF + 7, INF + 9 };

struct hash
{
    int h[M];
    
    hash() { forn(i, M) h[i] = 0; }
    hash(int x) { forn(i, M) h[i] = x; }
};

inline bool operator< (const hash &a, const hash &b)
{
    forn(i, M)
        if (a.h[i] != b.h[i])
            return a.h[i] < b.h[i];
    return false;
}

inline bool operator== (const hash &a, const hash &b)
{
    forn(i, M)
        if (a.h[i] != b.h[i])
            return false;
    return true;
}

inline bool operator!= (const hash &a, const hash &b)
{
    forn(i, M)
        if (a.h[i] != b.h[i])
            return true;
    return false;
}

inline hash operator+ (const hash &a, const hash &b)
{
    hash res;
    forn(i, M)
    {
        res.h[i] = a.h[i] + b.h[i];
        if (res.h[i] >= mods[i])
            res.h[i] -= mods[i];
    }
    
    return res;
}

inline hash operator- (const hash &a, const hash &b)
{
    hash res;
    forn(i, M)
    {
        res.h[i] = a.h[i] - b.h[i];
        if (res.h[i] < 0)
            res.h[i] += mods[i];
    }
    
    return res;
}

inline hash operator* (const hash &a, int c)
{
    hash res;
    forn(i, M)
    {
        li cur = a.h[i] * 1ll * c;
        if (cur >= mods[i]) cur %= mods[i];
        res.h[i] = int(cur);
    }
    
    return res;
}

inline hash operator* (const hash &a, const hash &b)
{
    hash res;
    forn(i, M)
    {
        li cur = a.h[i] * 1ll * b.h[i];
        if (cur >= mods[i]) cur %= mods[i];
        res.h[i] = int(cur);
    }
    
    return res;
}

hash pw[N];

hash hb[26 + 3];

hash ha[26 + 3][N];

inline hash getHash(int idx, int lf)
{
    assert(lf + m <= n);
    return (ha[idx][lf + m - 1] - (lf == 0 ? hash(0) : ha[idx][lf - 1])) * pw[N - 1 - lf];
}

inline void prepare()
{
    pw[0] = hash(1);
    forl(i, N - 1)
        pw[i] = pw[i - 1] * 1009;
        
    forn(i, 26)
    {
        hb[i] = hash(0);
        
        forn(j, m)
            hb[i] = hb[i] + (int(b[j] - 'a') == i) * pw[j];
    }
    
    forn(i, 26)
    {
        hash curh(0);
        
        forn(j, n)
        {
            curh = curh + (int(a[j] - 'a') == i) * pw[j];
            ha[i][j] = curh;
        }
    }
}

inline void solve()
{
    prepare();
    
    vector<int> d;
    vector<int> firstPos(26, -1);
    
    forn(i, m)
        if (firstPos[int(b[i] - 'a')] == -1)
            firstPos[int(b[i] - 'a')] = i;

    vector<int> ans;
    ans.reserve(n);
        
    forn(i, n)
    {
        if (i + m > n) break;
        
        bool ok = true;
        vector<int> mapping(26, -1);
        
        forn(j, 26)
            if (firstPos[j] != -1)
            {
                int pos = i + firstPos[j];
                assert(pos < n);
                
                int x = int(a[pos] - 'a');
                int y = int(b[firstPos[j]] - 'a');
                
                if (mapping[x] != -1 && mapping[x] != y)
                {
                    ok = false;
                    break;
                }
                
                if (mapping[y] != -1 && mapping[y] != x)
                {
                    ok = false;
                    break;
                }
                
                mapping[x] = y;
                mapping[y] = x;
            }
            
        if (!ok) continue;
            
        forn(j, 26) if (mapping[j] == -1) mapping[j] = j;
        
        forn(j, 26)
            if (hb[j] * pw[N - 1] != getHash(mapping[j], i))
            {
                ok = false;
                break;
            }
            
        if (ok) ans.pb(i);
    }   
    
    cout << sz(ans) << endl;
    forn(i, sz(ans))
        printf("%d ", ans[i] + 1);
    puts("");
}

int main()
{
#ifdef MG
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
#ifdef MG
    cerr << "=== TIME: " << clock() << " ===" << endl;
#endif

    return 0;
}
