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

int a[N], d[N];
vector <pr> g[N];
priority_queue <pr> q;
bool used[N];

int main()
{
    assert(freopen(problem".in", "r", stdin) != NULL);
    assert(freopen(problem".out", "w", stdout));

    int n, m;
    cin >> n >> m;
    int k_1 = 0, k_2 = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] == 1) {
            ++k_1;
        }
        if (a[i] == 2) {
            ++k_2;
        }
    }
    int p;
    if (k_1 < k_2) {
        p = 1;
    }
    else {
        p = 2;
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
        if (a[v] == p) {
            q.push(pr(v, 0));
            for (int i = 0; i < n; ++i) {
                d[i] = inf;
                used[i] = 0;
            }
            d[v] = 0;
            int t = 0;
            while(!q.empty() && t < n) {
                int x = q.top().v;
                int dd = -q.top().x;
                q.pop();
                if (used[x] || dd > d[x]) {
                    continue;
                }
                if (!used[x]) {
                    used[x] = 1;
                    ++t;
                }
                if (a[x] == 3 - p) {
                    break;
                }
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
                if (a[u] == 3 - p && ans > d[u]) {
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
    if (p == 1) {
        printf("%d %d %d\n", ans_u + 1, ans_v + 1, ans);
    }
    else {
        printf("%d %d %d\n", ans_v + 1, ans_u + 1, ans);
    }
    return 0;
}
