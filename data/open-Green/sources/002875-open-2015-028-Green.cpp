#include <iostream>
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

const int INF = int(1e9);
const int MOD = INF + 7;
const ll INFll = 1ll * INF * INF;

map<pair<vi, int>, ll> ans;
vector<pii> a;
vector<vector<ll> > st;

ll get(vi b, int k) {
    if (b.size() > a.size())
        b.pop_back();
    if (ans.count(mp(b, k)))
        return ans[mp(b, k)];
    if (k == 0 && b == vi(b.size(), 0))
        return 1;
    else
        if (k == 0)
            return 0;
    ll res = INFll;
    vi c(b.size() + 1, 0);
    while (c.back() == 0) {
        ll tmp = 1;
        int j = 0;
        while (j < b.size() && c[j] == b[j])
            c[j] = 0, j++;
        c[j]++;
        for (int i = 0; i < b.size(); ++i)
            tmp = tmp * st[i][b[i] - c[i]];
        ll t = get(c, k - 1);
        if (t)
            res = min(res, get(c, k - 1) * (tmp + 1) / 2);
    }
    ans[mp(b, k)] = res;
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    ll n;
    int k;
    cin >> n >> k;
    int d = 2;
    ll N = n;
    while (1ll * d * d <= n) {
        if (n % d == 0) {
            a.pb(mp(d, 0));
            while (n % d == 0)
                a.back().S++, n /= d;
        }
        d += 2 - (d == 2);
    }
    if (n > 1)
        a.pb(mp(n, 1));
    ans[mp(vi(0), 0)] = 1;
    vi b(a.size());
    st.resize(a.size());
    for (int i = 0; i < a.size(); ++i) {
        st[i].pb(1);
        st[i].pb(a[i].F);
        if (a[i].F > 100000)
            st[i].pb(a[i].F * a[i].F);
        else
            while (st[i].back() * a[i].F < N)
                st[i].pb(st[i].back() * a[i].F);
    }
    for (int i = 0; i < b.size(); ++i)
        b[i] = a[i].S;
    cout << get(b, k);
    return 0;
}
