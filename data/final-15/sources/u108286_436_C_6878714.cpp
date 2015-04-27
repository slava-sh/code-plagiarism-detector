/**************************************************
 *        Problem:  
 *         Author:  clavichord93
 *          State:  
 **************************************************/

/**************************************************
 * Header
 **************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <climits>
#include <cassert>
#include <cmath>
#include <string>
#include <bitset>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <limits>
#define Fill(a, b) memset(a, b, sizeof(a))
#define Copy(a, b) memcpy(a, b, sizeof(b))
#define NPOS string::npos
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define erep(j, a) for (Edge *j = a; j; j = j->next)
#define irep(i, a) for (__typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define srep(sub, s) for (int sub = s & (s - 1); sub; sub = (sub - 1) & s)
#define sqr(a) ((a) * (a))
#define R(x) scanf("%d", &x)
#define SS(a, b) scanf("%d %d", &a, &b)
#define SSS(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define O(x) pf("%d\n", x)
#define TEST int T;scanf("%d", &T);for (int cas = 1; cas <= T; cas++)
#define sf scanf
#define pf printf
#define pb push_back
#define ppb pop_back
#define pft push_front
#define ppf pop_front
#define mp make_pair
#define vec vector
#define it iterator
#define fir first
#define sec second
#define x first
#define y second
#define all(a) a.begin(),a.end()
#define sz(a) (int)(a.size())
#define bg(a) (a).begin()
#define en(a) (a).end()
#define clr(a) (a).clear()
#define dbg(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define bit_cnt(x) __builtin_popcount((unsigned)x)
#define gcd(a, b) __gcd(a, b)
#define sqr(a) ((a) * (a))
#define lch(t) (t << 1)
#define rch(t) (t << 1 | 1)
#define inf numeric_limits<int>::max()
#define finf numeric_limits<double>::infinity()
using namespace std;
template<class T> inline bool gmin(T &a, T b) { if (a > b) return a = b, true; return false; }
template<class T> inline bool gmax(T &a, T b) { if (a < b) return a = b, true; return false; }
template<class T> T exgcd(T a, T b, T &x, T &y) { if (!b) return x = (T)1, y = (T)0, a; else { T d = exgcd(b, a % b, y, x); return y -= a / b * x, d; } }
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<double, double> pdd;
typedef pair<double, pdd> pddd;
typedef vec<int> vi;
typedef vec<double> vd;
typedef vec<pii> vii;
typedef vec<pdd> vdd;
typedef istringstream iss;
typedef ostringstream oss;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = 1e10;
const double EPS = 1e-9;
const double PI = 3.14159265358979323846264338327950288;
const double TAU = 2.0 * PI;
inline int sgn(const double &a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int lowbit(int i) { return i & (-i); }
struct Initializer { Initializer() { ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); } } initializer;

/**************************************************
 * Templates
 **************************************************/



/**************************************************
 * Main
 **************************************************/

const int MAXN = 1005;
const int MAXM = 15;

int n, m, k, w;
int d[MAXN], p[MAXN];
int edge[MAXN][MAXN];
bool vis[MAXN];
int ans;
int ansx[MAXN];
char s[MAXN][MAXM][MAXM];

int dist(int x, int y) {
    int ret = 0;
    rep (i, 1, m) rep (j, 1, n) if (s[x][i][j] != s[y][i][j]) ret++;
    return ret;
}

int main() {
    sf("%d %d %d %d", &m, &n, &k, &w);
    rep (i, 1, k) {
        rep (j, 1, m) sf("%s", s[i][j] + 1);
    }

    rep (i, 1, k) edge[0][i] = m * n;
    rep (i, 1, k) rep (j, i + 1, k) {
        edge[i][j] = edge[j][i] = dist(i, j) * w;
    }

    Fill(d, 0x3f);
    Fill(vis, 0);
    d[0] = 0;
    rep (i, 0, k) {
        int mind = INF, minj = -1;
        rep (j, 0, k) if (!vis[j] && d[j] < mind) mind = d[j], minj = j;
        if (minj == -1) break;
        vis[minj] = 1;
        ans += mind;
        ansx[i] = minj;
        rep (j, 0, k) if (!vis[j] && d[j] > edge[minj][j]) d[j] = edge[minj][j], p[j] = minj;
    }

    pf("%d\n", ans);
    rep (i, 1, k) pf("%d %d\n", ansx[i], p[ansx[i]]);

    return 0;
}

/*
const int main_stack = 16;
char my_stack[128<<20];

int main() {
    __asm__("movl %%esp, (%%eax);\n"::"a"(my_stack):"memory");
    __asm__("movl %%eax, %%esp;\n"::"a"(my_stack + sizeof(my_stack) - main_stack):"%esp");
    Main();
    __asm__("movl (%%eax), %%esp;\n"::"a"(my_stack):"%esp");
    return 0;
}
*/
