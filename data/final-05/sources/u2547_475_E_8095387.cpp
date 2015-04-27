#undef NDEBUG
#ifdef SU2_PROJ
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
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

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

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
inline ostream& operator<< (ostream& out, const pt& p) { return out << '(' << p.x << ", " << p.y << ')'; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 2 * 1000 + 13;

int n, m;
vector<int> gg[N];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2) return false;
    
    forn(i, m)
    {
        int x, y;
        assert(scanf("%d%d", &x, &y) == 2); x--, y--;
        //x = i, y = (i + 1) % n;
        
        gg[x].pb(y);
        gg[y].pb(x);
    }
    
    return true;
}

int e[N][N];
vector<int> g[N], tg[N];

int u, used[N];

int comp[N];
int cnt[N];

void dfs3(int v, int col)
{
    used[v] = u;
    comp[v] = col;
    cnt[col]++;
    
    forn(i, sz(tg[v]))
    {
        int to = tg[v][i];
        if (used[to] != u)
            dfs3(to, col);
    }
}

int szperm;
int perm[N];

void dfs2(int v)
{
    used[v] = u;
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];       
        if (used[to] != u)
            dfs2(to);
    }
    
    perm[szperm++] = v;
}

void dfs(int v)
{
    used[v] = u;
    
    forn(i, sz(gg[v]))
    {
        int to = gg[v][i];      
        
        if (!e[v][to])
        {
            g[v].pb(to);
            tg[to].pb(v);
            
            e[v][to] = true;
            e[to][v] = true;
        }
        
        if (used[to] != u)
            dfs(to);
    }
}

int sum[N];
int z[N];

int dfsCalc(int v, int pr)
{
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (to == pr) continue;
        sum[v] += dfsCalc(to, v);
    }
    
    z[v] = cnt[v] * sum[v];
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (to == pr) continue;
        z[v] += z[to];
    }
    
    sum[v] += cnt[v];
    
    return sum[v];
}

inline void calc(const vector<int> &cur, int n)
{
    forn(i, n + 1) used[i] = 0;
    
    used[0] = 1;
    
    //forn(i, sz(cur)) cerr << cur[i] << ' '; cerr << endl;
    
    forn(i, sz(cur))
        ford(s, n + 1)
            if (used[s] && s + cur[i] <= n)
                used[s + cur[i]] = true;

    //forn(i, n + 1) cerr << used[i] << ' '; cerr << endl;              
}

inline void solve()
{
    u++;
    dfs(0);

    u++;
    dfs2(0);
    
    assert(szperm == n);
    reverse(perm, perm + szperm);
    
    int ans = 0;
    
    u++;
    int col = 0;
    forn(ii, szperm)
    {
        int i = perm[ii];
        if (used[i] != u)
        {
            cnt[col] = 0;
            dfs3(i, col);
            ans += cnt[col] * cnt[col];
            col++;
        }
    }
    
    forn(i, n) g[i].clear();
    
    forn(i, n)
        forn(j, sz(gg[i]))
        {
            int x = comp[i], y = comp[gg[i][j]];
            if (x == y) continue;           
            g[x].pb(y);
        }

    int sumn = n;   
    n = col;
    
    forn(i, n)
    {
        sort(all(g[i]));
        g[i].erase(unique(all(g[i])), g[i].end());
    }
    
    int curVal = 0;

    /*  
    forn(i, n)
        forn(j, sz(g[i]))
            cerr << i + 1 << ' ' << g[i][j] + 1 << endl;
    */
    
    forn(i, n)
    {
        forn(j, n) sum[j] = z[j] = 0;       
        dfsCalc(i, -1);
        
        vector<int> cur(sz(g[i]));
        
        forn(j, sz(g[i])) cur[j] = sum[g[i][j]];
        
        //cerr << i << endl;
        calc(cur, sumn);
        
        int add = 0;
        forn(j, sz(g[i])) add += z[g[i][j]];
        
        forn(j, sumn + 1)
        {
            if (!used[j]) continue;
            
            int a = j;
            int b = sumn - j;
            
            int cur = a * b;
            
            cur += cnt[i] * (sumn - a - cnt[i]);
            cur += add;

            curVal = max(curVal, cur);
        }
    }
    
    ans += curVal;
    
    cout << ans << endl;
}

int main()
{
#ifdef SU2_PROJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
#ifdef SU2_PROJ
    cerr << "== TIME: " << clock() << " ==" << endl;
#endif

    return 0;
}
