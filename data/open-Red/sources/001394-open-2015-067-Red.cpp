#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(_x) (int) (_x).size()
#define bend(_x) (_x).begin(), (_x).end()
#define mapa make_pair
#define puba push_back

using namespace std;
typedef pair <int, int> pii;
typedef long long LL;
const int MAXN = 1e5 + 5, MAXM = 4e5 + 5;


int n, m;
LL d;
vector <int> graph[MAXN + MAXM];

vector <pair <LL, pii > > preg[MAXN];
bool used[MAXN + MAXM];


int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m >> d;

    for (int i = 0; i < m; ++i) {
        int a, b;
        LL t;
        cin >> a >> b >> t;
        --a;--b;
        graph[2 * i + 1 + n].puba(a);
        graph[2 * i + n].puba(b);
        //cout << "add edge " << 2 * i + 1 + n << " -> " << a << endl;
        //cout << "add edge " << 2 * i + n << " -> " << b << endl;
        preg[a].puba(mapa(t, mapa(i, a)));
        preg[b].puba(mapa(t, mapa(i, a)));
    }

    for (int i = 0; i < n; ++i) {
        sort(bend(preg[i]));
        for (int j = 0; j < szof(preg[i]); ++j) {
            int pl1 = 0;
            if (preg[i][j].ss.ss != i) {
                pl1 = 1;
            }
            for (int k = j; k < szof(preg[i]) && preg[i][k].ff - preg[i][j].ff <= d; ++k) {
                int pl2 = 0;
                if (i != preg[i][k].ss.ss) {
                    pl2 = 1;
                }   
                graph[2 * preg[i][j].ss.ff + 1 - pl1 + n].puba(2 * preg[i][k].ss.ff + pl2 + n);
                graph[2 * preg[i][k].ss.ff + 1 - pl2 + n].puba(2 * preg[i][j].ss.ff + pl1 + n);
                //cout << "add edge " << 2 * preg[i][j].ss.ff + pl1 + n << " -> " << 2 * preg[i][k].ss.ff + 1 - pl2 + n << endl;
                //cout << "add edge " << 2 * preg[i][k].ss.ff + pl2 + n << " -> " << 2 * preg[i][j].ss.ff + 1 - pl2 + n << endl;
            } 
        }
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        --a;--b;
        memset(used, 0, sizeof used);
        queue <pii > qu;
        for (int j = 0; j < szof(preg[a]); ++j) {
            int pl = 0;
            if (preg[a][j].ss.ss != a) {
                pl = 1;
            }
            used[preg[a][j].ss.ff * 2 + pl + n] = true;
            qu.push(mapa(preg[a][j].ss.ff * 2 + pl + n, 0));
        }
        bool flag = false;
        //cout << "i: " << i << endl;
        while (szof(qu)) {
            pii p = qu.front();
            qu.pop();
            //cout << p.ss << " " << p.ff << endl;
            if (p.ff == b) {
                cout << p.ss << endl;
                flag = true;
                break;
            }
            for (int j = 0; j < szof(graph[p.ff]); ++j) {
                if (!used[graph[p.ff][j]]) {
                    used[graph[p.ff][j]] = true;
                    qu.push(mapa(graph[p.ff][j], p.ss + 1));
                }
            }   
        }
        if (!flag) {
            cout << -1 << endl;
        }
    }

    return 0;
}

