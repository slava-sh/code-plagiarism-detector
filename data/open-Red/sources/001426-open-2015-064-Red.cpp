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
/*
const int MAX_MEM = (int)4e8;

char mem[MAX_MEM];
size_t usedMem;

void * operator new(size_t sz) {
    void * res = mem + usedMem;
    usedMem += sz;
    return res;
}

void operator delete(void * p) {}
*/
const int INF = (int)1e9 + 5;

const int maxn = 200500;

struct edge {
    int x, y, c;
    edge() {}
    edge(int x, int y, int c) : x(x), y(y), c(c) {}
};

struct state {
    int from, to, c;
    state() {}
    state(int from, int to, int c) : from(from), to(to), c(c) {}
    bool operator <(const state & B) const {
        return from < B.from || (from == B.from && (c < B.c || (c == B.c && to < B.to)));
    }
    bool operator ==(const state & B) const {
        return to == B.to && c == B.c && from == B.from;
    }
};

edge e[maxn * 2];
int N, M, D, statesCnt;
state states[maxn * 2];
int d[maxn * 2];
int q[maxn * 2];
int qs, qe;
int L[maxn * 2], R[maxn * 2];

int getIdx(state x) {
    return lower_bound(states, states + statesCnt, x) - states;
}

void relax(int idx, int dist) {
    if (d[idx] == -1) {
        d[idx] = dist;
        q[qe++] = idx;
    }
}

int p[maxn * 2], sz[maxn * 2], maxi[maxn * 2];
bool del[maxn * 2];

void initDSU(int n) {
    for (int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
        maxi[i] = i;
        del[i] = false;
    }
}

int getDSU(int x) {
    if (x == p[x]) return x;
    return p[x] = getDSU(p[x]);
}

void unionDSU(int x, int y) {
    x = getDSU(x);
    y = getDSU(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    sz[y] += sz[x];
    p[x] = y;
    if (maxi[x] > maxi[y]) maxi[y] = maxi[x];
}

int norm(int v) {
    if (!del[v]) return v;
    v = maxi[getDSU(v)] + 1;
    return v;
}

int nxt(int v) {
    return norm(v + 1);
}

void dele(int v) {
    del[v] = true;
    if (v - 1 >= 0 && del[v - 1]) unionDSU(v - 1, v);
    if (v + 1 < statesCnt && del[v + 1]) unionDSU(v, v + 1);
}

int solve(int A, int B) {
    initDSU(statesCnt);
    fill(d, d + statesCnt, -1);
    qs = qe = 0;
    for (int i = 0; i < statesCnt; i++)\
        if (states[i].from == A) {
            relax(i, 1);
        }
    while (qs < qe) {
        int v = q[qs++];
        int it = norm(L[v]);
        while (it < R[v]) {
            relax(it, d[v] + 1);
            dele(it);
            it = nxt(it);
        }
    }
    int res = INF;
    for (int i = 0; i < statesCnt; i++)
        if (states[i].to == B && d[i] != -1) res = min(res, d[i]);
    if (res == INF) return -1;
    return res;
}

bool cmp(const edge & A, const edge & B) {
    return A.x < B.x || (A.x == B.x && A.c < B.c);
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
        e[i].x = nextInt<int>();
        e[i].y = nextInt<int>();
        e[i].c = nextInt<int>();
        states[statesCnt++] = state(e[i].x, e[i].y, e[i].c);
        states[statesCnt++] = state(e[i].y, e[i].x, e[i].c);
    }

    sort(e + 1, e + M + 1, cmp);
    sort(states, states + statesCnt);
    statesCnt = unique(states, states + statesCnt) - states;
    for (int i = 0; i < statesCnt; i++) {
        L[i] = lower_bound(states, states + statesCnt, state(states[i].to, -1, states[i].c - D)) - states;
        R[i] = upper_bound(states, states + statesCnt, state(states[i].to, INF, states[i].c + D)) - states;
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
