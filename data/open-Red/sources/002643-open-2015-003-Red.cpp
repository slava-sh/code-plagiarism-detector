#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 100010;
const int INF = 1e9;

struct graph {
    int x, c, n;
    graph() {}
    graph(int x, int c, int n): x(x), c(c), n(n) {}
};

vector<graph> g[maxn];
vector<bool> u[maxn];
vector<int> ans[maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    srand(213);

    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        x--, y--;
        g[x].push_back(graph(y, z, g[y].size()));
        g[y].push_back(graph(x, z, g[x].size() - 1));
        u[x].push_back(false);
        u[y].push_back(false);
        ans[x].push_back(0);
        ans[y].push_back(0);
    }
    int r;
    scanf("%d", &r);
    for (int z = 0; z < r; ++z) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (int)u[i].size(); ++j) {
                u[i][j] = false;
                ans[i][j] = INF;
            }
        }
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (rand() % 2) swap(a, b);
        queue<pair<int, int> > q;
        for (int i = 0; i < (int)g[a].size(); ++i) {
            int to = g[a][i].x, num = g[a][i].n;
            ans[to][num] = 1;
            u[to][num] = true;
            q.push(make_pair(to, num));
        }
        bool fl = false;
        while (!q.empty()) {
            int v = q.front().first;
            int x = q.front().second;
            q.pop();
            if (v == b) {
                printf("%d\n", ans[v][x]);
                fl = true;
                break;
            }
            for (int i = 0; i < (int)g[v].size(); ++i) {
                int to = g[v][i].x;
                int c = g[v][i].c;
                int num = g[v][i].n;
                if (!u[to][num] && c <= g[v][x].c + d && c >= g[v][x].c - d) {
                    u[to][num] = true;
                    ans[to][num] = ans[v][x] + 1;
                    q.push(make_pair(to, num));
                }
            }
        }
        if (!fl) printf("-1\n");
        /*int s = INF;
        for (int i = 0; i < (int)g[b].size(); ++i) {
            s = min(s, ans[b][i]);
        }
        if (s == INF) printf("-1\n");
        else printf("%d\n", s);*/
    }

    return 0;
}

