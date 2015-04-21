#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (lol)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

struct polol {
    lol x, y;
    polol(lol _x = 0, lol _y = 0) {
        x = _x, y = _y;
    }
};

struct line {
    lol a, b, c;

    line() {
        a = b = c = 0;
    }

    line(polol f, polol s) {
        a = f.y - s.y;
        b = s.x - f.x;
        c = f.x * s.y - s.x * f.y;
    }
    lol put(lol x) {
        return -a * x - c;
    }
};

vector <polol> v[10000];

int main() {
    inp("input.txt");
    lol a, b, n, m, i, j, x, y, ii, jj;
    cin >> a >> b >> n;
    for(i = 1; i <= n; i++) {
        cin >> m;
        for(j = 0; j <= m; j++) {
            cin >> x >> y;
            v[i].pb(polol(x, y));
        }
    }
    for(i = 1; i <= n; i++)
        for(j = i + 1; j <= n; j++) {
            ii = 1, jj = 0;
            lol aaa = 0, bbb = 0;
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
