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

const size_t MAXMEM = 500 * 1024 * 1024;
char MEM[MAXMEM];
size_t NOWMEM = 0;

inline void* operator new(size_t l) {
    assert(NOWMEM + l < MAXMEM);
    NOWMEM += l;
    return MEM + NOWMEM - l;
}   

inline void operator delete(void *) {}


int n, m;
LL d;
vector <pii > graph[MAXN + MAXM + MAXM * 3];

vector <pair <LL, pair <int, pii > > > preg[MAXN];
bool used[MAXN + MAXM + MAXM * 3];
int rsq[MAXM];


int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    //cin >> n >> m >> d;
    scanf("%d%d%lld", &n, &m, &d);

    for (int i = 0; i < m; ++i) {
        int a, b;
        LL t;
        //cin >> a >> b >> t;
        scanf("%d%d%lld", &a, &b, &t);
        --a;--b;
        graph[2 * i + 1 + n].puba(mapa(a, 1));
        graph[2 * i + n].puba(mapa(b, 1));
        //cout << "add edge " << 2 * i + 1 + n << " -> " << a << endl;
        //cout << "add edge " << 2 * i + n << " -> " << b << endl;
        preg[a].puba(mapa(t, mapa(i, mapa(a, b))));
        preg[b].puba(mapa(t, mapa(i, mapa(a, b))));
    }

    int lc = n + m * 2;
    for (int i = 0; i < n; ++i) {
        sort(bend(preg[i]));
        int bdv = 1;
        while (bdv < szof(preg[i])) {
            bdv <<= 1;
        }
        for (int j = 0; j < szof(preg[i]); ++j) {
            int pl2 = 0;
            if (i == preg[i][j].ss.ss.ss) {
                pl2 = 1;
            }
            rsq[j + bdv] = 2 * preg[i][j].ss.ff + pl2 + n;
            //cout << j + bdv << " " << 2 * preg[i][j].ss.ff + pl2 + n << endl;
        }
        for (int j = bdv - 1; j > 0; --j) {
            rsq[j] = lc++;
            graph[rsq[j]].puba(mapa(rsq[j * 2], 0));
            graph[rsq[j]].puba(mapa(rsq[j * 2 + 1], 0));
        }
        int lg = 0, rg = 0;
        for (int j = 0; j < szof(preg[i]); ++j) {
            while (rg + 1 < szof(preg[i]) && preg[i][rg + 1].ff - preg[i][j].ff <= d) {
                ++rg;
            }
            while (preg[i][j].ff - preg[i][lg].ff > d) {
                ++lg;
            }
            int tmpl = lg + bdv;
            int tmpr = rg + bdv;
            int pl1 = 0;
            if (preg[i][j].ss.ss.ff != i) {
                pl1 = 1;
            }
            //cout << bdv << endl;
            int therev = 2 * preg[i][j].ss.ff + 1 - pl1 + n;
            while (tmpl < tmpr) {
                //cout << tmpl << " " << tmpr << endl;
                if (tmpl % 2 == 1) {
                    graph[therev].puba(mapa(rsq[tmpl], 1));
                    //cout << therev << " -> " << rsq[tmpl] << " " << tmpl << endl;
                    ++tmpl;
                }
                if (tmpr % 2 == 0) {
                    graph[therev].puba(mapa(rsq[tmpr], 1));
                    //cout << therev << " -> " << rsq[tmpr] << " " << tmpr << endl;
                    --tmpr;
                }
                if (tmpl > tmpr) {
                    break;
                }
                tmpl /= 2;
                tmpr /= 2;
            }
            if (tmpl == tmpr) {
                //cout << therev << " -> " << rsq[tmpl] << endl;
                graph[therev].puba(mapa(rsq[tmpl], 1));
            }
        }
        /*
        for (int j = 0; j < szof(preg[i]); ++j) {
            int pl1 = 0;
            if (preg[i][j].ss.ss.ff != i) {
                pl1 = 1;
            }
            for (int k = j; k < szof(preg[i]) && preg[i][k].ff - preg[i][j].ff <= d; ++k) {
                int pl2 = 0;
                if (i == preg[i][k].ss.ss.ss) {
                    pl2 = 1;
                }   
                graph[2 * preg[i][j].ss.ff + 1 - pl1 + n].puba(2 * preg[i][k].ss.ff + pl2 + n);
                graph[2 * preg[i][k].ss.ff + 1 - pl2 + n].puba(2 * preg[i][j].ss.ff + pl1 + n);
                //cout << "add edge " << 2 * preg[i][j].ss.ff + 1 - pl1 + n << " -> " << 2 * preg[i][k].ss.ff + pl2 + n << endl;
                //cout << "add edge " << 2 * preg[i][k].ss.ff + 1 - pl2 + n << " -> " << 2 * preg[i][j].ss.ff + pl1 + n << endl;
            } 
        }*/
    }
    
    for (int i = 0; i < lc; ++i) {
        for (int j = 0; j < szof(graph[i]); ++j) {
            //cout << i << " -> " << graph[i][j].ff << endl;
        }
    }

    int q;
    //cin >> q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int a, b;
        //cin >> a >> b;
        scanf("%d%d", &a, &b);
        --a;--b;
        memset(used, 0, sizeof used);
        priority_queue <pii > qu;
        for (int j = 0; j < szof(preg[a]); ++j) {
            int pl = 0;
            if (preg[a][j].ss.ss.ff != a) {
                pl = 1;
            }
            //used[preg[a][j].ss.ff * 2 + pl + n] = true;
            qu.push(mapa(0, preg[a][j].ss.ff * 2 + pl + n));
            //cout << preg[a][j].ss.ff * 2 + pl + n << endl;
        }
        bool flag = false;
        //cout << "i: " << i << endl;
        while (szof(qu)) {
            pii p = qu.top();
            qu.pop();
            while (szof(qu) && used[p.ss]) {
                p = qu.top();
                qu.pop();
            }
            if (used[p.ss]) {
                break;
            }
            
            p.ff *= -1;
            
            //cout << p.ss << " " << p.ff << endl;
            //cout << p.ss << " " << p.ff << endl;
            if (p.ss == b) {
                //cout << p.ff << endl;
                printf("%d\n", p.ff);
                flag = true;
                break;
            }
            used[p.ss] = true;
            for (int j = 0; j < szof(graph[p.ss]); ++j) {
                if (!used[graph[p.ss][j].ff]) {
                    //used[graph[p.ff][j]] = true;
                    //cout << graph[p.ss][j].ff << " " << -p.ff - graph[p.ss][j].ss << " " << p.ss << endl;
                    qu.push(mapa(-p.ff - graph[p.ss][j].ss, graph[p.ss][j].ff));
                }
            }   
        }
        if (!flag) {
            //cout << -1 << endl;
            printf("-1\n");
        }
    }

    return 0;
}

