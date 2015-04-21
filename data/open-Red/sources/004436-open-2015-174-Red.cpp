#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to;
    int temp;
    int number;
};

int N, M, D;
vector< vector<Edge> > graph;

void query(int st, int fin) {
    map< pair<int, int>, int> dist;
    deque< pair<int, int> > q;

    q.push_back(make_pair(st, -1));
    dist[make_pair(st, -1)] = 0;

    bool flag = true;
    while (!q.empty()) {
        int v = q.front().first, temp = q.front().second;
        q.pop_front();
        for (auto e: graph[v]) {
            int u = e.to, delta = abs(e.temp - temp), number = e.number;
            if (flag || delta <= D) {
                auto p = make_pair(u, e.temp);
                if (dist.find(p) == dist.end()) {
                    q.push_back(p);
                    dist[p] = dist[make_pair(v, temp)] + 1;
                    if (u == fin) {
                        cout << dist[p] << endl;
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
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);

    cin >> N >> M >> D;
    graph.assign(N, vector<Edge>());
    for (int i = 0; i < M; i++) {
        int v, u, temp;
        cin >> v >> u >> temp;
        v--; u--;
        graph[v].push_back(Edge {u, temp, i});
        graph[u].push_back(Edge {v, temp, i});
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
