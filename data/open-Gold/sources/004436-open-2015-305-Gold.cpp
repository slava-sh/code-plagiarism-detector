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
    int k, c, d;

    cin >> n >> k >> c >> d;

    static int a[MAXN], b[MAXN], dp[MAXN];
    fori (n) {
        cin >> a[i] >> b[i];
    }

    dp[0] = d * (b[0] - a[0]);

    qfor (i, 1, n) {
        dp[i] = min (dp[i - 1] + c, dp[i - 1] + d * (a[i] - b[i - 1])) + d * (b[i] - a[i]);
    }

    cout << dp[n - 1];

}

