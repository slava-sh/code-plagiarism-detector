#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;

#define mp make_pair
#define fi first
#define se second
#define pb push_back

#define FILE "secure"

const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-9;

const ll LLINF = 1ll * INF * INF;
int n, m;
vector<int> a;
vector< vector< pair<pii, ll> > > g;
vector<ll> d;
set< pair<ll, int> > s;
vector<int> anc;
int ansX, ansY;

int main() {
#ifdef HAKU
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    g.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c, --u, --v;
        g[u].pb(mp(mp(u, v), c));
        g[v].pb(mp(mp(v, u), c));
    }

    for (int v = 0; v < n; ++v)
        if (a[v] == 1) {
            for (int i = 0; i < (int)g[v].size(); ++i) {
                int u = g[v][i].fi.se;
                if (a[u] != 1)
                    g[n].pb(g[v][i]);
            }
        }
    d.resize(n + 1, LLINF);
    d[n] = 0;
    for (int i = 0; i <= n; ++i)
        s.insert(mp(d[i], i));
    anc.resize(n + 1, -1);
    for (int i = 0; i <= n; ++i) {
        int v = s.begin()->se;
        s.erase(s.begin());
        for (int j = 0; j < (int)g[v].size(); ++j) {
            int u = g[v][j].fi.se, c = g[v][j].se;
            if (d[v] + c < d[u]) {
                s.erase(mp(d[u], u));
                d[u] = d[v] + c;
                s.insert(mp(d[u], u));
                anc[u] = g[v][j].fi.fi;
            }
        }
    }
    ansY = -1;
    for (int i = 0; i < n; ++i)
        if (a[i] == 2 && (ansY == -1 || d[i] < d[ansY]))
            ansY = i;
    if (d[ansY] == LLINF) {
        cout << -1 << "\n";
    } else {
        ansX = anc[ansY];
        while (a[ansX] != 1)
            ansX = anc[ansX];
        cout << ansX + 1 << " " << ansY + 1 << " " << d[ansY] << "\n";
    }
    return 0;
}
