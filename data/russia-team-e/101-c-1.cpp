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

#define FILE "dwarfs"

const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-9;

const int MAXN = 200 * 1000 + 5;
vector<int> g[MAXN], path;
int v0, u0, dep[MAXN];
char used[MAXN];

bool dfs0(int v) {
    used[v] = true;
    if(v == v0) {
        path.pb(v);
        return true;
    }
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if(!used[u] && dfs0(u)) {
            path.pb(v);
            return true;
        }
    }
    return false;
}

int dfs1(int v) {
    used[v] = true;
    int res = 0;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if(!used[u])
            res = max(res, dfs1(u));
    }
    return res + 1;
}

int main() {
#ifdef HAKU
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].pb(u);
        g[u].pb(v);
    }
    cin >> v0 >> u0;
    v0--;
    u0--;
    dfs0(u0);
    for(size_t i = 0; i < g[v0].size(); i++) {
        int u = g[v0][i];
        if(u == path[1]) {
            swap(g[v0][i], g[v0].back());
            g[v0].pop_back();
            break;
        }
    }
    for(int i = 1; i < (int)path.size() - 1; i++)
        for(size_t j = 0; j < g[path[i]].size(); j++) {
            int u = g[path[i]][j];
            if(u == path[i - 1]) {
                swap(g[path[i]][j], g[path[i]].back());
                g[path[i]].pop_back();
            }
            else if(u == path[i + 1]) {
                swap(g[path[i]][j], g[path[i]].back());
                g[path[i]].pop_back();
            }
        }
    for(size_t i = 0; i < g[u0].size(); i++) {
        int u = g[u0][i];
        if(u == path[(int)path.size() - 2]) {
            swap(g[u0][i], g[u0].back());
            g[u0].pop_back();
            break;
        }
    }
    for(int i = 0; i < n; i++)
        used[i] = false;
    for(size_t i = 0; i < path.size(); i++)
        dep[i] = dfs1(path[i]);
    int md = 0, ans = 0;
    for(int i = 1; i < (int)path.size(); i++) {
        ans = max(ans, min(md + dep[md], (int)path.size() - i - 1 + dep[i]));
        if(dep[i] > md)
            md = i;
    }
    cout << ans << '\n';
    return 0;
}
