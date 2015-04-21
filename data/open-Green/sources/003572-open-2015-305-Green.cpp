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
const ll BIGINF = ll (INFINITY) >> 2ll;
///=============================================

//#define MAXN int (1.1e5)

ll _pow (ll x, ll n) {
    if (x < 2 || n == 1)
        return x;
    if (!n)
        return 1;
    ll y = _pow (x, n / 2ll);
    return y * y * (n % 2 ? x : 1ll);
}

typedef pair <ll, int> pli;

const int SQ = 4e7;

ll solve (ll n, int k);

ll fn (vector <int> &mask, const vector <pli> &p, const ll n, const int k) {
    int num = mask.size();

   //cerr << "fn " << n << " " << k << " " << num << endl;

    if (num == p.size()) {
        ll cur = 1;

        fori (num) {
            //cerr << mask[i] << " " << p[i].one << endl;
            cur *= _pow (p[i].one, mask[i]);
        }


        ll ans = solve (n / cur, k - 1) * ((cur + 1) >> 1ll);
        //cerr << "fn_exit " << n << " " << k << " " << n / cur << " " << cur << " " << ans << endl;
        return ans;
    }

    mask.push_back (0);

    ll res = BIGINF;


    fori (p[num].two + 1) {
        mask[num] = i;
        res = min (res, fn (mask, p, n, k));
    }

    mask.pop_back();
    return res;
}

unordered_map <ll, ll> dp;

ll mhash (ll a, ll b) {
    static const ll MAG = 9997;
    return MAG * a + b;
}

ll solve (ll n, int k) {
    //cerr << "solve " << " " << n << " " << k << endl;

    if (dp.count (mhash (n, k))) {
        return dp[mhash (n, k)];
    }
    if (n == 1)
        return 1;
    if (k == 1)
        return (n + 1ll) / 2ll;

    ll n1 = n;

    vector <pli> p;

    qfor (i, 2, SQ) {
        if (n1 == 1) {
            break;
        }
        if (n1 % i == 0) {
            p.push_back (pii (i, 0));
        }
        while (n1 % i == 0) {
            n1 /= i;
            ++p.back().two;
        }
    }

    if (n1 != 1) {
        p.push_back (pii (n1, 1));
    }

    vector <int> mask;

    ll ans = fn (mask, p, n, k);

    dp[mhash (n, k)] = ans;
    //cerr << "solve_exit " << " " << n << " " << k << " " << ans << endl;
    return ans;
}

INT main () {
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout << fixed << setprecision (15);

    ll n, k;
    cin >> n >> k;

    cout << solve (n, k);


    /*n1 = n;

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

    cout << ans << endl;*/


}

