#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define foreach(i, q) for (typeof(q.begin()) i = q.begin(); i != q.end(); ++i)

#ifdef LOCAL
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif // LOCAL

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int INF = int(1e9);
const int MOD = INF + 7;
const ll INFll = 1ll * INF * INF;
const ld EPS = 1e-9;

ld get(int x, pii s, pii t) {
    int y1 = s.S, y2 = t.S, x1 = s.F, x2 = t.F;
    ld k = (y1 - y2) / ld(x1 - x2);
    ld b = (y1 - k * x1);
    return k * x + b;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    int A, B;
    cin >> A >> B;
    int n;
    cin >> n;
    vector<vector<pii> > a(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; ++j)
            cin >> a[i][j].F >> a[i][j].S;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int i1 = 0, j1 = 0;
            int was = -2;
            while (i1 < a[i].size()) {
                int x;
                ld y1, y2;
                if (a[i][i1].F == a[j][j1].F)
                    x = a[i][i1].F, y1 = a[i][i1].S, y2 = a[j][j1].S;
                else
                    if (a[i][i1].F < a[j][j1].F)
                        x = a[i][i1].F, y1 = a[i][i1].S, y2 = get(x, a[j][j1], a[j][j1 - 1]);
                    else
                        x = a[j][j1].F, y2 = a[j][j1].S, y1 = get(x, a[i][i1], a[i][i1 - 1]);
                int nw;
                if (fabs(y1 - y2) <= EPS)
                    nw = 0;
                else
                    if (y1 > y2)
                        nw = 1;
                    else
                        nw = -1;
                if (was == -2) {
                    was = nw;
                    if (!nw)
                        was = -2;
                } else
                    if (nw && nw != was) {
                        cout << "No\n" << i + 1 << " " << j + 1;
                        return 0;
                    } else
                        if (nw)
                            was = nw;
                if (a[i][i1].F == a[j][j1].F)
                    i1++, j1++;
                else
                    if (a[i][i1].F < a[j][j1].F)
                        i1++;
                    else
                        j1++;
            }
        }
    }
    cout << "Yes";
    return 0;
}
