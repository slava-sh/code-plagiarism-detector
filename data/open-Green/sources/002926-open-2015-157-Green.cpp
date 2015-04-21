#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;

typedef long long ll;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << n / 2 + n % 2 << endl;
        return 0;
    } else if (k == 2) {
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                ans = i / 2 + i % 2;
                n /= i;
                ans *= n / 2 + n % 2;
                break;
            }
        }
        cout << ans << endl;
        return 0;
    }

    ll m = n;
    vector<ll> sp;
    for (ll i = 0, p = 2; m != 1 && (int)sp.size() < k - 1; i++) {
        if (m % p == 0) {
            m /= p;
            sp.push_back(p);
        } else {
            p++;
        }
    }

    ll ans = 1;
    for (int i = 0; i < (int)sp.size(); i++) {
        ll need = (sp[i] >> 1LL);
        if (sp[i] & 1LL) {
            ++need;
        }
        ans *= need;
        n /= sp[i];
    }
    ans *= m / 2 + m % 2;

    cout << ans << endl;
}
