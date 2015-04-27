#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define sz(a) ((int)((a).size()))
#define forn(i, n) for (int i = 0; i < (n); i++)
#define foreach(i, a) for (typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define eprintf(...) {fprintf(stderr,__VA_ARGS__);fflush(stderr);}
typedef pair<int, int> ii;
typedef long long LL;

int n, m;
char a[1002][1002];
int ans[1002][1002], b[1002][1002];
int q[1<<20], let[10];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int comp_size(int x, int y, int it) {
    int qb = 0, qe = 0;
    q[qe++] = (x << 11) + y;
    b[x][y] = it;
    while (qb < qe) {
        int zz = q[qb++];
        int xx = zz >> 11, yy = zz & 2047;
        forn(dd, 4) {
            int xxx = xx + dx[dd], yyy = yy + dy[dd];
            if (xxx < 0 || yyy < 0 || xxx >= n || yyy >= m) continue;
            if (b[xxx][yyy] == it || ans[xxx][yyy] != ans[x][y]) continue;
            b[xxx][yyy] = it;
            q[qe++] = (xxx << 11) + yyy;
        }
    }
    return qb;
}

int mark_let(int x, int y) {
    int qb = 0, qe = 0;
    q[qe++] = (x << 11) + y;
    b[x][y] = 1;
    while (qb < qe) {
        int zz = q[qb++];
        int xx = zz >> 11, yy = zz & 2047;
        forn(dd, 4) {
            int xxx = xx + dx[dd], yyy = yy + dy[dd];
            if (xxx < 0 || yyy < 0 || xxx >= n || yyy >= m) continue;
            if (ans[xxx][yyy] != ans[x][y]) {
                if (ans[xxx][yyy] >= 0 && ans[xxx][yyy] < 10) let[ans[xxx][yyy]] = 1;
                continue;
            }
            if (b[xxx][yyy]) continue;
            b[xxx][yyy] = 1;
            q[qe++] = (xxx << 11) + yyy;
        }
    }
    return qb;
}

void repaint(int x, int y, int qb, int color) {
    forn(i, qb) {
        int xx = q[i] >> 11, yy = q[i] & 2047;
        ans[xx][yy] = color;
    }
}

int main() {
    scanf("%d%d\n", &n, &m);
    forn(i, n) gets(a[i]);
    int p = 0;
    forn(i, n) forn(j, m) if (a[i][j] == '.' && !ans[i][j]) {
        forn(d, 4) {
            int x = i + dx[d], y = j + dy[d];
            if (x < 0 || y < 0 || x >= n || y >= m) continue;
            if (a[x][y] == '.' && !ans[x][y]) {
                ans[i][j] = ans[x][y] = p;
                p++;
                break;
            }
        }
    } else if (a[i][j] == '#') ans[i][j] = -1;
    int it = 0;
    forn(i, n) forn(j, m) if (!ans[i][j]) {
        bool ok = false;
        forn(d, 4) {
            int x = i + dx[d], y = j + dy[d];
            if (x < 0 || y < 0 || x >= n || y >= m) continue;
            if (ans[x][y] > 0) {
                it++;
                if (comp_size(x, y, it) < 5) {
                    ans[i][j] = ans[x][y];
                    ok = true;
                    break;
                }
            }
        }
        if (!ok) return 0 * printf("-1\n");
    }
    memset(b, 0, sizeof b);
//forn(i, n) { forn(j, m) printf("%d ", ans[i][j]); printf("\n"); }
    forn(i, n) forn(j, m) if (!b[i][j] && ans[i][j] >= 0) {
        memset(let, 0, sizeof let);
        int qb = mark_let(i, j);
        int mn = -1;
        forn(k, 10) if (!let[k]) { mn = k; break; }
//printf("%d %d %d %d\n", i, j, qb, mn);
//forn(k, 10) printf("%d ", let[k]); printf("\n");
        repaint(i, j, qb, mn);
    }
//printf("\n");
//forn(i, n) { forn(j, m) printf("%d ", ans[i][j]); printf("\n"); }
    forn(i, n) {
        forn(j, m) {
            if (a[i][j] == '#') printf("#");
                else printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
