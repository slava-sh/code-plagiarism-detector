 # include <iostream>
 # include <cstdio>
 # include <cstdlib>
 # include <algorithm>
 # include <set>

 using namespace std;

 typedef long long ll;

 const ll mod = ll (1e9) + 7;
 const int N = int (1e5);

 set <int> st;

 ll n, f[N], b[N], a[N], cnt;
 ll p[N];

 ll bp (ll A, ll B) {
    ll res = 1;
    while (B) {
        if (B&1) {
            res *= A;
            res %= mod;
        }
        A *= A; A %= mod;
        B >>= 1ll;
    }
    return res % mod;
 }

 struct fenvick_tree {
    void upd (int x, int cr) {
        for (int i = x; i <= n; i += p[i])
            f[i] += cr;
    }
    ll get (int pos) {
        ll sum = 0;
        for (int i = pos; i >= 1; i -= p[i])
            sum += f[i];
        return sum;
    }
 } rmq;


 int main ()
 {

    freopen ("binary.in", "r", stdin);
    freopen ("binary.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = i & (-i);
    }

    for (int i = 1; i <= n; ++i) {
        if (a[i] + i - 1 > n) {
            cout << 0;
            return 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
       if (a[i] > 0) {
            rmq.upd (i, 1);
            rmq.upd (i + a[i], -1);
            rmq.upd (1, 1);
            rmq.upd (1 + a[i], -1);
       }
    }

    int r = 0;
    for (int tt = 1; tt <= n; ++tt) {
        b[tt] = rmq.get (tt);
        if (!b[tt] && a[tt] == -1) cnt ++;
        if (b[tt]) r = 2;
        if (b[tt] == 0 && b[1]) st.insert (tt);
    }

    if (a[1] != -1 && b[1] == 0 && n > 2) {
        cout << 0;
        return 0;
    }

    if (st.size () + 1 > 2) {
        cout << 0;
        return 0;
    }
    cout << ((r ? 2ll : 1) * bp (2, cnt)) % mod << endl;
 }
