#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

struct UF {
    vector<int> par;
    void init(int n) { par.assign(n, ~0); }
    int root(int x) { return par[x] < 0 ? x : par[x] = root(par[x]); }
    bool connect(int x, int y) {
        if ((x = root(x)) == (y = root(y))) return 0;
        if (par[y] < par[x]) swap(x, y);
        par[x] += par[y], par[y] = x;
        return 1;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -par[root(x)]; }
};

template<class S, class T, class U> struct Tuple {
    S s; T t; U u;
    Tuple() {} Tuple(S s, T t, U u) : s(s), t(t), u(u) {}
    bool operator==(const Tuple<S, T, U>& a) const { return (s == a.s and t == a.t and u == a.u) ? 1 : 0; }
    bool operator!=(const Tuple<S, T, U>& a) const { return !this->operator==(a); }
};

template<class S> struct Compare {
    bool operator() (const S& a, const S& b) const {
        if (a.s != b.s) return a.s > b.s;
        if (a.t != b.t) return a.t < b.t;
        if (a.u != b.u) return a.u < b.u;
        return 0;
    }
};

template<class S, class T, class U> ostream& operator<<(ostream& os, const Tuple<S, T, U>& a) {
    os << '(' << a.s << ' ' << a.t << ' ' << a.u << ')';
    return os;
}

typedef Tuple<int, int, int> P;

int n, m, k, w;
char in[1001][11][11];

UF uf;
int vis[1001];

vector<int> graph[1001];

void dfs(int u, int par) {
    // cout << u << ' ' << par << endl;
    if (~par) {
        printf("%d %d\n", u + 1, par + 1);
    }
    vis[u] = 1;
    int i;
    for (i = 0; i < graph[u].size(); i++) {
        int to = graph[u][i];
        if (vis[to] == 0) {
            dfs(to, u);
        }
    }
}

int main () {
    int i, j, tcc, tc = 1 << 28;
    for (tcc = 0; tcc < tc; tcc++) {
        n = getint(), m = getint(), k = getint(), w = getint();
        int icost = n * m;
        for (int ii = 0; ii < k; ii++) {
            for (i = 0; i < n; i++) getstr(in[ii][i]);
        }
        uf.init(k);
        priority_queue<P, vector<P>, Compare<P> > pque;
        for (i = 0; i < k; i++) for (j = i + 1; j < k; j++) {
            int ii, jj, cnt = 0;
            for (ii = 0; ii < n; ii++) for (jj = 0; jj < m; jj++) {
                if (in[i][ii][jj] != in[j][ii][jj]) cnt++;
            }
            pque.push(P(cnt * w, i, j));
        }
        int rescost = 0;
        while (pque.empty() == 0) {
            int cost = pque.top().s;
            int u = pque.top().t;
            int v = pque.top().u;
            pque.pop();
            if (cost >= icost) break;
            if (uf.same(u, v)) continue;
            rescost += cost;
            uf.connect(u, v);
            // cout << u << ' ' << v << endl;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (i = 0; i < k; i++) if (uf.root(i) == i) rescost += icost;

        printf("%d\n", rescost);
        for (i = 0; i < k; i++) if (vis[i] == 0) {
            printf("%d %d\n", i + 1, 0);
            dfs(i, ~0);
        }

    }
    return 0;
}
