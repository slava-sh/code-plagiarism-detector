#include <iostream>
#include <set>
#include <fstream>
#include <vector>

#define mp make_pair
#define pii pair <int, int>
#define INF 2000000000 // 2 * 10**9

using namespace std;

int main()
{
    freopen("secure.in", "r", stdin);
    freopen("secure.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> d;
    d.resize(n);
    vector<int> parent;
    parent.resize(n);
    set<int> ss;
    set<pii > q;
    for(int i = 0; i < n; i++)
    {
        int cdc;
        cin >> cdc;
        if(cdc == 0)
        {
            d[i] = INF;
            parent[i] = -1;
        }
        if(cdc == 1)
        {
            d[i] = 0;
            parent[i] = i;
        }
        if(cdc == 2)
        {
            d[i] = INF;
            parent[i] = -1;
            ss.insert(i);
        }
        q.insert(mp(d[i], i));
    }
    vector<vector<pii > > g;
    g.resize(n);
    for(int i = 0; i < m; i++)
    {
        int s, t, c;
        cin >> s >> t >> c;
        s--;
        t--;
        g[s].push_back(mp(t, c));
        g[t].push_back(mp(s, c));
    }

    //cout << 1 << endl;
    for(int k = 0; k < n; ++k)
    {
        //cout << "s " << k << endl;
        pii mn = *(q.begin());
        q.erase(mn);
        int v = mn.second;
        //cout << v << endl;
        if(d[v] == INF)
        {
            cout << -1 << endl;
            return 0;
        }
        if(ss.find(v) != ss.end())
        {
            cout << parent[v] + 1 << " " << v + 1 << " " << d[v] << endl;
            return 0;
        }
        //cout << "m " << k << endl;
        for(int i = 0; i < int(g[v].size()); ++i)
        {
            int to = g[v][i].first;
            int w = g[v][i].second;
            if(d[to] > d[v] + w)
            {
                q.erase(mp(d[to], to));
                d[to] = d[v] + w;
                parent[to] = parent[v];
                q.insert(mp(d[to], to));
            }
        }
        //cout << "e " << k << endl;
    }

    cout << -1 << endl;

    return 0;
}
