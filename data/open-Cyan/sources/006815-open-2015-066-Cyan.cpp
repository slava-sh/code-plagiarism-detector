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


bool operator < (Point a, Point b) {
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}


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

vector<vector<Point> > a;

int len;

bool check(vector<vector<Point> > a) {
    vector<Point> c;
    merge(all(a[0]), all(a[1]), back_inserter(c));
    int n = 2;
    int l = sz(c);
    vector<vector<double> > vals(n, vector<double>(l));
    for (int i = 0; i < n; i++) {
        int j = 0;
        int jj = 0;
        for (auto q : c) {
            int x = q.x;
            while (jj + 1 < sz(a[i]) && a[i][jj + 1].x < x) {
                jj++;
            }
            Point p = a[i][jj + 1] - a[i][jj];
            double dxx = (x - a[i][jj].x);
            vals[i][j] = dxx * p.y / p.x + a[i][jj].y;
            j++;
        }
    }
    int m = 0;
    for (int j = 0; j < l; j++) {
        m |= (int)(vals[0][j] > vals[1][j] + eps);
        m |= 2 * (int)(vals[1][j] < vals[0][j] + eps);
        if (m == 3) {
            return 1;
        }
    }
    return 0;
}

int main() {
    #define task "a"
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int A, B;
    cin >> A >> B;
    int n;
    cin >> n;
    a.resize(n);
    set<ll> xes;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        m++;
        a[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j].x >> a[i][j].y;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<vector<Point> > b;
            b.push_back(a[i]);
            b.push_back(a[j]);
            if (check(b)) {
                cout << "No" << endl;
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
