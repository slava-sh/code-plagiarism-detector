#include <fstream>
#include <deque>
#include <vector>
#include <set>

#define ll long long

using namespace std;

ifstream fin("secure.in");
ofstream fout("secure.out");

const int MAXN = 1000;
const ll INF = 1000 * 1000 * 1000 * 100;

vector<vector<pair<ll, ll> > > neib;
vector<ll> color, c, mark, d;
ll w[MAXN][MAXN];
ll x = -1, y = -1;

ll col(ll pos) {
    if (color[pos] == 0)
        return pos;
    if (color[pos] == 1)
        return x;
    return y;
}

ll n, m;

int main() {
    fin >> n >> m;
    color.resize(n);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            w[i][j] = INF;
        }
    }
    for (ll i = 0; i < n; ++i) {
        fin >> color[i];
        if (x == -1 && color[i] == 1)
            x = i;
        if (y == -1 && color[i] == 2)
            y = i;
    }
    neib.resize(n);
    mark.resize(n);
    for (ll i = 0, u, v, d; i < m; ++i) {
        fin >> u >> v >> d;
        --u;
        --v;
        if (color[u] + color[v] > 0) {
            neib[u].push_back(make_pair(v, d));
            neib[v].push_back(make_pair(u, d));
        }
        u = col(u), v = col(v);
        if (u == v) {
            continue;
        }
        w[u][v] = min(d, w[u][v]);
        w[v][u] = min(d, w[v][u]);

    }

    vector<ll> d(n, INF);
    set<pair<ll, ll> > q;
    vector<ll> p(n, -1);
    d[x] = 0;
    q.insert(make_pair(d[x], x));
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(make_pair(d[v], v));
        if (d[v] == INF)
            break;
        for (ll i = 0; i < n; ++i) {
            if (w[v][i] != INF && v != i) {
                ll to = i, len = w[v][i];
                if (d[v] + len < d[to]) {
                    q.erase(make_pair(d[to], to));
                    d[to] = d[v] + len;
                    q.insert(make_pair(d[to], to));
                    p[to] = v;
                }
            }
        }
    }
    if (d[y] == INF) {
        fout << -1 << endl;
        return 0;
    }
    //*
    if (p[y] == x) {
        for (int i = 0; i < neib.size(); ++i)
            for (int j = 0; j < neib[i].size(); ++j)
                if (color[neib[i][j].first] + color[i])
                    if (neib[i][j].second == d[y]) {
                        fout << (color[i] == 1 ? i + 1 : neib[i][j].first + 1) << ' ';
                        fout << (color[i] == 2 ? i + 1 : neib[i][j].first + 1) << ' ';
                        fout << d[y];
                        return 0;
                    }
    }
    //*/
    ll cur;
    for (cur = y; p[cur] != x; cur = p[cur]) {
    }
    for (ll i = 0; i < neib[cur].size(); ++i) {
        if (neib[cur][i].second == w[cur][x] && color[neib[cur][i].first] == 1) {
            fout << neib[cur][i].first + 1 << ' ';
            break;
        }
    }
    cur = p[y];
    for (ll i = 0; i < neib[cur].size(); ++i) {
        if (neib[cur][i].second == w[cur][y] && color[neib[cur][i].first] == 2) {
            fout << neib[cur][i].first + 1 << ' ';
            break;
        }
    }

    fout << d[y] << endl;

    return 0;
}
