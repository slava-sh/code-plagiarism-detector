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

#define FILE "binary"

const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-9;

const int MAXN = 1000 + 5;
vector<int> g[2][MAXN];
char col[MAXN];

bool dfs(int v, int c) {
    col[v] = c;
    bool b = true;
    for(size_t i = 0; i < g[0][v].size(); i++) {
        int u = g[0][v][i];
        if(!col[u])
            b = b && dfs(u, c);
        else if(col[u] != col[v])
            return false;
    }
    for(size_t i = 0; i < g[1][v].size(); i++) {
        int u = g[1][v][i];
        if(!col[u])
            b = b && dfs(u, (c ^ 1));
        else if(col[u] == col[v])
            return false;
    }
    return b;
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
    int z;
    cin >> z;
    if(z > 0) {
        cout << 0 << '\n';
        return 0;
    }
    for(int i = 1; i < n; i++) {
        cin >> z;
        for(int j = 0; j < z; j++)
            if(i + j >= n) {
                cout << 0 << '\n';
                return 0;
            }
            else {
                g[0][j].pb(i + j);
                g[0][i + j].pb(j);
            }
        if(z >= 0 && i + z < n) {
            g[1][z].pb(i + z);
            g[1][i + z].pb(z);
        }
    }
    int comp = 0;
    for(int i = 0; i < n; i++)
        if(!col[i]) {
            if(dfs(i, 2))
                comp++;
            else {
                cout << 0 << '\n';
                return 0;
            }
        }
    ll ans = 1;
    for(int i = 0; i < comp; i++)
        ans = (2 * ans) % MOD;
    cout << ans << '\n';
    return 0;
}
