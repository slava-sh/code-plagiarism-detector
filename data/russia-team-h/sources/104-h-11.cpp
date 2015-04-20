#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <queue>

#define problem "secure"

using namespace std;

struct pr {
    int v, x, h1, h2;
    pr(int _v = 0, int _x = 0, int _h1 = 0, int _h2 = 0): v(_v), x(_x), h1(_h1), h2(_h2) {}
    bool operator < (pr a) const {
        return x < a.x || (x == a.x && v < a.v);
    }
};

const int N = 5050;
const int inf  = 1e9;

int a[N], d[N];
vector <pr> g[N];
priority_queue <pr> q;
bool used[N];
pair<int, int> p[N];

int main()
{
    assert(freopen(problem".in", "r", stdin) != NULL);
    assert(freopen(problem".out", "w", stdout));

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        --u; --v;
        int l = u, r = v;
        if (a[u] == 1) {
            u = n;
        }
        if (a[u] == 2) {
            u = n + 1;
        }
        if (a[v] == 1) {
            v = n;
        }
        if (a[v] == 2) {
            v = n + 1;
        }
        if (u != v) {
            g[u].push_back(pr(v, c, l, r));
            g[v].push_back(pr(u, c, l, r));
        }
    }
    int v = n;
    q.push(pr(v, 0));
    for (int i = 0; i < n + 2; ++i) {
        d[i] = inf;
        used[i] = 0;
    }
    d[v] = 0;
    while(!q.empty()) {
        int x = q.top().v;
        int dd = -q.top().x;
//        printf("%d %d\n", x, dd);
        q.pop();
        if (used[x] || dd > d[x]) {
            continue;
        }
        used[x] = 1;
//                printf("%d %d\n", x, dd);
        for (int i = 0; i < (int) g[x].size(); ++i) {
            pr u = g[x][i];
            if (!used[u.v] && d[x] + u.x < d[u.v]) {
                d[u.v] = d[x] + u.x;
                q.push(pr(u.v, -d[u.v]));
                p[u.v] = make_pair(g[x][i].h1, g[x][i].h2);
            }
        }
    }
    if (d[n + 1] >= inf) {
        printf("-1\n");
        return 0;
    }
    int ans_v = p[n + 1].second;
    v = n + 1;
    q.push(pr(v, 0));
    for (int i = 0; i < n + 2; ++i) {
        d[i] = inf;
        used[i] = 0;
    }
    d[v] = 0;
    while(!q.empty()) {
        int x = q.top().v;
        int dd = -q.top().x;
//        printf("%d %d\n", x, dd);
        q.pop();
        if (used[x] || dd > d[x]) {
            continue;
        }
        used[x] = 1;
//                printf("%d %d\n", x, dd);
        for (int i = 0; i < (int) g[x].size(); ++i) {
            pr u = g[x][i];
            if (!used[u.v] && d[x] + u.x < d[u.v]) {
                d[u.v] = d[x] + u.x;
                q.push(pr(u.v, -d[u.v]));
                p[u.v] = make_pair(g[x][i].h1, g[x][i].h2);
            }
        }
    }
    int ans_u = p[n].second;
    printf("%d %d %d\n", ans_u + 1, ans_v + 1, d[n]);
    return 0;
}
