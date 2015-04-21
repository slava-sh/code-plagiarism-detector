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

int n;

struct tree {
    int sum[max_n];
    tree() {
        memset(sum, 0, sizeof(sum));
    }
    void update(int poz, int x) {
        for (int i = poz; i <= n; i = (i | (i + 1))) {
            sum[i] += x;
        }
    }
    int get_sum(int r) {
        int res = 0;
        for (int i = r; i > 0; i = (i & (i + 1)) - 1) {
            res += sum[i];
        }
        return res;
    }
    int get_sum(int l, int r) {
        return get_sum(r) - get_sum(l - 1);
    }
};

int a[max_n];
tree t1, t2, t3;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int ans1 = -1, ans2 = -1, mn = 0;
    for (int i = 0; i < n; ++i) {
        t3 = tree();
        int x = a[i];
        for (int j = i + 1; j < n; ++j) {
            int y = a[j];
            t2.update(a[j], 1);
            if (a[i] > a[j]) {
                int pl1 = t1.get_sum(y + 1, n) - t2.get_sum(y + 1, n);
                int pl2 = t2.get_sum(x + 1, n) - t1.get_sum(x + 1, n);
                int pl3 = -t3.get_sum(y, x);
                int pl = pl1 + pl2 + pl3;
                if (pl < mn) {
                    mn = pl;
                    ans1 = i + 1;
                    ans2 = j + 1;
                }
            }
            t3.update(a[j], 1);
        }
        for (int j = i + 1; j < n; ++j) {
            t2.update(a[j], -1);
        }
        t1.update(a[i], 1);
        t2.update(a[i], 1);
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
