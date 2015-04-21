#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define foreach(i, q) for (typeof(q.begin()) i = q.begin(); i != q.end(); ++i)

#ifdef LOCAL
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif // LOCAL

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const int INF = int(1e9) * 2 + 5;
const int MOD = INF + 7;

vector<vi> g;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    int n, m, D;
    scanf("%d %d %d", &n, &m, &D);
    g.resize(n);
    vi x(m), y(m), t(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &x[i], &y[i], &t[i]);
        x[i]--, y[i]--;
        g[x[i]].pb(i);
        g[y[i]].pb(i);
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        vector<vi> d(2, vi(m, INF));
        queue<pii> q;
        for (int i = 0; i < g[a].size(); ++i)
            if (x[g[a][i]] == a)
                d[1][g[a][i]] = 1, q.push(mp(g[a][i], 1));
            else
                d[0][g[a][i]] = 1, q.push(mp(g[a][i], 0));
        int res = INF;
        while (!q.empty()) {
            int num = q.front().F, dir = q.front().S;
            q.pop();
            int a;
            if (dir == 1)
                a = y[num];
            else
                a = x[num];
            for (int i = 0; i < g[a].size(); ++i)
                if (abs(1ll * t[num] - t[g[a][i]]) <= D) {
                    int ndir;
                    if (x[g[a][i]] == a)
                        ndir = 1;
                    else
                        ndir = 0;
                    if (d[ndir][g[a][i]] > d[dir][num] + 1) {
                        d[ndir][g[a][i]] = d[dir][num] + 1;
                        q.push(mp(g[a][i], ndir));
                    }
                }
        }
        for (int i = 0; i < g[b].size(); ++i)
            if (y[g[b][i]] == b)
                res = min(res, d[1][g[b][i]]);
            else
                res = min(res, d[0][g[b][i]]);
        if (res == INF)
            printf("-1\n");
        else
            printf("%d\n", res);
    }
    return 0;
}
