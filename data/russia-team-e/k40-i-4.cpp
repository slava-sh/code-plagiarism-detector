#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long
#define in(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

ll n, d;
ll a[100010];

int main() {
    in("sochi.in");
    out("sochi.out");

    ll ans(0), i, kol(0), j(0);
    cin >> n >> d;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    sort(a + 1, a + 1 + n);
    if(n >= 2 && a[n] + a[n - 1] - 2ll * d >= ans && a[n - 1] > d)
        ans = a[n] + a[n - 1] - 2ll * d;

    for(i = n; i >= 1; i--) {
        if(a[i] >= 3ll * d) {
            kol += a[i] - 2ll * d;
        } else {
            j = i;
            break;
        }
    }
    if(kol > 0) {
        ans = max(ans, kol + 2ll * d);
        if(j >= 1 && a[j] > d) {
            ans = max(ans, kol + a[j]);
        }
        if(j >= 2 && a[j - 1] > d)
            ans = max(ans, kol + a[j - 1] + a[j] - 2ll * d);
    }
    cout << ans;
}
