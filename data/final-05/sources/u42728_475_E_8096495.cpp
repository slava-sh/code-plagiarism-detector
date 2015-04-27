//Template
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <ios>
#include <iomanip>
#include <ctime>
#include <numeric>
#include <functional>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <cstdarg>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
#define pair(x, y) make_pair(x, y)
#define runtime() ((double)clock() / CLOCKS_PER_SEC)

inline int read() {
    static int r, sign;
    static char c;
    r = 0, sign = 1;
    do c = getchar(); while (c != '-' && (c < '0' || c > '9'));
    if (c == '-') sign = -1, c = getchar();
    while (c >= '0' && c <= '9') r = r * 10 + (int)(c - '0'), c = getchar();
    return sign * r;
}

template <typename T>
inline void print(T *a, int n) {
    for (int i = 1; i < n; ++i) cout << a[i] << " ";
    cout << a[n] << endl;
}
#define PRINT(_l, _r, _s, _t) { cout << #_l #_s "~" #_t #_r ": "; for (int _i = _s; _i != _t; ++_i) cout << _l _i _r << " "; cout << endl; }

#define N 2000
struct edge {
    int next, node;
} e[N << 1 | 1];
int head[N + 1], tot = 0;

inline void addedge(int a, int b) {
    e[++tot].next = head[a];
    head[a] = tot, e[tot].node = b;
}

int n, m, con[N + 1][N + 1], low[N + 1], dfn[N + 1], q[N + 1], top = 0, cnt = 0;
int belong[N + 1], bc = 0, size[N + 1];
bool inq[N + 1], nc[N + 1][N + 1];

void dfs(int x, int f) {
    low[x] = dfn[x] = ++cnt;
    for (int node = 1; node <= n; ++node) {
        if (!con[x][node]) continue;
        if (!dfn[node]) {
            dfs(node, x);
            low[x] = min(low[x], low[node]);
        } else if (node != f) {
            low[x] = min(low[x], dfn[node]);
        }
    }
    if (f > 0 && low[x] == dfn[x]) ++con[f][x], ++con[x][f];
}

int sum[N + 1], inside[N + 1];

void dfs2(int x, int f) {
    sum[x] = size[x], inside[x] = 0;
    for (int i = head[x]; i; i = e[i].next) {
        int node = e[i].node;
        if (node == f) continue;
        dfs2(node, x);
        sum[x] += sum[node];
        inside[x] += sum[node] * size[x] + inside[node];
    }
}

void bfs(int x) {
    int h = 0, t = 0;
    q[t++] = x, belong[x] = bc, size[bc] = 1;
    while (h < t) {
        int cur = q[h++];
        for (int node = 1; node <= n; ++node) {
            if (con[cur][node] != 1 || belong[node]) continue;
            q[t++] = node, belong[node] = bc, ++size[bc];
        }
    }
}

bitset<N + 1> f;

int main(int argc, char *argv[]) {
#ifdef KANARI
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        con[x][y] = con[y][x] = true;
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
        if (!belong[i]) {
            ++bc;
            bfs(i);
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (con[i][j]) nc[belong[i]][belong[j]] = true;
    for (int i = 1; i <= bc; ++i)
        for (int j = i + 1; j <= bc; ++j)
            if (nc[i][j]) addedge(i, j), addedge(j, i);
    int _n = n;
    n = bc;
    
    int ans = 0;
    for (int x = 1; x <= n; ++x) {
        for (int i = 1; i <= n; ++i)
            sum[i] = inside[i] = 0;
        for (int i = head[x]; i; i = e[i].next)
            dfs2(e[i].node, x);
        f.reset();
        f[0] = 1;
        for (int i = head[x]; i; i = e[i].next)
            f |= f << sum[e[i].node];
        int cur = 0;
        for (int i = 0; i <= _n; ++i)
            if (f[i]) cur = max(cur, (i + size[x]) * (_n - i));
        cur -= size[x] * size[x];
        for (int i = head[x]; i; i = e[i].next)
            cur += inside[e[i].node];
        ans = max(ans, cur);
    }
    for (int i = 1; i <= n; ++i)
        ans += size[i] * size[i];
    printf("%d\n", ans);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
