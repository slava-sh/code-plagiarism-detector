#include <bits/stdc++.h>
#define dout if (true) cout

using namespace std;

typedef long long ll;

const ll INF = 1e15;

char used[444444];
ll n, m, d, a, b, c, q;

struct Edge{
    ll to, t, num;
    Edge(ll _to, ll _t, ll _num) {
        to = _to;
        t = _t;
        num = _num;
    } Edge() {}
};

struct T {
    ll v, t, depth;
    T(ll _v, ll _t, ll _d) {
        v = _v;
        t = _t;
        depth = _d;
    } T() {}
};

vector<Edge> g[111111];

ll bfs(ll from, ll last) {
    queue<T> q;
    q.push(T(from, INF, 0));
    while (!q.empty()) {
        ll v = q.front().v;
        ll t = q.front().t;
        ll depth = q.front().depth;
        if (v == last) {
            return depth;
        }
        q.pop();
        for (int i = 0; i < g[v].size(); i++) {
            if (used[g[v][i].num] < 2 && (t == INF || abs(t-g[v][i].t) <= d)) {
                q.push(T(g[v][i].to, g[v][i].t, depth+1));
            }
        }
    }
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a].push_back(Edge(b, c, i));
        g[b].push_back(Edge(a, c, 200000+i));
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 444444; j++)
            used[j] = 0;
        cin >> a >> b;
        cout << bfs(a, b) << endl;
    }
}

