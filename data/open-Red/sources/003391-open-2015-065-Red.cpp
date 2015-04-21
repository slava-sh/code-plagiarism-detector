#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int inf = 1000000000;

struct edge
{
    int from, to, t, id;
};

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);

    vector <edge> E(2 * m);
    for (int i = 0; i < m; i++)
    {
        edge tmp;
        scanf("%d%d%d", &tmp.from, &tmp.to, &tmp.t);
        --tmp.from, --tmp.to;
        tmp.id = i * 2;
        E[i * 2] = tmp;
        swap(tmp.from, tmp.to);
        ++tmp.id;
        E[i * 2 + 1] = tmp;
    }

    int q;
    scanf("%d", &q);

    while (q--)
    {
        vector <vector <edge> > v(n);
        vector <bool> used(2 * m, false);
        for (int i = 0; i < 2 * m; i++)
            v[E[i].from].pb(E[i]);
        queue <int> edge_id;
        vector <int> dist(n, inf);
        int start, finish;
        cin >> start >> finish;
        --start, --finish;
        dist[start] = 0;
        for (int i = 0; i < sz(v[start]); i++)
        {
            edge_id.push(v[start][i].id);
            used[v[start][i].id] = true;
        }
        int t = 1;
        queue <int> edge_id_next;
        while (!edge_id.empty())
        {
            edge e = E[edge_id.front()];
            edge_id.pop();
            for (int i = 0; i < sz(v[e.to]); i++)
                if (v[e.to][i].t >= e.t - d && v[e.to][i].t <= e.t + d && !used[v[e.to][i].id])
            {
                edge e_next = E[v[e.to][i].id];
                dist[e_next.to] = min(dist[e_next.to], t + 1);
                edge_id_next.push(e_next.id);
                used[e_next.id] = true;
            }
            if (edge_id.empty())
            {
                ++t;
                edge_id = edge_id_next;
                while (!edge_id_next.empty())
                    edge_id_next.pop();
            }
        }
        cout << (dist[finish] == inf ? -1 : dist[finish]) << "\n";
    }

}

