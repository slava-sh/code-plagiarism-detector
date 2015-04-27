#ifndef LOCAL_BOBER
#pragma comment(linker, "/STACK:134217728")
#endif

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define prev prev239
#define next next239
#define hash hash239
#define rank rank239
#define sqrt(x) sqrt(abs(x))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef double D;
typedef long double LD;
typedef pair<ll, ll> pll;

template<class T> T abs(T x) {return x > 0 ? x : -x;}

#define FILENAME ""

int n;
int m;

map<int, int> col;

bool l1(ii a, ii b) {
    if (a.se != b.se)
        re a.se > b.se;
    re a.fi < b.fi;
}

set<ii, bool (*) (ii, ii)> s(l1);

int main() {
#ifdef LOCAL_BOBER
    freopen("input.txt", "r", stdin);
#endif

#ifndef LOCAL_BOBER
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME".out", "w", stdout);
#endif

    vi v;
    cin >> n;
    rep(i, n) {
        int x;
        scanf("%d", &x);
        v.pb(x);
    }

    sort(all(v));

    rep(i, sz(v))
    col[v[i]]++;

    v.resize(unique(all(v)) - v.begin());

    rep(i, sz(v)) {
        s.insert(mp(v[i], col[v[i]]));
    }

    vvi ans;
    while (sz(s) > 2) {
        ii a[3];
        rep(i, 3) {
            a[i] = *s.begin();
            s.erase(a[i]);
        }
        vi tmp;
        rep(i, 3)
        tmp.pb(a[i].fi);
        sort(all(tmp));
        reverse(all(tmp));
        ans.pb(tmp);
        rep(i, 3) {
            if (a[i].se > 1)
                s.insert(mp(a[i].fi, a[i].se - 1));
        }
    }

    cout << sz(ans) << endl;
    rep(i, sz(ans)) {
        rep(j, 3)
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    re 0;
}
