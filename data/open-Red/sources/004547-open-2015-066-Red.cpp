#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define prev prev_
#define next next_

const int INF = (int)1e9;

int abs_(int x) {
    return max(x, -x);
}

int main() {
    #define task "a"
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, D;
    cin >> n >> m >> D;
    vector<vector<int> > g(n + 1);
    vector<vector<int> > g2(m * 2);
    vector<int> t(m * 2);
    vector<int> v(m * 2);
    vector<int> u(m * 2);
    for (int i = 0; i < m; i++) {
        cin >> v[i * 2] >> u[i * 2] >> t[i * 2];
        t[i * 2 + 1] = t[i * 2];
        v[i * 2 + 1] = u[i * 2];
        u[i * 2 + 1] = v[i * 2];
    }
    for (int i = 0; i < 2 * m; i++) {
        g[v[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (auto v1 : g[i]) {
            for (auto u1 : g[i]) {
                if (v1 != u1 && abs_(t[v1] - t[u1]) <= D) {
                    g2[v1 ^ 1].push_back(u1);
                    g2[u1].push_back(v1 ^ 1);
                }
            }
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        vector<int> d(m * 2, INF);
        queue<int> q;
        for (auto v : g[a]) {
            d[v] = 1;
            q.push(v);
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto u : g2[v]) {
                if (d[u] > d[v] + 1) {
                    d[u] = d[v] + 1;
                    q.push(u);
                }
            }
        }
        int ans = INF;
        for (auto u : g[b]) {
            ans = min(ans, d[u ^ 1]);
        }
        if (ans == INF) {
            ans = -1;
        }
        cout << ans << endl;
    }
    return 0;
}
