#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <cmath>
using namespace std;
#define CLEAR(a) memset(a, 0, sizeof(a))
#define CLEARF(a) memset(a, -1, sizeof(a))
const double eps = 1e-8;
const double pi = acos(-1.0);

const int MAXN = 2010;

struct point {
    double l, r; int v;
    point() {}
    point(double _l, double _r, int _v) : l(_l), r(_r), v(_v) {}
};


bool visF[MAXN], visT[MAXN];

int solve(int n, vector <point> F, vector <point> T, double hl, double hr) {
    int ans = 0, pf = 0, pt = 0, i;
    double k, x, h;
    if (n & 1) k = ((n - 1) * 100 + hl + hr) / 1e5;
    else k = ((n - 1) * 100 + hl + 100 - hr) / 1e5;
    CLEAR(visF), CLEAR(visT);
    for (x = 0, i = 1; i <= n; i++) {
        h = (i == 1) ? hl : 100;
        x += h / k;
        if (i & 1) {
            while (pf + 1 < F.size() && F[pf + 1].l <= x + eps) pf++;
            if (x > F[pf].r + eps || x < F[pf].l - eps || visF[pf]) return 0;
            visF[pf] = 1, ans += F[pf].v;
        }
        else {
            while (pt + 1 < T.size() && T[pt + 1].l <= x + eps) pt++;
            if (x > T[pt].r + eps || x < T[pt].l - eps || visT[pt]) return 0;
            visT[pt] = 1, ans += T[pt].v;
        }
    }
    return ans;
}

vector <point> F, T;
bool cmp (point a, point b) {
    return a.l < b.l;
}
int main() {
    double hl, hr, l, r; int n, i, ans, v; char ch;
    while(~scanf("%lf%lf%d", &hl, &hr, &n)){
        T.clear(); F.clear();
        for (i = 1; i <= n; i++) {
            scanf("%d %c%lf%lf", &v, &ch, &l, &r);
            if (ch == 'T') T.push_back(point(l, r, v));
            else F.push_back(point(l, r, v));
        }
        sort(F.begin(), F.end(), cmp), sort(T.begin(), T.end(), cmp);
        for (ans = 0, i = 1; i <= n; i++) {
            ans = max(ans, solve(i, F, T, hl, hr));
            ans = max(ans, solve(i, T, F, 100. - hl, 100. - hr));
        }
        printf("%d\n", ans);
    }
    return 0;
}
