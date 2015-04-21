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

pii l[N][N];
int leng[N];
int was;

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

void check(int new_was, int i, int j) {
    if (was == 1 && new_was == 2) {
        printf("No\n");

        cout << "No\n";
        cout << i << " " << j << "\n";
        exit(0);
    }
    if (was == 2 && new_was == 1) {
        cout << "No\n";
        cout << i << " " << j << "\n";
        exit(0);
    }
    was = new_was;
}

int main() {
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
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int i1 = 0, i2 = 0;
            was = 0;
            int lf = 0;
            while (true) {
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
                int cmp1 = get_coord(i, i1, lf, j, i2, lf);
                int cmp2 = get_coord(i, i1, rh, j, i2, rh);
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