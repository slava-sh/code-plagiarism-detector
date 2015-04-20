#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;

#define mp make_pair
#define fi first
#define se second
#define pb push_back

#define FILE "polygon"

const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-9;

ld sqr(ld x) {
    return x * x;
}

bool ldLess(ld x, ld y) {
    return x < y - EPS;
}

bool ldEqual(ld x, ld y) {
    return !ldLess(x, y) && !ldLess(y, x);
}

bool ldGreater(ld x, ld y) {
    return !ldLess(x, y) && !ldEqual(x, y);
}

struct Point {
    ld x, y;

    Point() : x(0), y(0) {}

    Point(ld x, ld y) : x(x), y(y) {}

    Point operator+(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    Point operator-() const {
        return Point(-x, -y);
    }

    Point operator*(ld c) const {
        return Point(x * c, y * c);
    }

    Point operator/(ld c) const {
        return Point(x / c, y / c);
    }

    ld operator%(const Point &p) const {
        return x * p.x + y * p.y;
    }

    ld operator*(const Point &p) const {
        return x * p.y - p.x * y;
    }

    ld len() const {
        return sqrt(sqr(x) + sqr(y));
    }

    Point norm() const {
        return (*this) / len();
    }

    Point norm(ld c) const {
        return (*this) / len() * c;
    }

    Point rot() const {
        return Point(-y, x);
    }

    ld dist(const Point &a, const Point &b) const {
        return fabs((a - *this) * (b - *this)) / (a - b).len();
    }

    void scan() {
        cin >> x >> y;
    }

    void print(char end = '\n') const {
        cout << x << " " << y << end;
    }
};

ld PI = acos(-1);
int n, m;
vector<Point> a;

ld sgn(ld x) {
    if (ldLess(x, 0))
        return -1;
    if (ldGreater(x, 0));
        return 1;
    return 0;
}

bool onSegment(const Point &a, const Point &b, const Point &p) {
    return !ldGreater((p - a).len() + (p - b).len(), (a - b).len());
}

void intersect(const Point &a, const Point &b, ld r, vector<Point> &res) {
    Point o(0, 0);
    ld d = o.dist(a, b);
    if (ldGreater(d, r))
        return;
    ld p = sqrt(max(0.0, sqr(r) - sqr(d)));
    Point u = (b - a).norm(p);
    Point v = (b - a).norm(d).rot() * (-sgn((b - a) * (o - a)));
    if (onSegment(a, b, v + u))
        res.pb(v + u);
    if (onSegment(a, b, v - u))
        res.pb(v - u);
}

ld norm(ld x) {
    if (x < 0)
        return x + 2 * PI;
    return x;
}

int main() {
#ifdef HAKU
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(20);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        a[i].scan();
    Point begPoint(a[0]);
    for (int i = 0; i < n; ++i)
        a[i] = a[i] - begPoint;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        Point w;
        w.scan();
        w = w - begPoint;
        vector<Point> res;
        for (int j = 0; j < n; ++j)
            intersect(a[j], a[(j + 1) % n], w.len(), res);
        ld fst = 2 * PI, snd = 0;
        for (int j = 0; j < (int)res.size(); ++j) {
            fst = min(fst, norm(atan2(w * res[j], w % res[j])));
            snd = max(snd, norm(atan2(w * res[j], w % res[j])));
        }
        snd = 2 * PI - snd;
        fst *= 180.0l / PI;
        snd *= 180.0l / PI;
        cout << fst << " " << snd << "\n";
    }
    return 0;
}
