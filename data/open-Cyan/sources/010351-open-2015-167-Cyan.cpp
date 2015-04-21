#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cstdlib>

#define mp make_pair
#define ll long long
#define ld long double
#define pii pair <int, int>
#define fi first
#define se second

using namespace std;

const int N = (int)5e5 + 7;
const ll INF = (ll)1e9 + 7;
const ld EPS = 1e-7;

int a[N], c[N], x[407][407], y[407][407], u[N];
bool bo[407][407];
pair <ld, int> t[N];

bool cmp(pair <ld, int> a, pair <ld, int> b){
    return a.fi > b.fi + EPS;
}

int main(){
    ld x1, x2, y1, y2, a1, b1, c1;
    int aa, bb, p;
    int v = 0, n;
    cin >> aa >> bb;
    a[v++] = aa;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> c[i];
        for (int j = 0; j <= c[i]; j++){
            cin >> x[i][j] >> y[i][j];
            a[v++] = x[i][j];
        }
    }
    a[v++] = bb;
    sort(a, a + v);
    for (int i = 0; i < v; i++){
        if (i > 0 && a[i] == a[i - 1])
            continue;
        p = 0;
        for (int j = 0; j < n; j++){
            while (x[j][u[j]] < a[i])
                u[j]++;
            if (x[j][u[j]] == a[i]){
                t[p++] = mp(y[j][u[j]], j);
                continue;
            }
            x1 = x[j][u[j]], y1 = y[j][u[j]];
            x2 = x[j][u[j] - 1], y2 = y[j][u[j] - 1];
            a1 = y2 - y1, b1 = x1 - x2;
            c1 = - a1 * x1 - b1 * y1;
            t[p++] = mp((-c1 - a1 * (ld)a[i]) / b1, j);
        }
        sort(t, t + p, cmp);
        int nx = 0;
        for (int j = 0; j < p; j++){
            while (nx < p && abs(t[j].fi - t[nx].fi) < EPS)
                nx++;
            for (int c = 0; nx + c < p; c++){
                if (bo[t[nx + c].se][t[j].se])
                    return cout << "No\n" << nx + c + 1 << " " << j + 1, 0;
                bo[t[j].se][t[nx + c].se] = true;
            }
        }
    }
    cout << "Yes";
    return 0;
}
