#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment(linker, "/STACK:300000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

struct edge{
    int f,t,w;
};

int n,m,k,W;
vector <edge> e;
vector <vector <string> > f;

bool read(){
    if (!(cin >> n >> m >> k >> W)) return false;
    f.assign(k, vector <string> (n,""));
    forn(i,k){
        forn(j,n)
            cin >> f[i][j];
    }
    return true;
}

edge me(int f, int t, int w){
    edge res = {f,t,w};
    return res;
}

void add_edge(int f, int t, int w){
    e.pb(me(f,t,w));
    e.pb(me(t,f,w));
}

bool operator < (const edge &a, const edge &b){
    return a.w < b.w;
}

int dsu[2000], h[2000];

int getdsu(int x){
    return dsu[x] == x ? x : dsu[x] = getdsu(dsu[x]);
}

void unite(int x, int y){
    x = getdsu(x);
    y = getdsu(y);
    if (h[x] == h[y]){
        h[x]++;
        dsu[y] = x;
    }else{
        if (h[x] < h[y]){
            dsu[x] = y;
        }else{
            dsu[y] = x;
        }
    }
}

vector <vector <int> > g;
bool used[2000];
vector <pair <int,int> > ans;

void dfs(int v, int p = -1){
    used[v] = true;
    ans.pb(mp(v+1, p+1));
    forn(i,sz(g[v]))
        if (!used[g[v][i]])
            dfs(g[v][i], v);
}

void solve(){
    ans.clear();
    g.clear();
    g.resize(k);
    forn(i,k){
        dsu[i] = i;
        h[i] = 1;
    }
    forn(ff,k){
        forn(ss,ff){
            int cnt = 0;
            forn(i,n)
                forn(j,m)
                    if (f[ff][i][j]!=f[ss][i][j])
                        cnt++;
            int cost = cnt*W;
            if (cost <= n*m)
                add_edge(ff,ss,cost);
        }
    }
    int tot = 0;
    sort(all(e));
    memset(used, 0, sizeof used);
    forn(i,sz(e)){
        if (getdsu(e[i].f)!=getdsu(e[i].t)){
            tot += e[i].w;
            unite(e[i].f, e[i].t);
            g[e[i].f].pb(e[i].t);
            g[e[i].t].pb(e[i].f);
        }
    }
    forn(i,k)
        if (getdsu(i) == i){
            tot += n*m;
            dfs(i);
        }
    cout << tot << endl;
    forn(i,k)
        cout << ans[i].first << ' ' << ans[i].second << endl;
}

int main(){
#ifdef dudkamaster
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    while (read())
        solve();
    return 0;
}