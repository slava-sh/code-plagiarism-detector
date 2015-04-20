#define _USE_MATH_DEFINES

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>

#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>

using namespace std;

#define INF INT_MAX
#define LINF LLONG_MAX
#define EPS 1e-9
#define MAXN 5002
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front

typedef long long int64;
typedef long double real;
typedef pair<int, int> pii;

#define TASK "secure"

struct edge {
    int to, c;

    edge()
    : to(0), c(0) {
    }

    edge(int to, int c)
    : to(to), c(c) {
    }
};

int n, m;
vector<edge> G[MAXN];
vector<int> type;

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#else
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif
    
    scanf("%d %d", &n, &m);
    type.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &type[i]);
    }

    for (int i = 0; i < m; ++i) {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        --s; --t;
        G[s].pub(edge(t, c));
        G[t].pub(edge(s, c));
    }

    // n -- 1, n + 1 -- 2
    for (int i = 0; i < n; ++i) {
        if (type[i] == 1) {
            G[n].pub(edge(i, 0));
        }

        if (type[i] == 2) {
            G[i].pub(edge(n + 1, 0));
        }
    }

    vector<int64> dist(n + 2, LINF);
    vector<bool> used(n + 2, false);
    vector<int> p(n + 2, -1);
    dist[n] = 0;

    for (int i = 0; i < n + 2; ++i) {
        int v = -1;
        int64 mind = LINF;

        for (int j = 0; j < n + 2; ++j) {
            if (dist[j] < mind && !used[j]) {
                mind = dist[j];
                v = j;
            }
        }

        if (v == -1) {
            break;
        }

        used[v] = true;
        for (int j = 0; j < G[v].size(); ++j) {
            int to = G[v][j].to;
            if (dist[to] > dist[v] + G[v][j].c) {
                dist[to] = dist[v] + G[v][j].c;
                p[to] = v;
            }
        }
    }

    if (dist[n + 1] == INF) {
        printf("-1\n");
        return 0;
    }

    int v = n + 1;
    vector<int> path;
    while (v != -1) {
        path.pub(v);
        v = p[v];
    }

    int x = path[path.size() - 2];
    int y = path[1];
    int64 d = dist[n + 1];
    printf("%d %d %I64d\n", x + 1, y + 1, d);

}