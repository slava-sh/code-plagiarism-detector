/*
ID:     hewifi1
PROG:   [pro]
LANG:   C++
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
typedef long long ll;
const int _N = 10 + 2;
const int _M = 1000 + 10;
struct Map {
    char s[_N][_N];
};
struct Edge {
    int u, v, len, typ;
    Edge() {
    }
    Edge(int _u, int _v, int _len, int _typ) {
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
int n, m, fa[_M];
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
    
    ll ans = n * m;
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
/*
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
typedef long long ll;
const int _N = 10 + 2;
const int _M = 1000 + 10;
struct Map {
    char s[_N][_N];
};
struct Edge {
    int u, v, len, typ;
    Edge() {
    }
    Edge(int _u, int _v, int _len, int _typ) {
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
int n, m, fa[_M];
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
    
    ll ans = n * m;
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
*/