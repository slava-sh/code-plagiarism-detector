#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
#define forn(i,a,b) for(ll i = a; i < (ll)b; i++)
#define srep(i, a) for(__typeof(a.begin()) i = a.begin(); i != a.end(); i++)

typedef pair<ll, ll> pii;
#define fi first
#define se second
#define mp make_pair

const ll maxn = 200005;
const ll INF = 1e9;

pii a[maxn];
ll t[maxn];

inline ll dup(ll a, ll b)
{
    ll r = a / b;
    if (r * b < a) r++;
    return r;
}

int main()
{
    ll n, k, c, d;
    cin >> n >> k >> c >> d;
    ll tres = 0;
    rep(i, n)
    {
        cin >> a[i].fi >> a[i].se;
        tres += a[i].se - a[i].fi;
    }
    tres *= d;
    rep(i, n-1)
    {
        t[i] = a[i+1].fi - a[i].se;
    }
    sort(t, t+n-1);
    ll res = dup(n, k)*c;
    ll ts = 0;
    rep(i, n-1)
    {
        ts += t[i];
        res = min(res, ts*d + dup(n-i-1, k)*c);
    }
    cout << res + tres - c;
    return 0;
}
