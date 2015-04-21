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

const int MAXN = int (3e5);

bool comp (pii a, pii b) {
    return a.one > b.one || (a.one == b.one && a.two > b.two);
}

INT main () {
    freopen ("_test.c", "r", stdin);

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

    //exit (0);

    int ans1 = BIGINF;
    if (k0 < n) { /// count ans1
        static pii delta[MAXN];

        int sum_all = 0;

        qfor (i, 1, n) {
            sum_all += d0 * (a[i] - b[i - 1]);
            delta[i - 1] = pii (a[i] - b[i - 1], i);
        }

        sort (delta, delta + n - 1, comp);

        int ans = BIGINF;
    ///696903
        int sum_pref = 0;
        for (int i = 0; i < n; i += k0) {
            for (int j = max (0ll, i - k0); j < i; ++j) {
                sum_pref += d0 * (a[delta[j].two] - b[delta[j].two - 1]);
            }
            ans = min (ans, c0 * (i / k0) + sum_all - sum_pref);
        }

        fori (n) {
            ans += d0 * (b[i] - a[i]);
        }

        ans1 = ans;
    }

    //cerr << ans1 << " " << ans2 << endl;

    cout << min (ans1, ans2);

}

