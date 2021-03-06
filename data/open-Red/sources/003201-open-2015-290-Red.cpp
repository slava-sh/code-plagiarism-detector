#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct edge
{
    int v;
    int t;
    int i;
    edge(int _v, int _t, int _i)
    {
        v = _v;
        t = _t;
        i = _i;
    }
};

int n, m;
vector<vector<edge> > graph;
vector<vector<int> > edge_graph;

void build_edge_graph(int t)
{
    edge_graph.resize(2 * m);
    for (int i = 0; i < n; i++)
    {
        for (edge e : graph[i])
        {
            for (edge u : graph[e.v])
            {
                if (abs(u.t - e.t) <= t)
                    edge_graph[e.i].push_back(u.i);
            }
        }
    }
}

#define INF 1791791

vector<vector<int> > dist;

void bfs(int s)
{
    dist[s].assign(2 * m, INF);
    dist[s][s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : edge_graph[u])
        {
            if (dist[s][v] == INF)
            {
                dist[s][v] = dist[s][u] + 1;
                q.push(v);
            }
        }
    }
}

void precalc()
{
    dist.resize(2 * m, vector<int>(2 * m, INF));
    for (int i = 0; i < 2 * m; i++)
    {
        dist[i][i] = 0;
        for (int u : edge_graph[i])
            dist[i][u] = min(dist[i][u], 1);
    }
    for (int k = 0; k < 2 * m; k++)
    {
        for (int i = 0; i < 2 * m; i++)
        {
            for (int j = 0; j < 2 * m; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int get_ans(int a, int b)
{
    int mn = INF;
    if (graph[a].size() > graph[b].size())
        swap(a, b);
    for (edge u : graph[a])
    {
        for (edge v : graph[b])
            mn = min(mn, dist[u.i][v.i]);
    }
    if (mn == INF)
        return -1;
    return mn;
}

int main()
{
    int d;
    cin >> n >> m >> d;
    graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        graph[u - 1].push_back(edge(v - 1, t, i));
        graph[v - 1].push_back(edge(u - 1, t, i + m));
    }
    build_edge_graph(d);
    precalc();
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << get_ans(a - 1, b - 1) << endl;
    }
    return 0;
}
