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


    ll n, d, i, j, kol(0), ma(0);
    cin >> n >> d;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    if(n == 1)
        out(a[1]);
    if(a[n] < 3ll * d)
        out(a[n]);
    j = 0;
    for(i = n; i >= 1; i--) {
        if(a[i] >= 3ll * d)
            kol += a[i] - 2ll * d;
        else {
            j = i;
            break;
        }
    }

    ma = kol + 2ll * d;
    if(kol + a[j] > ma)
        ma = kol + a[j];
    else if(j > 1 && kol + a[j] + a[j - 1] - 2ll * d > ma && a[j] > d && a[j - 1] > d)
        ma = kol + a[j] + a[j - 1] - 2ll * d;
    cout << ma;
}
