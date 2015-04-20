#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double eps = 1e-6;
const double eps2 = 1e-4;
const double pi = acos(-1.0);

struct Point {
    double x, y;

    Point () {}

    Point (double xx, double yy) {
        x = xx;
        y = yy;
    }

    Point operator - (Point a) {
        return Point(x - a.x, y - a.y);
    }

    Point operator + (Point a) {
        return Point(x + a.x, y + a.y);
    }

    double operator * (Point a) {
        return x * a.y - y * a.x;
    }

    Point operator * (double xx) {
        return Point(x * xx, y * xx);
    }

    double operator % (Point a) {
        return x * a.x + y * a.y;
    }

    double len() {
        return sqrt(x * x + y * y);
    }

    double len2() {
        return (x * x + y * y);
    }

    Point norm() {
        return Point(x / len(), y / len());
    }

    Point ro90() {
        return Point(y, -x);
    }
};

double abs(double x) {
    return x < 0 ? -x : x;
}

double sqr(double x) {
    return x * x;
}

double rrr(Point c, Point a, Point b) {
    double aa = a.y - b.y;
    double bb = a.x - b.x;
    double cc = -aa * a.x - bb * a.y;
    return (aa * c.x + bb * c.y + cc) / sqrt(aa * aa + bb * bb);
}

double r2(Point c, Point a, Point b) {
    double aa = a.y - b.y;
    double bb = a.x - b.x;
    double cc = -aa * a.x - bb * a.y;
    return sqr(aa * c.x + bb * c.y + cc) / (aa * aa + bb * bb);
}

double ro(Point c, Point a, Point b) {
    double aa = a.y - b.y;
    double bb = a.x - b.x;
    double cc = -aa * a.x - bb * a.y;
    return fabs(aa * c.x + bb * c.y + cc) / sqrt(aa * aa + bb * bb);
}

Point inter(Point c, double r, Point a, Point b) {
    if (fabs((a - c).len() - r) < eps)
        return a;

    if (fabs((b - c).len() - r) < eps)
        return b;

    if ((a - c).len2() > r * r)
        swap(a, b);

    Point h = c + (b - a).norm() * sqrt(r * r - r2(c, a, b)) + (b - a).norm().ro90() * rrr(c, a, b);
    return h;
}

int n, m;
Point d, p, c;
Point a[2013];
double mn, mx;
bool nll;

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;

    Point c = a[0];

    double vec = (a[1] - a[0]) * (a[n - 1] - a[0]);
    double scl = (a[1] - a[0]) % (a[n - 1] - a[0]);
    vec = 180 * atan2(vec, scl) / pi;

    cin >> m;
    cout.precision(9);
    for (int it = 0; it < m; ++it) {
        cin >> p.x >> p.y;
        nll = false;
        double rad = (c - p).len();
        for (int i = 1; i < n; ++i) {
            if ((a[i] - c).len() > rad + eps && (a[i - 1] - c).len() > rad + eps)
                continue;
            if ((a[i] - c).len() < rad - eps && (a[i - 1] - c).len() < rad - eps)
                continue;
            d = inter(c, rad, a[i], a[i - 1]);
            double dn = atan2((p - c) * (d - c), (p - c) % (d - c));
            double dx = atan2(((c - p) * (d - c)), (p - c) % (d - c));
            if (!nll) {
                mn = dn;
                mx = dx;
                nll = true;
            }
            if (mn > dn)
                mn = dn;
            if (mx < dx)
                mx = dx;
        }
        mx *= 180 / pi;
        mx -= vec;
        mn *= 180 / pi;
        if (mn < eps)
            mn += 360;
        if (mx < eps)
            mx += 360;

        if (mx > 360 - eps || mn > 360 - eps) {
            mx = 360;
            mn = 360;
        }
        cout << fixed << mn;
        cout << " ";
        cout << fixed << mx;
        cout << "\n";
    }

    return 0;
}
