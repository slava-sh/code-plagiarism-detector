#include <bits/stdc++.h>
//#include <unordered_set>
#define ff first
#define ss second
#define szof(_x) (int) (_x).size()
#define bend(_x) (_x).begin(), (_x).end()
#define mapa make_pair
#define puba push_back

using namespace std;
typedef pair <int, int> pii;
typedef long long LL;
const int MAXN = 1e5 + 5;

LL a, b;
int n;
vector <pair <LL, pii > > scanline;
vector <pair <LL, LL> > inp[MAXN];
int wherenow[MAXN];
int lr[2][MAXN];
//bool toc[2][MAXN];

//unordered_set <LL> have;
int wheret[MAXN];

vector <int> graph[MAXN];

bool checkup(pair <LL, LL> p, pair <LL, LL> s, pair <LL, LL> e) {
    //double tmp = (e.ss - s.ss) / (double) (e.ff - s.ff) * (p.ff - s.ff) + s.ss;
    assert(p.ff >= s.ff && e.ff >= p.ff);
    return (e.ss - s.ss) * (p.ff - s.ff) + s.ss * (e.ff - s.ff) < p.ss * (e.ff - s.ff);
}   

bool checkdown(pair <LL, LL> p, pair <LL, LL> s, pair <LL, LL> e) {
    assert(p.ff >= s.ff && e.ff >= p.ff);
    //double tmp = (e.ss - s.ss) / (double) (e.ff - s.ff) * (p.ff - s.ff) + s.ss;
    return (e.ss - s.ss) * (p.ff - s.ff) + s.ss * (e.ff - s.ff) > p.ss * (e.ff - s.ff);
}

vector <int> topsort;

bool used[MAXN];


int dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < szof(graph[v]); ++i) {        
        if (!used[graph[v][i]]) {
            dfs(graph[v][i]);
        }
    }
    topsort.puba(v);
    return 0;
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%lld%lld", &a, &b);
    scanf("%d", &n);
    vector <pair <LL, int> > v, v2;

    for (int i = 0; i < n; ++i) {
        topsort.puba(i);
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m + 1; ++j) {
            LL x, y;
            scanf("%lld%lld", &x, &y);
            if (j == 0) {
                v.puba(mapa(y, i));
            }
            
            
            if (j == m) {
                v2.puba(mapa(y, i));
                //cout << i << " " << y << endl;
            }
            scanline.puba(mapa(x, mapa(i, j)));
            inp[i].puba(mapa(x, y));
        }
    }

    /*
    sort(bend(v));
    //sort(bend(v));
    memset(lr, -1, sizeof lr);
    for (int i = 0; i < n; ++i) {        
        if (i < n - 1) {            
            lr[1][v[i].ss] = v[i + 1].ss;            
            if (v[i].ff != v[i + 1].ff) {
                graph[v[i].ss].puba(v[i + 1].ss);
            }
        }
        if (i > 0) {
            lr[0][v[i].ss] = v[i - 1].ss;            
            if (v[i].ff != v[i - 1].ff) {
                graph[v[i - 1].ss].puba(v[i].ss);
            }
        }
    }

    
    sort(bend(v2));
    //sort(bend(v));
    //memset(lr, -1, sizeof lr);
    for (int i = 0; i < n; ++i) {        
        if (i < n - 1) {            
            //lr[1][v2[i].ss] = v2[i + 1].ss;            
            if (v2[i].ff != v2[i + 1].ff) {
                graph[v2[i].ss].puba(v2[i + 1].ss);
            }
        }
        if (i > 0) {
            //lr[0][v2[i].ss] = v2[i - 1].ss;            
            if (v2[i].ff != v2[i - 1].ff) {
                graph[v2[i - 1].ss].puba(v2[i].ss);
            }
        }
    }

    sort(bend(scanline));

    //bool flag = true;

    for (int i = 0; i < szof(scanline); ++i) {
        if (scanline[i].ff == a) {
            wherenow[scanline[i].ss.ff] = 0;
            continue;
        }           
        int numl = scanline[i].ss.ff;
        int numc = scanline[i].ss.ss;
        if (lr[0][numl] != -1) {
            if (checkup(inp[numl][numc], inp[lr[0][numl]][wherenow[lr[0][numl]]], inp[lr[0][numl]][wherenow[lr[0][numl]] + 1])) {
                graph[lr[0][numl]].puba(numl);
            }
            if (checkdown(inp[numl][numc], inp[lr[0][numl]][wherenow[lr[0][numl]]], inp[lr[0][numl]][wherenow[lr[0][numl]] + 1])) {
                graph[numl].puba(lr[0][numl]);
            }
        }

        if (lr[1][numl] != -1) {
            if (checkdown(inp[numl][numc], inp[lr[1][numl]][wherenow[lr[1][numl]]], inp[lr[1][numl]][wherenow[lr[1][numl]] + 1])) {
                graph[numl].puba(lr[1][numl]);
            }
            if (checkup(inp[numl][numc], inp[lr[1][numl]][wherenow[lr[1][numl]]], inp[lr[1][numl]][wherenow[lr[1][numl]] + 1])) {
                graph[lr[1][numl]].puba(numl);
            }
        }
        if (numc != szof(inp[numl]) - 1) {
            wherenow[numl] = numc;
        }
    }

    
    
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(bend(topsort));


    for (int i = 0; i < n; ++i) {
        wheret[topsort[i]] = i;
    }   
    */
    for (int kl = 0; kl < 10; ++kl) {
    //v.clear();
    random_shuffle(bend(topsort));
    vector <pair <int, pii > > v3;
    for (int i2 = 0; i2 < n; ++i2) {
        int i = topsort[i2];
        for (int j = 0; j < szof(inp[i]); ++j) {
            LL y = inp[i][j].ss;
            
            if (j == 0) {
                v3.puba(mapa(y, mapa(i2, i)));
            }                                               
        }
    }

    
    sort(bend(v3));
    //sort(bend(v));
    memset(lr, -1, sizeof lr);
    for (int i = 0; i < n; ++i) {        
        if (i < n - 1) {            
            lr[1][v3[i].ss.ss] = v3[i + 1].ss.ss;                        
        }
        if (i > 0) {
            lr[0][v3[i].ss.ss] = v3[i - 1].ss.ss;                        
        }
    }
    

    //sort(bend(scanline));

    //bool flag = true;

    for (int i = 0; i < szof(scanline); ++i) {
        if (scanline[i].ff == a) {
            wherenow[scanline[i].ss.ff] = 0;
            continue;
        }           
        int numl = scanline[i].ss.ff;
        int numc = scanline[i].ss.ss;
        if (lr[0][numl] != -1) {
            if (!checkup(inp[numl][numc], inp[lr[0][numl]][wherenow[lr[0][numl]]], inp[lr[0][numl]][wherenow[lr[0][numl]] + 1])) {
                printf("No\n%d %d\n", numl + 1, lr[0][numl] + 1);
                return 0;
            }            
        }

        if (lr[1][numl] != -1) {
            if (!checkdown(inp[numl][numc], inp[lr[1][numl]][wherenow[lr[1][numl]]], inp[lr[1][numl]][wherenow[lr[1][numl]] + 1])) {
                printf("No\n%d %d\n", numl + 1, lr[1][numl] + 1);
                return 0;
            }
        }
        if (numc != szof(inp[numl]) - 1) {
            wherenow[numl] = numc;
        }
    }

    }

    printf("Yes\n");

    return 0;
}