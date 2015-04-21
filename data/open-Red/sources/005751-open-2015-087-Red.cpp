#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <queue>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

struct edge{
    int b, e, t;
};

const int INF = 1000000007;

vector<edge> e;
vector<vector<int> > a;
int k[200200];

void add_edge(int x, int y, int t) {
    edge e1 = {x, y, t};
    edge e2 = {y, x, t};
    a[x].pb(e.size());
    e.pb(e1);
    a[y].pb(e.size());
    e.pb(e2);
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n,m,d;
    scanf("%d%d%d", &n, &m, &d);
    a.resize(n+1);
    int d1,d2,d3;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &d1, &d2, &d3);
        add_edge(d1,d2,d3);
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &d1, &d2);
        for (int i = 0; i < e.size(); i++) k[i] = INF;
        queue<int> r;
        for (int i = 0; i < a[d1].size(); i++) {
            k[a[d1][i]] = 1;
            r.push(a[d1][i]);
        }
        while (!r.empty()) {
            int u = r.front();
            r.pop();
            int t = e[u].e;
            for (int i = 0; i < a[t].size(); i++) {
                if (abs(e[a[t][i]].t - e[u].t) <= d && k[a[t][i]] > k[u] + 1) {
                    k[a[t][i]] = k[u] + 1;
                    r.push(a[t][i]);
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < a[d2].size(); i++) {
            ans = min(ans, k[a[d2][i] ^ 1]);
        }
        if (ans == INF) ans = -1;
        printf("%d", ans);
    }
    return 0;
}
