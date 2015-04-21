#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 1011111111;

struct tree {
    int a[4 * max_n], f[4 * max_n], s[4 * max_n];
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            a[v] = 1;
            f[v] = value;
            s[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        a[v] = a[2 * v] + a[2 * v + 1];
        f[v] = f[2 * v];
        s[v] = s[2 * v + 1];
        if (s[2 * v] == f[2 * v + 1]) {
            --a[v];
        }
    }
    int get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int n, q, a[max_n];
tree t;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        t.update(1, 1, n, i, a[i]);
    }
    scanf("%d", &q);
    while (q--) {
        int poz, v;
        scanf("%d%d", &poz, &v);
        t.update(1, 1, n, poz, v);
        printf("%d\n", t.a[1]);
    }
    return 0;
}
