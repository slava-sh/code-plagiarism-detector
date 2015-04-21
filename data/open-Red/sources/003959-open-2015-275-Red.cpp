#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define forn(i,a,b) for(int i = a; i < (int)b; i++)
#define srep(i, a) for(__typeof(a.begin()) i = a.begin(); i != a.end(); i++)

typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int maxn = 1e5;
const int INF = 1e9;

vector<pii> g[maxn];
map<pii, int> d;
int qs = 0;
int ta[maxn];

int N, M, D;

inline int getd(pii a)
{
    if (d.find(a) == d.end()) return INF;
    return d[a];
}

int bfs(int s, int f)
{
    queue<pii> q;
    rep(i, g[s].size())
    {
        int v = g[s][i].fi;
        int t = g[s][i].se;
        d[mp(v, t)] = 1;
        q.push(mp(v, t));
        if (f == v) return 1;
    }
    while(!q.empty())
    {
        int v = q.front().fi;
        int t = q.front().se;
        int td = getd(mp(v, t));
        q.pop();
        rep(i, g[v].size())
        {
            int u = g[v][i].fi;
            int nt = g[v][i].se;
            if (abs(ta[t]-ta[nt]) <= D && getd(mp(u, nt)) == INF)
            {
                d[mp(u, nt)] = td+1;
                q.push(mp(u, nt));
                if (u == f)
                {
                    return td+1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M >> D;
    int pt = -INF;
    rep(i, M)
    {
        int v, u, t;
        cin >> v >> u >> t;
        if (pt != t)
        {
            ta[qs] = t;
            qs++;
        }
        pt = t;
        g[v-1].push_back(mp(u-1, qs-1));
        g[u-1].push_back(mp(v-1, qs-1));
    }
    int Q;
    cin >> Q;
    rep(i, Q)
    {
        d.clear();
        int s, f;
        cin >> s >> f;
        cout << bfs(s-1, f-1) << endl;
    }
    return 0;
}
