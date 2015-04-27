#pragma comment(linker, "/STACK:64000000")
#include <algorithm>
#include <memory.h>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;
#define prev privet1
#define next privet2
#define y1 privet3
#define rank privet4
#define left privet5
#define right privet6
#define y0 privet7

const double pi = 3.141592653589793238;

void ensureLimit(long long n, long long l, long long r)
{
    assert(l <= n && n <= r);
}

const int delta = 1000300;

int sz, n, m, ar[delta * 2 + 10], f[delta * 8 + 100], b[delta * 2 + 10];
int ans[delta + 10];

void upd(int v, int d) {
    v = v + sz - 1;
    f[v] += d;
    v >>= 1;
    while (v > 0) {
        f[v] = f[v + v] + f[v + v + 1];
        v >>= 1;
    }
}

bool used[1000333];

int getKth(int v, int ll, int rr, int k) {
    if (ll == rr) return ll;
    int c = (ll + rr) >> 1;
    if (f[v + v] >= k) return getKth(v + v, ll, c, k);
    return getKth(v + v + 1, c + 1, rr, k - f[v + v]);
}

int main()
{
    scanf("%d%d", &n, &m);
    sz = 1;
    while (sz < delta * 2) {
        sz += sz;
    }
    for (int i = 1; i <= n; i++) {
        f[i + delta + sz - 1] = 1;
        ar[i + delta] = 0; // ??
        b[i + delta] = i;
    }
    for (int i = sz - 1; i > 0; i--) 
        f[i] = f[i + i] + f[i + i + 1];
    int x, y, id;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        id = getKth(1, 1, sz, y);
        id -= delta;
        //cerr << id << endl;
        if (ar[id + delta] != 0 && ar[id + delta] != x) {
            printf("-1\n");
            return 0;
        }
        if (ar[id + delta] == 0) {
            if (used[x]) {
                printf("-1\n");
                return 0;
            }
            ans[b[id + delta]] = x, used[x] = true;
            ar[id + delta] = x;
        }
        ar[delta - i] = ar[id + delta];
        b[delta - i] = b[id + delta];
        ar[id + delta] = b[id + delta] = 0;
        upd(id + delta, -1);
        upd(delta - i, 1);
    }
//  for (int i = 1; i <= n; i++) 
//      cout << used[i] << " ";
//  cout << endl;
    int j = 1;
    for (int i = 1; i <= n; i++) {
        if (ans[i] != 0) {
            printf("%d ", ans[i]);
            continue;
        }
        while (used[j]) {
            j++;
        }
        printf("%d ", j);
        used[j] = true;
    }
    printf("\n");
}
