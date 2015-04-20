#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pb push_back
#define in(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

const int N = 200 * 100 + 10;
vector <int> g[N], br;
bool us[N];
int d[N], ma, x[N], L[N], R[N];

bool dfs_bridge(int v, int u) {
    if(us[v])
        return false;
    us[v] = true;
    if(v == u) {
        br.pb(v);
        return true;
    }
    for(int i = 0; i < g[v].size(); i++)
        if(dfs_bridge(g[v][i], u)) {
            br.pb(v);
            return true;
        }

    return false;
}

void dfs(int cur, int pr) {
    for(int i = 0; i < g[cur].size(); i++)
        if(pr != g[cur][i]) {
            ma = max(ma, d[cur] + 1);
            d[g[cur][i]] = d[cur] + 1;
            dfs(g[cur][i], cur);
        }

}

bool dfs1(int cur, int pr1, int pr2) {
    for(int i = 0; i < g[cur].size(); i++)
        if(pr1 != g[cur][i] && pr2 != g[cur][i]) {
            ma = max(ma, d[cur] + 1);
            d[g[cur][i]] = d[cur] + 1;
            dfs1(g[cur][i], cur, pr2);
        }
}



int main() {
    in("dwarfs.in");
    out("dwarfs.out");
    int n, u, v, i, l, r, ans;
    cin >> n;
    for(i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> u >> v;
    dfs_bridge(u, v);

    i = br.size() - 1;
    dfs(br[i], br[i - 1]);
    x[i] = ma; ma = 0;

    dfs(br[0], br[1]);
    x[0] = ma; ma = 0;
    ans = min(x[0], x[i]);

    for(i = 1; i + 1 < (int)br.size(); i++) {
        dfs1(br[i], br[i - 1], br[i + 1]);
        x[i] = ma; ma = 0;
    }

    n = br.size() - 1;
    L[0] = x[0];
    for(i = 1; i < br.size(); i++)
        L[i] = max(L[i - 1], i + x[i]);
    R[n] = x[n];

    for(i = n - 1; i >= 0; i--)
        R[i] = max(R[i + 1], n - i + x[i]);
    for(i = 0; i < n; i++)
        ans = min(L[i], R[i]);
    cout << ans + 1;
}
