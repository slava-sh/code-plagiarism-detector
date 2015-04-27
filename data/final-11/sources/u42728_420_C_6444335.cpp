//Template
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <ios>
#include <iomanip>
#include <ctime>
#include <numeric>
#include <functional>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <cstdarg>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
#define pair(x, y) make_pair(x, y)
#define runtime() ((double)clock() / CLOCKS_PER_SEC)

inline int read() {
    static int r, sign;
    static char c;
    r = 0, sign = 1;
    do c = getchar(); while (c != '-' && (c < '0' || c > '9'));
    if (c == '-') sign = -1, c = getchar();
    while (c >= '0' && c <= '9') r = r * 10 + (int)(c - '0'), c = getchar();
    return sign * r;
}

template <typename T>
inline void print(T *a, int n) {
    for (int i = 1; i < n; ++i) cout << a[i] << " ";
    cout << a[n] << endl;
}
#define PRINT(_l, _r, _s, _t) { cout << #_l #_s "~" #_t #_r ": "; for (int _i = _s; _i != _t; ++_i) cout << _l _i _r << " "; cout << endl; }

#define N 301000
int n, k, a[N + 1], b[N + 1], cnt[N + 1], tot = 0;
vector <int> p[N + 1];

int arr[N + 1];

inline void modify(int x, int v) {
    for (++x; x > 0; x -= x & -x) arr[x] += v;
}

inline int query(int x) {
    int r = 0;
    for (++x; x <= n + 1; x += x & -x) r += arr[x];
    return r;
}

int main(int argc, char *argv[]) {
#ifdef KANARI
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", a + i, b + i);
        if (a[i] > b[i]) swap(a[i], b[i]);
        p[a[i]].push_back(i);
    }
    ll ans = 0LL;
    for (int i = 1; i <= n; ++i) ++cnt[a[i]], ++cnt[b[i]];
    for (int i = 1; i <= n; ++i) modify(cnt[i], 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < p[i].size(); ++j) {
            modify(cnt[b[p[i][j]]], -1);
            modify(--cnt[b[p[i][j]]], 1);
        }
        modify(cnt[i], -1);
        ans += query(max(0, k - (int)(p[i].size())));
        for (int j = 0; j < p[i].size(); ++j)
            if (a[p[i][j]] != 0) {
                a[p[i][j]] = 0;
                p[b[p[i][j]]].push_back(p[i][j]);
                modify(cnt[b[p[i][j]]], -1);
                modify(++cnt[b[p[i][j]]], 1);
            }
    }
    
    cout << ans << endl;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
