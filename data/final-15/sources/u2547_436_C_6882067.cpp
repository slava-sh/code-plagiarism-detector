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

const int N = 1000 + 3;
const int M = 10 + 3;

int n, m, k, w;
char a[N][M][M];

inline bool read()
{
    if (scanf("%d%d%d%d", &n, &m, &k, &w) != 4) return false;
    
    forn(i, k)
        forn(j, n)
            assert(scanf("%s", a[i][j]) == 1);          
    
    return true;
}

inline int calc(int x, int y)
{
    int ans = 0;
    forn(i, n)
        forn(j, m)
            ans += int(a[x][i][j] != a[y][i][j]);
            
    return ans * w;
}

int dsu[N];

int leader(int v)
{
    if (dsu[v] == v) return v;
    return dsu[v] = leader(dsu[v]);
}

inline bool unite(int x, int y)
{
    x = leader(x);
    y = leader(y);
    
    if (x == y) return false;
    
    if (rand()) swap(x, y);
    
    dsu[x] = y;
    return true;
}

vector<int> g[N];

void dfs(int v, int pr)
{
    if (pr != -1) printf("%d %d\n", v + 1, pr == k - 1 ? 0 : (pr + 1));
    
    forn(i, sz(g[v]))
    {
        int to = g[v][i];
        if (to != pr) dfs(to, v);
    }
}

inline void solve()
{
    vector<pair<int, pt> > e;
    
    forn(i, k)
        forn(j, i)
            e.pb(mp(calc(i, j), mp(i, j)));         
            
    forn(i, k)
        e.pb(mp(n * m, mp(i, k)));
        
    k++;
    
    forn(i, k) dsu[i] = i;
    
    sort(all(e));
    
    int ans = 0;
    
    forn(i, sz(e))
    {
        int w = e[i].ft, x = e[i].sc.ft, y = e[i].sc.sc;
        
        if (unite(x, y))
        {
            ans += w;
            g[x].pb(y);
            g[y].pb(x);
        }
    }
    
    cout << ans << endl;
    dfs(k - 1, -1);
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
