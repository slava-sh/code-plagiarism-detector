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

struct edge {
    int g, t, num;
    edge() {
    }
    edge(int g, int t, int num) : g(g), t(t), num(num) {
    }
};

int n, m, d;
vector<int> g[max_n], t[max_n], dp[max_n], num[max_n];
vector<edge> e[max_n], e2[max_n];
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
        e2[u].push_back(edge(v, tt, dp[v].size()));
        e2[v].push_back(edge(u, tt, dp[u].size()));
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
            e[i] = e2[i];
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
            //cout << v << " " << last << "  " << p.first << endl;
            for (int i = 0; i < e[v].size(); ++i) {
                if (my_abs(last - e[v][i].t) <= d) {
                    if (p.first + 1 < dp[e[v][i].g][e[v][i].num]) {
                        q.erase(make_pair(dp[e[v][i].g][e[v][i].num], make_pair(e[v][i].g, e[v][i].num)));
                        dp[e[v][i].g][e[v][i].num] = p.first + 1;
                        q.insert(make_pair(dp[e[v][i].g][e[v][i].num], make_pair(e[v][i].g, e[v][i].num)));
                    }
                    swap(e[v][i], e[v].back());
                    e[v].pop_back();
                    --i;
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
