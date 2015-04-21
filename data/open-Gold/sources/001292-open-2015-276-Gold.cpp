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
    //freopen("inp", "r", stdin);
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

    if (pref.size()) {
        cur = pref[n-2] * electro;

        for (int i = 1; i < n; i++) {
            cur = min(cur, price*i+(pref[n-2]-pref[i-1])*electro);
        }
    } else {
        cur = 0;
    }

    /*for (auto i: v)
        cout << i << ' ';
    cout << endl;*/

    cout << ans + cur << endl;
}
