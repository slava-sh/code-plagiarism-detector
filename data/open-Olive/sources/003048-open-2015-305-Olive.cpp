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
//#define int ll

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

const int MAXN = int (1e6) + 100;

int q[MAXN], w[MAXN];

void inv (int *a, int *b, int len) {
    if (len == 1) {
        return;
    }

    int m = len / 2;

    inv (a, b, m);
    inv (a + m, b + m, len - m);

    int x = 0, y = m;
    fori (len) {
        if (y != len && (x == m || a[x] > a[y])) {
            b[i] = a[y];
            q[a[y]] += m - x;
            ++y;
        } else {
            b[i] = a[x];
            ++x;
        }
    }
    copy (b, b + len, a);
}

void inv2 (int *a, int *b, int len) {
    if (len == 1) {
        return;
    }

    int m = len / 2;

    inv2 (a, b, m);
    inv2 (a + m, b + m, len - m);

    int x = 0, y = m;
    fori (len) {
        if (y != len && (x == m || a[x] > a[y])) {
            b[i] = a[y];
            w[INF - a[y]] += m - x;
            ++y;
        } else {
            b[i] = a[x];
            ++x;
        }
    }
    copy (b, b + len, a);
}



INT main () {
    //freopen ("_test.c", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout << fixed << setprecision (15);


    int n;
    cin >> n;

    static int a[MAXN], b[MAXN], tmp[MAXN];;
    fori (n) {
        cin >> a[i];
        b[i] = a[i];
    }

    if (is_sorted (a, a + n)) {
        cout << "-1 -1";
        return 0;
    }

    inv (b, tmp, n);

    /*fori (n) {
        cerr << q[a[i]] << " ";
    }
    cerr << endl;
    fori (n) {
        cerr << b[i] << " ";
    }
    cerr << endl;*/

    fori (n) {
        b[i] = INF - a[n - 1 - i];
    }

    inv2 (b, tmp, n);

    /*fori (n) {
        cerr << w[a[i]] << " ";
    }*/



    /*fori (mi.two) {
        if (a[i] > a[mi.two]) {
            cout << i + 1 << " " << mi.two + 1;
            return 0;
        }
    }*/

    pii r (-1, -1);
    fori (n) {
        r = max (r, pii (q[a[i]], i));
    }

    pii l (-1, -1);
    fori (r.two) {
     //   cerr << w[a[i]] << " ";
        if (w[a[i]] > l.one) {
            l = pii (w[a[i]], i);
        }
    }
    //cerr << endl;

    cout << l.two + 1 << " " << r.two + 1;

}

