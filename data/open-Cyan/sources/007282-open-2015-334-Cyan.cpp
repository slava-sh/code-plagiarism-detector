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
    int put(int x) {
        return -a * x - c;
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
            ii = 1, jj = 0;
            int aaa = 0, bbb = 0;
            for(jj = 0; jj < v[j].size(); jj++) {
                while(v[i][ii].x < v[j][jj].x)
                    ii++;
                line f = line(v[i][ii - 1], v[i][ii]);
                if(v[j][jj].y * f.b > f.put(v[j][jj].x))
                    aaa = 1;
                if(v[j][jj].y * f.b < f.put(v[j][jj].x))
                    bbb = 1;

            }
            if(aaa && bbb) {
                cout << "No\n";
                cout << i << ' ' << j << "\n";
                return 0;
            }
        }
    cout << "Yes\n";
}
