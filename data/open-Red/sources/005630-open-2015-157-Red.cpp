#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;

typedef long long ll;

const int INF = 1234657890;

struct To {
    int u, w, i;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, D;
    scanf("%d%d%d", &n, &m, &D);

    vector<vector<To> > g(n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);

        --a;
        --b;

        g[a].push_back({b, w, i});
        g[b].push_back({a, w, m + i});
    }

    int q;
    scanf("%d", &q);

    for (int ii = 0; ii < q; ii++) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;

        {
            int ans = -1;
            vector<char> us(2 * m, false);
            queue<pair<int, pair<int, int> > > q;
            q.push(mp(a, mp(INF, 0)));
            while (!q.empty()) {
                int v = q.front().fi;
                int w = q.front().se.fi;
                int d = q.front().se.se;
                q.pop();

                if (v == b) {
                    ans = d;
                    break;
                }

                int l1, l2;
                {
                    int l = 0, r = (int)g[v].size();
                    while (l + 1 < r) {
                        int m = (l + r) / 2;
                        if (w - g[v][m].w > D) {
                            l = m;
                        } else {
                            r = m;
                        }
                    }
                    l1 = l;
                }
                {
                    int l = 0, r = (int)g[v].size();
                    while (l + 1 < r) {
                        int m = (l + r) / 2;
                        if (g[v][m].w - w > D) {
                            r = m;
                        } else {
                            l = m;
                        }
                    }
                    l2 = r;
                }
                if (w == INF) l1 = 0, l2 = (int)g[v].size();
                for (int i = l1; i < l2; i++) {
                    To to = g[v][i];
                    if (us[to.i] == false) {
                        if (w == INF || abs(w - to.w) <= D) {
                            us[to.i] = true;
                            q.push(mp(to.u, mp(to.w, d + 1)));
                        }
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
}
