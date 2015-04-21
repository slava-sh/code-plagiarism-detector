#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to;
    int temp;
};

int N, M, D;
vector< vector<Edge> > graph;

void query(int st, int fin) {
    map< pair<int, int>, int> dist;
    priority_queue< pair<int, pair<int, int> > > q;

    q.push(make_pair(0, make_pair(st, -1)));

    bool flag = true;
    while (!q.empty()) {
        int v = q.top().second.first, temp = q.top().second.second;
        int d0 = flag ? 0: q.top().first;
        q.pop();
        for (auto e: graph[v]) {
            int u = e.to, delta = abs(e.temp - temp);
            if (flag || delta <= D) {
                auto p = make_pair(u, e.temp);
                if (dist.find(p) == dist.end() || dist[p] > d0 + 1) {
                    q.push(make_pair(d0 + 1, p));
                    dist[p] = d0 + 1;
                    if (u == fin) {
                        cout << d0 + 1 << endl;
                        return;
                    }
                }
            }
        }
        flag = false;
    }
    cout << -1 << endl;
}

int main() {
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);

    cin >> N >> M >> D;
    graph.assign(N, vector<Edge>());
    for (int i = 0; i < M; i++) {
        int v, u, temp;
        cin >> v >> u >> temp;
        v--; u--;
        graph[v].push_back(Edge {u, temp});
        graph[u].push_back(Edge {v, temp});
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int st, fin;
        cin >> st >> fin;
        st--; fin--;
        query(st, fin);
    }
}
