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
    double x, y;
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
};


bool operator < (Point a, Point b) {
    return a.x < b.x;
}

const int maxN = 404;
const int maxL = 404;
Point a[maxN][maxL];
int m[maxN];
double c[maxL * 2];

int len = 0;
void merge_(int ii, int jj) {
    int i = 0;
    int j = 0;
    len = 0;
    while(i < m[ii] && j < m[jj]) {
        if (a[ii][i].x < a[jj][j].x) {
            c[len++] = a[ii][i++].x;
        } else {
            c[len++] = a[jj][j++].x;
        }
    }
    while(i < m[ii]) {
        c[len++] = a[ii][i++].x;
    }
    while(j < m[jj]) {
        c[len++] = a[jj][j++].x;
    }
}

bool check(int i, int j) {
    merge_(i, j);
    int q = 0;
    for (int k = 0; k < len; k++) {
        int jj1 = 0;
        int jj2 = 0;
        double x = c[k];
            while (jj1 + 1 < m[i] && a[i][jj1 + 1].x + eps < x) {
                jj1++;
            }
            while (jj2 + 1 < m[j] && a[j][jj2 + 1].x + eps < x) {
                jj2++;
            }
            double dx = a[i][jj1 + 1].x - a[i][jj1].x;
            double dy = a[i][jj1 + 1].y - a[i][jj1].y;
            double dxx = (x - a[i][jj1].x);
            double v1 = dxx * dy / dx + a[i][jj1].y;

        dx = a[j][jj2 + 1].x - a[j][jj2].x;
        dy = a[j][jj2 + 1].y - a[j][jj2].y;
        dxx = (x - a[j][jj2].x);
        double v2 = dxx * dy / dx + a[j][jj2].y;

        q |= (int)(v1 > v2 + eps);
        q |= 2 * (int)(v2 > v1 + eps);
        if (q == 3) {
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
    vector<pair<int,int> > minx;
    for (int i = 0; i < n; i++) {
        cin >> m[i];
        m[i]++;
        int mn = 1.1e9;
        for (int j = 0; j < m[i]; j++) {
            int x;
            cin >> x;
            mn = min(x, mn);
            cin >> a[i][j].y;
            a[i][j].x = x;
        }
        minx.push_back({mn, i});
    }
    sort(minx.begin(), minx.end());
    for (int k = 0; k < n - 1; k++) {
        int i = minx[k].se;
        for (int d = 1; d < 50 && k + d < n; d++) {
            int j = minx[k + d].se;
            if (check(i, j)) {
                    cout << "No" << endl;
                    cout << i + 1 << " " << j + 1 << endl;
                    return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
