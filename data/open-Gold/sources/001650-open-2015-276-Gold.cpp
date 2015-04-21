#include <bits/stdc++.h>
#define dout if (true) cout

using namespace std;

typedef long long ll;

ll n, quality, price, electro;
ll a, b, oldb;

ll ans = 0;
ll cur = 1e18;

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin >> n >> quality >> price >> electro;

    vector<ll> v(n-1);

    for (ll i = 0; i < n; i++) {
        cin >> a >> b;
        if (i) {
            v[i-1] = a-oldb;
        }
        ans += (b-a)*electro;
        oldb = b;
    }
    sort(v.rbegin(), v.rend());

    vector<ll> pref(v.begin(), v.end());
    for (int i = 1; i < n-1; i++)
        pref[i] += pref[i-1];

    /*cout << "PREF:" << endl;
    for (auto i: pref)
        cout << i << ' ';
    cout << endl;*/

    // make QUALITY count!
    if (pref.size()) {
        cur = pref[n-2] * electro;

        for (int i = 0; i < n; i++) {
            ll val = min((i+1)*quality-1, n-1);
            cur = min(cur, price*i+(pref[n-2] - (val > 0 ? pref[val-1] : 0))*electro);
        }
    } else {
        cur = 0;
    }



    cout << ans + cur << endl;
}
