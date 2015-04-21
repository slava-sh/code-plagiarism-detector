#include <cstdio>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 2e5 + 10;
const int INF = 2e9;

int a[N], ans, n;

void update(int p, int c) {
    int lf = max(p - 10, 1);
    int rh = min(p + 10, n);
    int res1 = 1;
    for (int i = lf + 1; i <= rh; i++) {
        if (a[i] != a[i - 1]) {
            res1++;
        }
    }
    a[p] = c;
    int res2 = 1;
    for (int i = lf + 1; i <= rh; i++) {
        if (a[i] != a[i - 1]) {
            res2++;
        }
    }
    ans = ans - res1 + res2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    a[0] = a[n + 1] = INF;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    ans = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            ans++;
        }
    }
    int m;
    scanf("%d", &m);
    for (int q = 1; q <= m; q++) {
        int p, c;
        scanf("%d %d", &p, &c);
        update(p, c);
        printf("%d\n", ans);
    }
    return 0;
}