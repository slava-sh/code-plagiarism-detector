#if 1
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;

const LD eps = 1e-9;
const LD pi = acos(-1.0);
const LL inf = 1e+9;

#define mp make_pair
#define pb push_back
#define X first
#define Y second

#define dbg(x) { cerr << #x << " = " << x << endl; }

// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> istream & operator >> (istream &, vector<T> &);
template<typename T> ostream & operator << (ostream &, const vector<T> &);

#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;

#define NAME "problem"

int dp[2000];
void dinit() { forn(i, 2000) dp[i] = i; }
int dfind(int x) { return dp[x] == x ? x : dp[x] = dfind(dp[x]); }
void dunion(int x, int y) { dp[dfind(x)] = dfind(y); }

int n, m, k, w;
char a[2000][20][20];

int dd(int x, int y)
{
    int cnt = 0;
    forn(i, n)
        forn(j, m)
            cnt += a[x][i][j] != a[y][i][j];
    return cnt;
}

struct edge_t
{
    int u, v, w;
    edge_t(int u, int v, int w) : u(u), v(v), w(w) {}
    friend bool operator < (const edge_t &a, const edge_t &b)
    {
        return mp(mp(a.w, a.u), a.v) <  mp(mp(b.w, b.u), b.v);
    }
};

void dfs(const vvi &g, int s, vi &used, int prev = -1)
{
    used[s] = true;
    printf("%d %d\n", s + 1, prev + 1);
    forn(i, g[s].size())
    {
        int to = g[s][i];
        if (!used[to])
            dfs(g, to, used, s);
    }
}

void solve()
{
    scanf("%d %d %d %d\n", &n, &m, &k, &w);
    forn(t, k)
        forn(i, n)
            gets(a[t][i]);

    const int nm = n * m;


    vector<edge_t> edges;
    edges.reserve(k * k);
    forn(i, k)
        for (int j = i + 1; j < k; ++j)
        {
            int d = dd(i, j) * w;
            if (d < nm)
                edges.push_back(edge_t(i, j, d));
        }

    sort(all(edges));

    LL res = 0;
    vector<pii> mst;
    dinit();
    forn(i, edges.size())
    {
        int u = edges[i].u;
        int v = edges[i].v;
        if (dfind(u) != dfind(v))
        {
            dunion(u, v);
            mst.push_back(mp(u, v));
            res += edges[i].w;
        }
    }

    vvi g(k);
    forn(i, mst.size())
    {
        g[mst[i].X].push_back(mst[i].Y);
        g[mst[i].Y].push_back(mst[i].X);
    }

    int comps = 0;
    forn(i, k)
        comps += dp[i] == i;

    res += LL(comps) * n * m;

    printf("%I64d\n", res);

    vi used(k, false);
    forn(i, k)
        if (!used[i])
            dfs(g, i, used);

}

int main()
{
    START
    // freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    //freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
 
    solve();

    END
    return 0;
}
/*******************************************
*******************************************/

template<typename T> istream & operator >> (istream &is, vector<T> &v)
{
    forn(i, v.size())
        is >> v[i];
    return is;
}
template<typename T> ostream & operator << (ostream &os, const vector<T> &v)
{
    forn(i, v.size())
        os << v[i] << " ";
    return os;
}
#endif