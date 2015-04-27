#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 100010;
struct node {
    int t, v;
} p[N];

int cc;
int a[N];
bool ok[N];
int ans[N];
bool vis[N];

int main() {
    char op[5];
    int n, m; scanf("%d%d", &n, &m);
    rep(i, m) {
        scanf(" %s%d", op, &p[i].v);
        p[i].t = (op[0] == '+') ? 1 : -1;
    }
    Rep(i, n) ok[i] = 1;


    cc = 0;
    rep(i, m) {
        if (!vis[p[i].v]) {
            vis[p[i].v] = 1;
            if (p[i].t == -1) {
                ++a[p[i].v];
                ++cc;
            }
        }
    }

    rep(i, m) {
        if (p[i].t == 1) {
            if (cc != 0 || (i != 0 && !(p[i - 1].v == p[i].v && p[i - 1].t == -1))) {
                ok[p[i].v] = 0;
            }
        } else {
            if (!((cc == 1 && a[p[i].v] == 1) || cc == 0)) {
                ok[p[i].v] = 0;
            }
        }
        a[p[i].v] += p[i].t;
        cc += p[i].t;
    }
    
    cc = 0; clr(a, 0); clr(vis, 0);
    reverse(p, p + m);
    rep(i, m) p[i].t = -p[i].t;
    rep(i, m) {
        if (!vis[p[i].v]) {
            vis[p[i].v] = 1;
            if (p[i].t == -1) {
                ++a[p[i].v];
                ++cc;
            }
        }
    }
    rep(i, m) {
        if (p[i].t == 1) {
            if (cc != 0 || (i != 0 && !(p[i - 1].v == p[i].v && p[i - 1].t == -1))) {
                ok[p[i].v] = 0;
            }
        } else {
            if (!((cc == 1 && a[p[i].v] == 1) || cc == 0)) {
                ok[p[i].v] = 0;
            }
        }
        a[p[i].v] += p[i].t;
        cc += p[i].t;
    }


    int cnt = 0;
    Rep(i, n) if (ok[i]) ans[cnt++] = i;
    printf("%d\n", cnt);
    rep(i, cnt) {
        if (i == cnt - 1) printf("%d\n", ans[i]);
        else printf("%d ", ans[i]);
    }
    return 0;
}
