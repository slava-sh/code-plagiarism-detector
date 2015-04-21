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
const int MAXN = 1e5 + 5;

LL a, b;
int n;
vector <pair <LL, pii > > scanline;
vector <pair <LL, LL> > inp[MAXN];
int wherenow[MAXN];
int lr[2][MAXN];

bool checkup(pair <LL, LL> p, pair <LL, LL> s, pair <LL, LL> e) {
    //double tmp = (e.ss - s.ss) / (double) (e.ff - s.ff) * (p.ff - s.ff) + s.ss;
    assert(p.ff >= s.ff && e.ff >= p.ff);
    return (e.ss - s.ss) * (p.ff - s.ff) + s.ss * (e.ff - s.ff) <= p.ss * (e.ff - s.ff);
}   

bool checkdown(pair <LL, LL> p, pair <LL, LL> s, pair <LL, LL> e) {
    assert(p.ff >= s.ff && e.ff >= p.ff);
    //double tmp = (e.ss - s.ss) / (double) (e.ff - s.ff) * (p.ff - s.ff) + s.ss;
    return (e.ss - s.ss) * (p.ff - s.ff) + s.ss * (e.ff - s.ff) >= p.ss * (e.ff - s.ff);
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%lld%lld", &a, &b);
    scanf("%d", &n);
    vector <pair <LL, int> > v;

    for (int i = 0; i < n; ++i) {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m + 1; ++j) {
            LL x, y;
            scanf("%lld%lld", &x, &y);
            if (j == 0) {
                v.puba(mapa(y, i));
            }
            scanline.puba(mapa(x, mapa(i, j)));
            inp[i].puba(mapa(x, y));
        }
    }

    sort(bend(v));
    memset(lr, -1, sizeof lr);
    for (int i = 0; i < n; ++i) {
        if (i < n - 1) {            
            lr[1][v[i].ss] = v[i + 1].ss;
        }
        if (i > 0) {
            lr[0][v[i].ss] = v[i - 1].ss;
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
        if (lr[0][numl] != -1 && wherenow[lr[0][numl]] < szof(inp[lr[0][numl]]) - 1) {
            if (!checkup(inp[numl][numc], inp[lr[0][numl]][wherenow[lr[0][numl]]], inp[lr[0][numl]][wherenow[lr[0][numl]] + 1])) {
                printf("No\n%d %d\n", lr[0][numl] + 1, numl + 1);
                return 0;
            }
        }

        if (lr[1][numl] != -1 && wherenow[lr[1][numl]] < szof(inp[lr[1][numl]]) - 1) {
            if (!checkdown(inp[numl][numc], inp[lr[1][numl]][wherenow[lr[1][numl]]], inp[lr[1][numl]][wherenow[lr[1][numl]] + 1])) {
                printf("No\n%d %d\n", lr[1][numl] + 1, numl + 1);
                return 0;
            }
        }
        if (numc != szof(inp[numl]) - 1) {
            wherenow[numl] = numc;
        }
    }

    printf("Yes\n");

    return 0;
}