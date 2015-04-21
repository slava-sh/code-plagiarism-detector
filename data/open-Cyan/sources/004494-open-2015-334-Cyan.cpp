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

const int N = 100010;

struct point {
    int x, y;
    point(int _x = 0, int _y = 0) {
        x = _x, y = _y;
    }
} p;

vector <point> v[N];


istream &operator>>(istream &in, point &p) {
    in >> p.x >> p.y;
    return in;
}

bool intersects(int i, int ii, int j, int jj) {
    int a1, b1, c1;
    int a2, b2, c2;
    point a = v[i][ii];
    point b = v[i][ii - 1];
    a1 = b.y - a.y;
    b1 = a.x - b.x;
    c1 = b.x * a.y - a.x * b.y;
    a = v[j][jj];
    b = v[j][jj - 1];
    a2 = b.y - a.y;
    b2 = a.x - b.x;
    c2 = b.x * a.y - a.x * b.y;

    int m1 = max(v[i][ii - 1].x, v[j][jj - 1].x);
    int m2 = min(v[i][ii].x, v[j][jj].x);
    int y11 = (-a1 * m1 - c1) * b2;
    int y21 = (-a2 * m1 - c2) * b1;
    int y12 = (-a1 * m2 - c1) * b2;
    int y22 = (-a2 * m2 - c2) * b1;
    if(y11 < y21 && y12 > y22)
        return 1;
    if(y11 > y21 && y12 < y22)
        return 1;
    return 0;

}

int main() {
    inp("input.txt");
    must;
    int a, b, i, j, n, m, ii, jj;
    cin >> a >> b >> n;
    for(i = 1; i <= n; i++) {
        for(cin >> m; m >= 0; m--) {
            cin >> p;
            v[i].pb(p);
        }
    }
    for(i = 1; i <= n; i++)
        for(j = i + 1; j <= n; j++) {
            ii = jj = 1;
            while(ii < v[i].size() && jj < v[j].size()) {
                if(intersects(i, ii, j, jj)) {
                    cout << "No\n" << i << ' ' << j;
                    return 0;
                }
                if(v[i][ii].x < v[j][jj].x)
                    ii++;
                else
                    jj++;
            }
        }
    cout << "Yes\n";
}
