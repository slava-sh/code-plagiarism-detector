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

const int maxn = 200010;

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
int l[maxn], num[maxn], pos[maxn], cur[maxn];
vector<point2> p;

bool cmp(int x, int y) {
    return a[x][0].y > a[y][0].y;
}

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
        for (int j = 0; j < l[i]; ++j) {
            int x, y;
            scanf("%d%d", &x, &y);
            a[i].push_back(point(x,y));
            p.push_back(point2(a[i].back(), i));
        }
    }
    for (int i = 0; i < n; ++i) num[i] = i;
    sort(num, num + n, cmp);
    sort(p.begin(), p.end(), cmp2);
    for (int i = 0; i < n; ++i) pos[num[i]] = i;
    for (int i = 0; i < (int)p.size(); ++i) {
        cur[p[i].n]++;
        if (cur[p[i].n] == 1) continue;
        if (pos[p[i].n] > 0 && f(p[i].a, a[num[pos[p[i].n] - 1]][cur[num[pos[p[i].n] - 1]] - 1], a[num[pos[p[i].n] - 1]][cur[num[pos[p[i].n] - 1]]]) < p[i].a.y) {
            cout << "No" << endl;
            cout << p[i].n + 1 << ' ' << num[pos[p[i].n] - 1] + 1 << endl;
            return 0;
        }
        if (pos[p[i].n] < n - 1 && f(p[i].a, a[num[pos[p[i].n] + 1]][cur[num[pos[p[i].n] + 1]] - 1], a[num[pos[p[i].n] + 1]][cur[num[pos[p[i].n] + 1]]]) > p[i].a.y) {
            cout << "No" << endl;
            cout << p[i].n + 1 << ' ' << num[pos[p[i].n] + 1] + 1 << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}

