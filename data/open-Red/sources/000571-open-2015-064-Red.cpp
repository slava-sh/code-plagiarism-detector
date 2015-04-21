#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

template<class T> T nextInt() {
    T x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = (int)1e9 + 5;

const int maxn = 100500;

struct state {
    int to, c;
    state() {}
    state(int to, int c) : to(to), c(c) {}
    bool operator <(const state & B) const {
        return c < B.c || (c == B.c && to < B.to);
    }
};

int N, M, D;
int x[maxn * 2], y[maxn * 2], c[maxn * 2];
set<state> s[maxn];

void addEdge(int x, int y, int c) {
    s[x].insert(state(y, c));
    s[y].insert(state(x, c));
}

map<state, int> d;

state q[maxn * 4];
int qs, qe;

int solve(int A, int B) {
    d.clear();
    for (int i = 1; i <= N; i++)
        s[i].clear();
    for (int i = 1; i <= M; i++)
        addEdge(x[i], y[i], c[i]);
    q[qe++] = state(A, INF);
    d[state(A, INF)] = 0;
    while (qs < qe) {
        state t = q[qs++];
        int cur = d[t];
        int L = t.c - D, R = t.c + D;
        if (t.c == INF) {
            L = -INF, R = INF;
        }
        set<state>::iterator it = s[t.to].lower_bound(state(0, L));
        set<state>::iterator iit = it;
        while (it != s[t.to].end() && it->c <= R) {
            state to = *it;
            if (d.find(to) == d.end()) {
                d[to] = cur + 1;
                q[qe++] = to;
            }
            it++;
        }
        s[t.to].erase(iit, it);
    }
    int res = INF;
    for (map<state, int>::iterator it = d.begin(); it != d.end(); it++)
        if (it->first.to == B) res = min(res, it->second);
    if (res == INF) res = -1;
    return res;
}

int main()
{
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    N = nextInt<int>();
    M = nextInt<int>();
    D = nextInt<int>();

    for (int i = 1; i <= M; i++) {
        x[i] = nextInt<int>();
        y[i] = nextInt<int>();
        c[i] = nextInt<int>();
    }

    int Q = nextInt<int>();

    while (Q--) {
        int A, B;
        A = nextInt<int>();
        B = nextInt<int>();
        printf("%d\n", solve(A, B));
    }

    return 0;
}
