#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
const int _N = 10 + 2;
const int _M = 1000 + 10;

const int MAX_N = 1007;
const long long INF = 1LL<<61;

long long ans;
long long cost[MAX_N];
bool use[MAX_N];
int typ[MAX_N][MAX_N];
long long d[MAX_N][MAX_N];

int n, m;
vector<int> ord; 
int k;
int pre[MAX_N];

void prim() {
    for (int i = 0; i <= k; ++i) {
        cost[i] = INF;
        use[i] = false;
    }
    cost[1] = 0;
    ans = 0;
    while (true) {
        int v = -1;
        for (int u = 1; u <= k; ++u) {
            if (!use[u] && (v == -1 || cost[u] < cost[v]))
                v = u;
        }
        if (v == -1) break;
        use[v] = true;
        ord.push_back(v);
        ans += cost[v];
        for (int u = 1; u <= k; ++u) {
            if (u == v) continue;
            if (d[v][u] < cost[u]) {
                cost[u] = d[v][u];
                pre[u] = v;
            }
        }
    }
    ans += n * m;
    printf("%I64d\n", ans);
    for (int i = 0; i < ord.size(); ++i) {
        printf("%d ", ord[i]);
        if (typ[ord[i]][pre[ord[i]]] == 0) 
            printf("%d\n", 0);
        else printf("%d\n", pre[ord[i]]);
    }
}

struct Map {
    char s[_N][_N];
};
struct Edge {
    int u, v, typ;
    long long len;
    Edge() {
    }
    Edge(int _u, int _v, long long _len, int _typ) {
        u = _u;
        v = _v;
        len = _len;
        typ = _typ;
    }
};

std::vector<Edge> eg;
std::vector<int> e[_M];
std::vector<int> out1, out2;
std::queue<int> Q;

Map map[_M];
int fa[_M];
int vis[_M];

int dis(int idx, int idy) {
    int re = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (map[idx].s[i][j] != map[idy].s[i][j])
                ++re;
    return re;
}

int find(int x) {
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
}

bool cmp(const Edge& a, const Edge& b) {
    return a.len < b.len;
}

void dfs(int u, int fa) {
    printf("%d %d\n", u + 1, fa + 1);
    vis[u] = 1;
    for (int i = 0; i < e[u].size(); ++i)
        if (!vis[e[u][i]])
            dfs(e[u][i], u);
}

int main() {
    //freopen("[pro].in","r",stdin);
    //freopen("[pro].out","w",stdout);
    int K, w;
    scanf("%d%d%d%d", &n, &m, &K, &w);
    for (int i = 0; i < K; ++i) 
        for (int j = 0; j < n; ++j)
            scanf("%s", map[i].s[j]);
    int v;
    for (int i = 0; i < K; ++i)
        for (int j = 0; j < K; ++j) {
            if (i == j)
                continue;
            v = dis(i, j);
            if (v * w < n * m)
                eg.push_back(Edge(i, j, v * w, 1));
            else
                eg.push_back(Edge(i, j, n * m, 0));
        }
    
    std::sort(eg.begin(), eg.end(), cmp);
    
    ll ans = (long long)n * m;
    for (int i = 0; i < K; ++i)
        fa[i] = i;
    for (int i = 0; i < eg.size(); ++i)
        if (find(eg[i].u) != find(eg[i].v)) {
            ans += eg[i].len;
            if (eg[i].typ == 1) {
                e[eg[i].u].push_back(eg[i].v);
                e[eg[i].v].push_back(eg[i].u);
            }
            Union(eg[i].u, eg[i].v);
        }
    
    std::cout << ans << std::endl;  
    for (int i = 0; i < K; ++i)
        if (vis[i] == 0)
            dfs(i, -1);
    return 0;
}