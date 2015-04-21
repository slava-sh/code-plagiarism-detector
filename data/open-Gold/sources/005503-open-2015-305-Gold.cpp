#define _USE_MATH_DEFINES

#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int INT;
#define int ll

typedef pair <int, int> pii;
#define one first
#define two second

#define qfor(i, a, b) for (int i = a; i < int (b); ++i)
#define fori(n) qfor (i, 0, n)
#define forj(n) qfor (j, 0, n)

#define cont(v) v.begin(), v.end()

template <class T>
inline T sqr (const T & x) {
    return x * x;
}

const ld EPS = 1e-9L;
const int INF = 1e9L + 7;
const ll BIGINF = 2e18L;

inline bool equal (ld a, ld b) {
    return abs (a - b) < EPS;
}
///=============================================

const int MAXN = int (4e3);


INT main () {
    //freopen ("_test.c", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout << fixed << setprecision (15);

    int n;
    int k0, c0, d0;

    cin >> n >> k0 >> c0 >> d0;

    static int a[MAXN], b[MAXN];
    fori (n) {
        cin >> a[i] >> b[i];
    }

    int ans2 = 0;
    { /// count ans2
        int more = k0;
        fori (n) {
            ans2 += d0 * (b[i] - a[i]);
            if (more == 0) {
                ans2 += c0;
                more = k0;
            }
            --more;
        }
    }

    int ans1 = BIGINF;
    if (k0 < n) { /// count ans1
        //ld k = k0, c = c0, d = d0;

        int ans = d0 * (b[0] - a[0]);

        ld q = ld (c0) / ld (k0);

        int more = k0 - 1;

        qfor (i, 1, n) {
            ans += d0 * ld (b[i] - a[i]);
            if (!(more == 0 && n - i < k0) && (n - i == more || q < d0 * (a[i] - b[i - 1]))) {
                if (more == 0) {
                    ans += c0;
                    more = k0;
                }
                --more;
            } else {
                ans += d0 * (a[i] - b[i - 1]);
            }
        }

        if (more != 0) {
            return 1;
        }

        ans1 = ans;
    }

    //cerr << ans1 << " " << ans2 << endl;

    cout << min (ans1, ans2);

}

