#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

const int maxn = 100010;

typedef long long ll;
typedef long double ld;

struct tree {
    int cnt, l, r;
};

tree t[maxn * 4];

void add(int v, int tl, int tr, int x, int s) {
    if (tl > x || tr < x) return;
    if (tl == tr) {
        t[v].l = s;
        t[v].r = s;
        t[v].cnt = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    add(v * 2, tl, tm, x, s);
    add(v * 2 + 1, tm + 1, tr, x, s);
    t[v].l = t[v * 2].l;
    t[v].r = t[v * 2 + 1].r;
    t[v].cnt = t[v * 2].cnt + t[v * 2 + 1].cnt;
    if (t[v * 2].r == t[v * 2 + 1].l) t[v].cnt--;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        add(1, 1, n, i + 1, x);
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int p, c;
        scanf("%d%d", &p, &c);
        add(1, 1, n, p, c);
        cout << t[1].cnt << endl;
    }

    return 0;
}

