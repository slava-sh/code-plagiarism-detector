#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int oo = 2e9;
const int nmax = 1100;

vector<pair<int, int> > gr[nmax];
map<int, int> d[nmax];
int a[nmax], b[nmax];
queue<pair<int, int> > qq;
int n, m, q, dd;


void read()
{
    fin >> n >> m >> dd;
    for (int i = 0; i < m; i++)
    {
        int u, v, t;
        fin >> u >> v >> t;
        u--;
        v--;
        gr[u].push_back(make_pair(v, t));
        gr[v].push_back(make_pair(u, t));
    }
    fin >> q;
    for (int i = 0; i < q; i++)
    {
        fin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
}


void bfs(int s, int f)
{
    qq.push(make_pair(s, oo));
    d[s][oo] = 0;
    while (!qq.empty())
    {
        pair<int, int> p = qq.front();
        qq.pop();
        int v = p.first;
        int tfrom = p.second;
        //fout << v << ' ' << tfrom << ' ' << d[v][tfrom] << endl;
        for (int i = 0; i < gr[v].size(); i++)
        {
            int to = gr[v][i].first;
            int t = gr[v][i].second;
            if (((d[to].find(t) == d[to].end()) || (d[to][t] > d[v][tfrom] + 1)) && ((tfrom == oo) || (abs(tfrom - t) <= dd)))
            {
                d[to][t] = d[v][tfrom] + 1;
                qq.push(make_pair(to, t));
            }
        }
    }
    int mind = oo;
    for (map<int, int>::iterator it = d[f].begin(); it != d[f].end(); it++)
    {
        int curd = (*it).second;
        mind = min(mind, curd);
    }
    if (mind == oo)
        fout << -1 << endl;
    else
        fout << mind << endl;
}


void solve()
{
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < n; j++)
            d[j].clear();
        bfs(a[i], b[i]);
    }
}


int main()
{
    read();
    solve();
    return 0;
}
