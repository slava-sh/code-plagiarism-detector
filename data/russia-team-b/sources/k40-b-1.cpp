#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

const int N = 3 * 1000 * 1000 + 10;
ll a[N], n, R;

ll binary(ll i) {
    ll l = 0, r = i - 1, m;
    while(l + 1 < r) {
        m = (l + r) / 2;
        if(a[i] - a[m] > R)
            l = m;
        else
            r = m;
    }
    if(a[i] - a[r] > R)
        l = r;
    return l;
}

int main() {
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);

    ll i, kol(0);
    cin >> n >> R;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        kol += binary(i);
    }
    cout << kol;
    return 0;
}
