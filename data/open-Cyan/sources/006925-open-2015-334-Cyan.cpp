#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (int)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

struct point {
    int x, y;
    point(int _x = 0, int _y = 0) {
        x = _x, y = _y;
    }
};

struct line {
    int a, b, c;

    line() {
        a = b = c = 0;
    }

    line(point f, point s) {
        a = f.y - s.y;
        b = s.x - f.x;
        c = f.x * s.y - s.x * f.y;
    }

    bool intersection(line sc, int x1, int x2) {
        double y11 = 1. * (-a * x1 - c) * sc.b;
        double y12 = 1. * (-a * x2 - c) * sc.b;
        double y21 = 1. * (-sc.a * x1 - sc.c) * b;
        double y22 = 1. * (-sc.a * x2 - sc.c) * b;
        if(y11 > y21 && y22 > y12)
            return 1;
        if(y11 < y21 && y22 < y12)
            return 1;
        return 0;

    }
};

vector <point> v[10000];

int main() {
    inp("input.txt");
    int a, b, n, m, i, j, x, y, ii, jj;
    cin >> a >> b >> n;
    for(i = 1; i <= n; i++) {
        cin >> m;
        for(j = 0; j <= m; j++) {
            cin >> x >> y;
            v[i].pb(point(x, y));
        }
    }
    for(i = 1; i <= n; i++)
        for(j = i + 1; j <= n; j++) {
            for(ii = 1; ii < v[i].size(); ii++)
                for(jj = 1; jj < v[j].size(); jj++) {
//                    cout << i << ' ' << j << "\n\t" << ii << ' ' << jj << "\n";
                    line f = line(v[i][ii - 1], v[i][ii]);
                    line s = line(v[j][jj - 1], v[j][jj]);
                    int aaa = max(v[i][ii - 1].x, v[j][jj - 1].x);
                    int bbb = min(v[i][ii].x, v[j][jj].x);
                    if(f.intersection(s, aaa, bbb)) {
                        cout << "NO\n" << i << ' ' << j << "\n";
                        return 0;
                    }
                }
        }
    cout << "YES\n";
}
