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

#define INF 1791791791

vector<int> dist;

void bfs(int s)
{
    dist.assign(2 * m, INF);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : edge_graph[u])
        {
            if (dist[v] == INF)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
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
        bfs(u.i);
        for (edge v : graph[b])
            mn = min(mn, dist[v.i]);
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
