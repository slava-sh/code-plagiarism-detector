#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 1011111111;

int n, m, d;
vector<int> g[max_n], t[max_n], dp[max_n], num[max_n];
set<pair<int, pair<int, int> > > q;

int my_abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int main() {
    scanf("%d%d%d", &n, &m, &d);
    while (m--) {
        int u, v, tt;
        scanf("%d%d%d", &u, &v, &tt);
        g[u].push_back(v);
        t[u].push_back(tt);
        g[v].push_back(u);
        t[v].push_back(tt);
        num[u].push_back(dp[v].size());
        num[v].push_back(dp[u].size());
        dp[u].push_back(inf);
        dp[v].push_back(inf);
    }
    scanf("%d", &m);
    while (m--) {
        q.clear();
        int st, fin;
        scanf("%d%d", &st, &fin);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
                dp[i][j] = inf;
                if (i == st) {
                    dp[i][j] = 0;
                }
                q.insert(make_pair(dp[i][j], make_pair(i, j)));
            }
        }
        int ans = inf;
        while (!q.empty()) {
            pair<int, pair<int, int> > p = *q.begin();
            q.erase(p);
            if (p.first == inf) {
                break;
            }
            int v = p.second.first;
            int last = t[v][p.second.second];
            if (v == fin) {
                ans = min(ans, p.first);
            }
            for (int i = 0; i < g[v].size(); ++i) {
                if (my_abs(last - t[v][i]) <= d) {
                    if (p.first + 1 < dp[g[v][i]][num[v][i]]) {
                        q.erase(make_pair(dp[g[v][i]][num[v][i]], make_pair(g[v][i], num[v][i])));
                        dp[g[v][i]][num[v][i]] = p.first + 1;
                        q.insert(make_pair(dp[g[v][i]][num[v][i]], make_pair(g[v][i], num[v][i])));
                    }
                }
            }
        }
        if (ans == inf) {
            ans = -1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
