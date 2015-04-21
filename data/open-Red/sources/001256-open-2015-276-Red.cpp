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

bool operator < (const Edge &a, const Edge &b) {
    return a.t < b.t;
}

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
        if (t == INF) {
            for (int i = 0; i < g[v].size(); i++) {
                ++used[g[v][i].num];
                q.push(T(g[v][i].to, g[v][i].t, depth+1));
            }
        } else {
            ll minimal = t-d;
            ll maximal = t+d;
            //cout << "FOR v = " << v << " and t = " << t << " and d = " << d << endl;
            ll minpos = lower_bound(g[v].begin(), g[v].end(), Edge(0, minimal, 0)) - g[v].begin();
            ll maxpos = upper_bound(g[v].begin(), g[v].end(), Edge(0, maximal, 0)) - g[v].begin();
            //cout << "MINPOS: " << minpos << endl;
            //cout << "MAXPOS: " << maxpos << endl;
            //cout << "MINTEMP: " << g[v][minpos].t << endl;
            //cout << "MAXTEMP: " << g[v][maxpos].t << endl;
            for (int i = minpos; i < maxpos; i++) {
                if (used[g[v][i].num] < 2) {
                    ++used[g[v][i].num];
                    q.push(T(g[v][i].to, g[v][i].t, depth+1));
                }
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
    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end()); // USE BINSEARCH + POSSIBLY MEMO

    cin >> q;
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 444444; j++)
            used[j] = 0;
        cin >> a >> b;
        cout << bfs(a, b) << endl;
    }
}

