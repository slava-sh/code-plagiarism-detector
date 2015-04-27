#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <utility>
#include <sstream>
#include <numeric>

#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cmath>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(v) do{cerr<<#v<<':';for(auto x:v) cerr << x << ','; cerr << '\n';}while(0)
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define ford1(i, n) for(int i = (int)(n); i>=1; --i)
#define fored(i, a, b) for(int i = (int)(b); i >= (int)(a); --i)
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define clr(v) memset(v, 0, sizeof(v))
#define clr1(v) memset(v, 0xFF, sizeof(v))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define op operator

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;

const int MOD = 1000000007;

int popcnt(int x) { return __builtin_popcount(x);}
int popcnt(u64 x) { return __builtin_popcountll(x);}
int ctz(int x) { return __builtin_ctz(x);}
int ctz(u64 x) { return __builtin_ctzll(x);}
int clz(int x) { return __builtin_clz(x);}
int clz(u64 x) { return __builtin_clzll(x);}
int ffs(int x) { return __builtin_ffs(x);}
int ffs(u64 x) { return __builtin_ffsll(x);}
int parity(int x) { return __builtin_parity(x);}
int parity(u64 x) { return __builtin_parityll(x);}
int gcd(int a, int b) { return __gcd(a,b); }
i64 gcd(i64 a, i64 b) { return __gcd(a,b); }
int lcm(int a, int b) { return a/__gcd(a,b)*b; }
i64 lcm(i64 a, i64 b) { return a/__gcd(a,b)*b; }

int add(int a, int b) { a += b; if(a>=MOD) a-= MOD; return a; }
int sub(int a, int b) { a -= b; if(a<0) a+= MOD; return a; }
int mul(int a, int b) { return (a*1ll*b) % MOD; }
inline int pow(int a, i64 n) { int r(1); while(n) { if(n&1) r=mul(r,a); n/=2; if(n)a=mul(a,a);} return r; }

template<class T> bool uax(T&a, const T& b) {
    if( a < b ) { a = b; return true; }
    return false;
}

template<class T> bool uin(T&a, const T& b) {
    if( a > b ) { a = b; return true; }
    return false;
}

const ld pi = acosl(-1.0);
const ld eps = 1e-9;

const int inf = 1e9 + 100500;
const int N = 1001;
const int M = 103;
char _a[N][N];
int a[N][N];
int u[N];
int d[N];
int p[N];
vi g[1001];

int dist(char *s, char *t, int len) {
    int r =0;
    forn(i, len) r += s[i] != t[i];
    return r;
}
int root;

void dfs(int v, int p) {
    if( v != root ) {
        if( p == root )
            printf("%d 0\n", v + 1);
        else
            printf("%d %d\n", v + 1, p + 1);
    }
    forn(j, g[v].size()) {
        if( g[v][j] != p) {
            dfs(g[v][j], v);
        }
    }
}

void solve() {
    int n, m, k, w;
    scanf("%d%d%d%d", &n, &m, &k, &w);
    forn(i, k) {
        forn(j, n) scanf(" %s", _a[i] + j * m);
    }
    //forn(i, k) puts(_a[i]);
    forn(i, k) forn(j, i) a[j][i] = a[i][j] = dist(_a[i], _a[j], n * m) * w;
    forn(i, k) a[i][k] = a[k][i] = n * m;
    ++k;
    forn(i, k) d[i] = inf;
    forn(i, k) p[i] = -1;
    d[k-1] =0;
    int ans = 0;
    forn(i, k) {
        int v = -1;
        forn(j, k) if( !u[j] && ( v == -1 || d[v] > d[j] ) )
            v = j;
        u[v] = 1;
        if( i ) {
            g[v].pb(p[v]);
            g[p[v]].pb(v);
        }
        ans += d[v];
        forn(u, k) if( d[u] > a[v][u] ) {
            d[u] = a[v][u];
            p[u] = v;
        }
    }
    printf("%d\n", ans);
    root = k-1;
    dfs(k-1, -1);
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
	cout << fixed;
	cout.precision(15);
	cerr << fixed;
	cerr.precision(15);
    solve();
    return 0;
}
