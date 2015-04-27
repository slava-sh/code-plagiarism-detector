#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 105
#define M 100
#define C 1000
#define eps 1e-6

const double D = 1e5;

int hl, hr, n;
int v[N], a[N], b[N];
bool up[N];
int c[N];

int gao(double y) {
    double k = (y - hl) / D;
    fill(c, c + n, 0);
    double x = 0, dx;
    y = hl;
    for (int ci = 0; ci < C && D - x > eps; ++ci) {
        if (k > 0) {
            dx = (100 - y) / k;
            y = 100;
            x += dx;
            if (x > D) break;
            bool flag = false;
            for (int i = 0; i < n; ++i)
                if (up[i]) {
                    if (a[i] - eps <= x && x <= b[i] + eps) {
                        ++c[i];
                        if (c[i] > 1) return 0;
                        flag = true;
                    }
                }
            if (!flag) return 0;
        } else {
            dx = -y / k;
            y = 0;
            x += dx;
            if (x > D) break;
            bool flag = false;
            for (int i = 0; i < n; ++i)
                if (!up[i]) {
                    if (a[i] - eps <= x && x <= b[i] + eps) {
                        ++c[i];
                        if (c[i] > 1) return 0;
                        flag = true;
                    }
                }
            if (!flag) return 0;
        }
        k = -k;
    }
    int sum = 0;
    for (int i = 0; i < n; ++i)
        if (c[i])
            sum += v[i];
    return sum;
}

int main() {
    scanf("%d %d %d", &hl, &hr, &n);
    for (int i = 0; i < n; ++i) {
        char ss[4];
        scanf("%d %s %d %d", &v[i], ss, &a[i], &b[i]);
        up[i] = (ss[0] == 'T');
    }
    int ans = 0;
    for (int i = 0; i < M; ++i) {
        double h = i * 100.0 + (i & 1 ? 100 - hr : hr);
        ans = max(ans, max(gao(h), gao(-h)));
    }
    printf("%d\n", ans);
    return 0;
}