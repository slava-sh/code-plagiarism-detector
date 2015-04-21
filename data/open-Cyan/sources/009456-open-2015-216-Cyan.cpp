#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include <queue>
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 400 + 10;
const double EPS = 1e-9;

pii l[N][N];
int leng[N];
int was, p[N];

int get_coord(int i1, int j1, int x1, int i2, int j2, int x2) {
    ll v1 = (1LL * l[i1][j1 - 1].y * (l[i1][j1].x - l[i1][j1 - 1].x) + (0LL + l[i1][j1].y - l[i1][j1 - 1].y) * ((x1 - l[i1][j1 - 1].x + 0.0))) * (l[i2][j2].x - l[i2][j2 - 1].x);
    ll v2 = (1LL * l[i2][j2 - 1].y * (l[i2][j2].x - l[i2][j2 - 1].x) + (0LL + l[i2][j2].y - l[i2][j2 - 1].y) * ((x2 - l[i2][j2 - 1].x + 0.0))) * (l[i1][j1].x - l[i1][j1 - 1].x);
    if (v1 == v2) {
        return 0;
    } else if (v1 > v2) {
        return 1;
    } else {
        return 2;
    }
}

double yyy(int i, int j, int x) {
    return (1LL * l[i][j - 1].y * (l[i][j].x - l[i][j - 1].x) + (0LL + l[i][j].y - l[i][j - 1].y) * ((x - l[i][j - 1].x + 0.0))) / (l[i][j].x - l[i][j - 1].x);
}

double myabs(double &x, double &y) {
    return (x < y ? y - x : x - y);
}

int main() {
    srand(time(NULL));
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a, b;
    scanf("%d %d", &a, &b);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &leng[i]);
        for (int j = 0; j <= leng[i]; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            x -= a;
            l[i][j] = make_pair(x, y);
        }
    }
    b -= a;
    a = 0;
    bool cmp = false;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    if (n > 300) {
        for (int it = 1; it <= 100000; it++) {
            int x = rand() % n + 1;
            int y = rand() % n + 1;
            swap(p[x], p[y]);
        }
        n = 300;
    }
    for (int ii = 1; ii <= n; ii++) {
        for (int jj = ii + 1; jj <= n; jj++) {
            int i = p[ii];
            int j = p[jj];
            int i1 = 0, i2 = 0;
            was = 0;
            int lf = 0;
            int cnt = 0;
            while (true) {
                cnt++;
                if (l[i][i1].x == lf) {
                    i1++;
                }
                if (i1 > leng[i]) {
                    break;
                }
                if (l[j][i2].x == lf) {
                    i2++;
                }
                if (i2 > leng[j]) {
                    break;
                }
                int rh = l[i][i1].x;
                if (l[j][i2].x < rh) {
                    rh = l[j][i2].x;
                }
                int cmp1, cmp2;
                if (!cmp) {
                    cmp1 = get_coord(i, i1, lf, j, i2, lf);
                    cmp2 = get_coord(i, i1, rh, j, i2, rh);
                } else {
                    double y11 = yyy(i, i1, lf);
                    double y12 = yyy(i, i1, rh);
                    double y21 = yyy(j, i2, lf);
                    double y22 = yyy(j, i2, rh);
                    if (myabs(y11, y12) <= EPS) {
                        cmp1 = 0;
                    } else if (y11 > y12) {
                        cmp1 = 1;
                    } else {
                        cmp1 = 2;
                    }
                    if (myabs(y12, y22) <= EPS) {
                        cmp2 = 0;
                    } else if (y12 > y22) {
                        cmp2 = 1;
                    } else {
                        cmp2 = 2;
                    }
                }
                lf = rh;
                if (cmp1 == 0) {
                    if (cmp2 == 0) {
                        continue;
                    }
                    if (was + cmp2 == 3) {
                        printf("No\n");
                        printf("%d %d\n", i, j);
                        return 0;
                    } else {
                        was = cmp2;
                    }
                    continue;
                }
                if (cmp1 + cmp2 == 3) {
                    printf("No\n");
                    printf("%d %d\n", i, j);
                    return 0;
                }
                was = cmp1;
            }
        }
    }
    printf("Yes\n");
    return 0;
}