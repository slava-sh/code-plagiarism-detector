#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <string.h>
#include <sstream>
#include <cmath>
#include <math.h>
#include <queue>
#include <deque>
#include <cassert>
#include <time.h>

#define forn(i,n) for (int i = 0; i < (int)n; i++)
#define fornd(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define forab(i,a,b) for (int i = (int)a; i <= (int)b; i++)
#define forabd(i, b, a) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define _(a, val) memset (a, val, sizeof (a))
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

#ifdef _DEBUG
#define dbg(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
#define dbgx(x) {cerr << #x << " = " << x << endl;}
#define dbgv(v) {cerr << #v << " = {"; for (typeof(v.begin()) it = v.begin(); it != v.end(); it ++) cerr << *it << ", "; cerr << "}"; cerr << endl;}
#else
#define dbg(...) { }
#define dbgx(x) { }
#define dbgv(v) { }
#endif

typedef long long lint;
typedef unsigned long long ull;
typedef long double ld;

const lint LINF = 1000000000000000000LL;
const int INF = 1000000000;
const long double eps = 1e-9;
const long double PI = 3.1415926535897932384626433832795l;

using namespace std;

void prepare (string s)
{
#ifdef _DEBUG
    freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
#else
    if (s.length() != 0)
    {
        freopen ((s + ".in").c_str(), "r", stdin);
        freopen ((s + ".out").c_str(), "w", stdout);
    }
#endif
}


int rank[1000110], p[1000110];
class DSU{
public:
    void pre_build(){
        for (int i = 0; i < 1000110; i++){
            rank[i] = 1;
            p[i] = i;
        }
    }

    int get_root (int a){
        if (p[a] != a)
            p[a] = get_root ( p[a] );
        return p[a];
    }

    void merge(int a, int b) {
        a = get_root ( a );
        b = get_root ( b );
        if (rank[a] > rank[b]){
            p[b] = a;
        }else{
            p[a] = b;
            if (rank[a] == rank[b])
                rank[b] ++;
        }
    }
};

struct edge
{
    int a, b, cost;
    edge() {}
    edge(int _a, int _b, int _cost)
    {
        a = _a;
        b = _b;
        cost = _cost;
    }
};

int n, m, k, w;
const int NMAX = 1005;
char lvl[NMAX][15][15];
vector<int> g[NMAX];
DSU dsu;
vector<edge> e;

void read()
{
    scanf("%d %d %d %d\n", &n, &m, &k, &w);
    forn(i, k)
        forn(j, n)
            scanf("%s", lvl[i][j]);
    
}

int go(int id1, int id2)
{
    int res = 0;
    forn(i, n)
    {
        forn(j, m)
        {
            if (lvl[id1][i][j] != lvl[id2][i][j])
                res ++;
        }
    }
    return res;
}

bool cmp(const edge &e1, const edge &e2)
{
    return e1.cost < e2.cost;
}

vector<pair<int, int> > parent;
void dfs(int v, int par)
{
    if (v > 0)
        parent.pb ( mp(v, par) );
    forn(i, sz(g[v]))
    {
        int u = g[v][i];
        if (u != par)
            dfs( u, v );
    }
}

void solve()
{
    for(int i = 0; i < k; i++)
    {
        e.pb ( edge(0, i + 1, n*m) );
        for(int j = i + 1; j < k; j++)
        {
            e.pb ( edge(i + 1, j + 1, go(i, j)*w) );
        }
    }
    
    sort(all(e), cmp);
    
    dsu.pre_build();
    int answer = 0;
    forn(i, sz(e))
    {
        if (dsu.get_root(e[i].a) != dsu.get_root(e[i].b))
        {
            answer += e[i].cost;
            dsu.merge(e[i].a, e[i].b);
            g[e[i].a].pb ( e[i].b );
            g[e[i].b].pb ( e[i].a );
        }
    }
    
    dfs( 0, -1 );
    printf("%d\n", answer);
    forn(i, sz(parent))
    {
        printf("%d %d\n", parent[i].first, parent[i].second);
    }
    printf("\n");
}

int main ()
{
    prepare ("");

    read();
    solve();

    return 0;
}
