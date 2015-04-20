#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <queue>

#define problem "secure"

using namespace std;

struct pr {
    int v, x;
    pr(int _v = 0, int _x = 0): v(_v), x(_x) {}
    bool operator < (pr a) const {
        return x < a.x || (x == a.x && v < a.v);
    }
};
const int N = 5050;
const int inf  = 1e9;

int a[N];
vector <pr> g[N];

int main()
{
    assert(freopen(problem".in", "r", stdin) != NULL);
    assert(freopen(problem".out", "w", stdout));

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        --u; --v;
        g[u].push_back(pr(v, c));
        g[v].push_back(pr(u, c));
    }
    int ans = inf;
    int ans_u, ans_v = 1;
    for (int v = 0; v < n; ++v) {
        if (a[v] == 1) {
            priority_queue <pr> q;
            q.push(pr(v, 0));
            vector <int> d(n, inf);
            d[v] = 0;
            vector <bool> used(n, 0);
            while(!q.empty()) {
                int x = q.top().v;
                int dd = -q.top().x;
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
                    }
                }
            }
            for (int u = 0; u < n; ++u) {
                if (a[u] == 2 && ans > d[u]) {
                    ans = d[u];
                    ans_u = v;
                    ans_v = u;
                }
            }
        }

    }
    if (ans >= inf) {
        printf("-1\n");
        return 0;
    }
    printf("%d %d %d\n", ans_u + 1, ans_v + 1, ans);
    return 0;
}
