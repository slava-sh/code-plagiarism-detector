#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 2010;

struct point {
    int x, y;
    point() {}
    point(int x, int y): x(x), y(y) {}
};

struct point2 {
    int n;
    point a;
    point2() {}
    point2(point a, int n): a(a), n(n) {}
};

vector<point> a[maxn];
int l[maxn], cur[maxn], u[maxn][maxn];
ld yy[maxn];
vector<point2> p;

bool cmp2(point2 a, point2 b) {
    return a.a.x < b.a.x;
}

long double f(point a, point b, point c) {
    point v;
    v.x = c.x - b.x;
    v.y = c.y - b.y;
    ld ans = 1.0 * (a.x - b.x) * v.y / v.x;
    return b.y + ans;
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int A, B;
    scanf("%d%d", &A, &B);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &l[i]);
        for (int j = 0; j < l[i] + 1; ++j) {
            int x, y;
            scanf("%d%d", &x, &y);
            a[i].push_back(point(x,y));
            p.push_back(point2(a[i].back(), i));
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][0].y < a[j][0].y) u[i][j] = 1;
            if (a[i][0].y > a[j][0].y) u[i][j] = 2;
        }
    }
    sort(p.begin(), p.end(), cmp2);
    for (int i = 0; i < (int)p.size(); ++i) {
        cur[p[i].n]++;
        if (cur[p[i].n] == 1) continue;
        for (int j = 0; j < n; ++j) {
            yy[j] = f(p[i].a, a[j][cur[j] - 1], a[j][cur[j]]);
        }
        for (int j = 0; j < n; ++j) {
            if (u[p[i].n][j] == 0) {
                if (yy[p[i].n] < yy[j]) u[p[i].n][j] = 1, u[j][p[i].n] = 2;
                else if (yy[p[i].n] > yy[j]) u[p[i].n][j] = 2, u[j][p[i].n] = 1;
            } else if (u[p[i].n][j] == 1) {
                if (yy[j] < yy[p[i].n]) {
                    cout << "No" << endl;
                    cout << p[i].n + 1 << ' ' << j + 1 << endl;
                    return 0;
                }
            } else {
                if (yy[j] > yy[p[i].n]) {
                    cout << "No" << endl;
                    cout << p[i].n + 1 << ' ' << j + 1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}

