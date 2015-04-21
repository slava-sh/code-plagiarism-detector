#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <cmath>
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

const int MAX_MEM = (int)4e8;
char mem[MAX_MEM];
int used_mem = 0;

void * operator new(size_t sz) {
    void * res = mem + used_mem;
    used_mem += sz;
    return res;
}

void operator delete(void * p) {}

const int maxn = (int)1e6 + 5;

pair<int, int> ft[maxn];
int n, a[maxn], pr[maxn], c[maxn], dp[maxn];
bool used[maxn];

void assignFT(int r, pair<int, int> x) {
    while (r < maxn) {
        if (x > ft[r]) ft[r] = x;
        r |= r + 1;
    }
}

pair<int, int> maxFT(int r) {
    pair<int, int> x = ft[r];
    while (r >= 0) {
        if (ft[r] > x) x = ft[r];
        r = (r & (r + 1)) - 1;
    }
    return x;
}

int go(int v) {
    if (used[v]) return dp[v];
    used[v] = true;
    dp[v] = v;
    if (pr[v] != 0) dp[v] = go(pr[v]);
    return dp[v];
}

struct node {
    node * l, * r;
    int sum;
    void upd() {
        sum = l->sum + r->sum;
    }
    node() {}
    node(node * _l, node * _r) {
        l = _l;
        r = _r;
        upd();
    }
    node(int sum) : l(0), r(0), sum(sum) {}
};

node * root[maxn];

node * build(int tl, int tr) {
    if (tl == tr) return new node(0);
    int tm = (tl + tr) >> 1;
    return new node(build(tl, tm), build(tm + 1, tr));
}

node * addTree(node * v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        return new node(v->sum + val);
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
        return new node(addTree(v->l, tl, tm, pos, val), v->r);
    else
        return new node(v->l, addTree(v->r, tm + 1, tr, pos, val));
}

int getSum(node * v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return v->sum;
    }
    int tm = (tl + tr) >> 1;
    if (r <= tm) return getSum(v->l, tl, tm, l, r);
    else if (l > tm) return getSum(v->r, tm + 1, tr, l, r);
    else return getSum(v->l, tl, tm, l, tm) + getSum(v->r, tm + 1, tr, tm + 1, r);
}

void precalc() {
    root[0] = build(1, n);
    for (int i = 1; i <= n; i++) {
        root[i] = addTree(root[i - 1], 1, n, a[i], 1);
    }
}

int foo(int L, int R) {
    return getSum(root[R], 1, n, a[L], a[R]) - getSum(root[L - 1], 1, n, a[L], a[R]);
}

int main()
{
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);

    n = nextInt<int>();

    for (int i = 1; i <= n; i++) {
        a[i] = n - nextInt<int>() + 1;
    }

    precalc();

    for (int i = 1; i <= n; i++) {
        pair<int, int> t = maxFT(a[i] - 1);
        pr[i] = t.second;
        c[pr[i]]++;
        assignFT(a[i], make_pair(t.first + 1, i));
    }

    int best = -1, x = -1, y = -1;

    for (int R = 1; R <= n; R++) {
        if (true) {
            int L = go(R);
            if (L == R) continue;
            int t = foo(L, R);
            if (t > best) {
                best = t;
                x = L, y = R;
            }
        }
    }

    printf("%d %d\n", x, y);

    return 0;
}
