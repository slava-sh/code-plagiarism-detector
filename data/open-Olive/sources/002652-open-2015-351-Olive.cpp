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

const int max_n = 5055, inf = 1011111111;

struct tree {
    int a[4 * max_n];
    tree() {
        memset(a, 0, sizeof(a));
    }
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            a[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        a[v] = a[2 * v] + a[2 * v + 1];
    }
    int get_sum(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (tl == l && tr == r) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

int n, a[max_n];
tree t1, t2, t3;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int ans1 = -1, ans2 = -1, mn = 0;
    for (int i = 0; i < n; ++i) {
        t3 = tree();
        for (int j = i + 1; j < n; ++j) {
            int x = a[i];
            int y = a[j];
            t2.update(1, 1, n, a[j], 1);
            if (a[i] > a[j]) {
                int pl1 = t1.get_sum(1, 1, n, y + 1, n) - t2.get_sum(1, 1, n, y + 1, n);
                int pl2 = t2.get_sum(1, 1, n, x + 1, n) - t1.get_sum(1, 1, n, x + 1, n);
                int pl3 = -t3.get_sum(1, 1, n, y, x);
                int pl = pl1 + pl2 + pl3;
                //cout << i << " " << j << " : " << pl1 << " " << pl2 << " " << pl3 << endl;
                if (pl < mn) {
                    mn = pl;
                    ans1 = i + 1;
                    ans2 = j + 1;
                }
            }
            t3.update(1, 1, n, a[j], 1);
        }
        for (int j = i + 1; j < n; ++j) {
            t2.update(1, 1, n, a[j], 0);
        }
        t1.update(1, 1, n, a[i], 1);
        t2.update(1, 1, n, a[i], 1);
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
