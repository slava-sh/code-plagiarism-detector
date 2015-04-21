#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <functional>
#include <cassert>
#include <sstream>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a,b,n,x,m;
int xa,ya,xb,yb;

struct segment {
    int xa, ya, xb, yb, idx;
} seg[2001005];

int segi;

ld eps = ld(1e-9);

bool inside(ll xa, ll ya, ld xb, ld yb, ll xc, ll yc) {
    return (xb > xa && xb < xc || xb < xa && xb > xc) &&
            (yb > ya && yb < yc || yb < ya && yb > yc);
}

bool inside(ll a, ll b, ld c) {
    return min(a,b) <= c + eps && c <= max(a,b) + eps;
}

bool is1(ll a, ll b, ll c, ll d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return max(a,c) <= max(b,d);
}

bool intersect(int i, int j) {
    ll A1 = seg[i].ya - seg[i].yb;
    ll B1 = seg[i].xb - seg[i].xa;
    ll C1 = -A1 * seg[i].xa -B1 * seg[i].ya;

    ll A2 = seg[j].ya - seg[j].yb;
    ll B2 = seg[j].xb - seg[j].xa;
    ll C2 = -A2 * seg[j].xa -B2 * seg[j].ya;

    if (A1 < 0 || (A1 == 0 && B1 < 0)) A1 = -A1, B1 = -B1, C1 = -C1;
    if (A2 < 0 || (A2 == 0 && B2 < 0)) A2 = -A2, B2 = -B2, C2 = -C2;

    if (A1 * B2 == A2 * B1) {
        if (A1 * C2 == A2 * C1 && B1 * C2 == B2 * C1) {
            return is1(seg[i].xa, seg[i].xb, seg[j].xa, seg[j].xb) &&
                    is1(seg[i].ya, seg[i].yb, seg[j].ya, seg[j].yb);
        }
    } else {
        ll xp = C2*B1 - C1*B2, xq = A1*B2 - A2*B1;
        ll yp = A2*C1 - A1*C2, yq = A1*B2 - A2*B1;
        return inside(seg[i].xa, seg[i].xb, ld(xp) / ld(xq)) && inside(seg[j].xa, seg[j].xb, ld(xp) / ld(xq)) &&
               inside(seg[i].ya, seg[i].yb, ld(yp) / ld(yq)) && inside(seg[j].ya, seg[j].yb, ld(yp) / ld(yq)) &&
               (fabsl(seg[i].xa - ld(xp) / ld(xq)) > eps || fabsl(seg[i].ya - ld(yp) / ld(yq)) > eps) &&
               (fabsl(seg[j].xa - ld(xp) / ld(xq)) > eps || fabsl(seg[j].ya - ld(yp) / ld(yq)) > eps);
    }
    return false;
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);

    scanf("%d%d%d",&a,&b,&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d",&x,&xa,&ya);
        for (int j = 1; j <= x; ++j) {
            scanf("%d%d",&xb,&yb);
            seg[segi].xa = xa;
            seg[segi].xb = xb;
            seg[segi].ya = ya;
            seg[segi].yb = yb;
            seg[segi].idx = i+1;
            ++segi;
            xa = xb; ya = yb;
        }
    }

    m = segi;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (seg[i].idx == seg[j].idx) continue;
            if (intersect(i, j)) {
                printf("No\n%d %d", min(seg[i].idx, seg[j].idx), max(seg[i].idx, seg[j].idx));
                return 0;
            }
        }
    }

    printf("Yes");

    return 0;
}
