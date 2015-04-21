#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define prev prev_
#define next next_

const double eps = 1e-7;

struct Point {
    ll x, y;
    Point() {
        x = y = 0;
    }
    Point(ll xx, ll yy) {
        x = xx;
        y = yy;
    }
    Point operator + (Point b) {
        return Point(x + b.x, y + b.y);
    }
    Point operator - (Point b) {
        return Point(x - b.x, y - b.y);
    }
    double dist() {
        return sqrt(x * x + y * y);
    }
    Point operator * (ll k) {
        return Point(x * k, y * k);
    }
    ll operator * (Point b) {
        return x * b.x + y * b.y;
    }
    ll operator % (Point b) {
        return x * b.y - y * b.x;
    }
};

int sign_(ll x) {
    if (x == 0) {
        return 0;
    }
    return (x < 0) ? 1 : -1;
}

struct Seg {
    Point a, b;
    Seg() {
    }
    Seg(Point aa, Point bb) {
        a = aa;
        a = bb;
    }
    bool check(Point c) {
        return fabs((a - c).dist() + (b - c).dist() - (a - b).dist()) < eps;
    }
    bool check(Seg B) {
        if (sign_((B.a - a) % (b - a)) * sign_((B.b - a) % (b - a)) == -1
        && (sign_((B.a - B.b) % (a - B.b)) * sign_((B.a - B.b) % (b - B.b))) == -1) {
            return 1;
        }
        return 0;
    }
};

int main() {
    #define task "a"
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int A, B;
    cin >> A >> B;
    int n;
    cin >> n;
    vector<vector<Point> > a(n);
    set<ll> xes;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        m++;
        a[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j].x >> a[i][j].y;
            xes.insert(a[i][j].x);
        }
    }
    int l = xes.size();
    vector<vector<double> > vals(n, vector<double>(l));
    for (int i = 0; i < n; i++) {
        int j = 0;
        int jj = 0;
        for (auto x : xes) {
            while (jj + 1 < sz(a[i]) && a[i][jj + 1].x < x) {
                jj++;
            }
            Point p = a[i][jj + 1] - a[i][jj];
            double dxx = (x - a[i][jj].x);
            vals[i][j] = dxx * p.y / p.x + a[i][jj].y;
            j++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int ii = i + 1; ii < n; ii++) {
            int m = 0;
            for (int j = 0; j < l; j++) {
                m |= (int)(vals[i][j] > vals[ii][j] + eps) | 2 * (int)(vals[i][j] + eps < vals[ii][j]);
            }
            if (m == 3) {
                cout << "No" << endl;
                printf("%d %d\n", i + 1, ii + 1);
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
