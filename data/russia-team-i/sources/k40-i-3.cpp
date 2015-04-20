#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

const int N = 1000 * 100 + 10;
ll a[N];

void out(ll a) {
    cout << a;
    exit(0);
}

int main() {
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);


    ll n, d, i, j(0), kol(0), ma(0);
    cin >> n >> d;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);

    }
    sort(a + 1, a + 1 + n);
    if(n > 1 && a[n - 1] > d)
        ma = max(ma, a[n - 1] + a[n] - 2ll * d);
    for(i = n; i >= 1; i--) {
        if(a[i] >= 3ll * d)
            kol += a[i] - 2ll * d;
        else {
            j = i;
            break;
        }
    }
    if(kol > 0) {
        ma = max(ma, kol + 2ll * d);
        if(j >= 1 && a[j] > d)
            ma = max(ma, kol + a[j]);
        if(j > 1 && a[j - 1] > d)
            kol = max(ma, kol + a[j] + a[j - 1] - 2ll * d);
    }
    cout << ma;
}
