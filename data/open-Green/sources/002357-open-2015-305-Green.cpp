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
const T & sqr (const T & x) {
    return x * x;
}

const int INF = 1e9 + 7;
///=============================================

//#define MAXN int (1.1e5)

typedef pair <ll, int> pli;

INT main () {
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout << fixed << setprecision (15);

    ll n, k;
    cin >> n >> k;

    vector <pli> p;
    const int SQ = 4e7;

    ll n1 = n;

    qfor (i, 2, SQ) {
        if (n1 == 1) {
            break;
        }
        if (n1 % i == 0) {
            p.emplace_back (i, 0);
        }
        while (n1 % i == 0) {
            n1 /= i;
            ++p.back().two;
        }
    }

    if (n1 != 1) {
        p.emplace_back (n1, 1);
    }

    n1 = n;

    int cur = 0;
    ll ans = 1;
    fori (k - 1) {
        if (n1 == 1) {
            break;
        }

        if (!p[cur].two) {
            ++cur;
        }

        ans *= (p[cur].one + 1ll) / 2ll;

        --p[cur].two;

        n1 /= p[cur].one;
        //cerr << p[cur].one << " " << ans << endl;
    }

    ans *= (n1 + 1ll) / 2ll;

    cout << ans << endl;


}

