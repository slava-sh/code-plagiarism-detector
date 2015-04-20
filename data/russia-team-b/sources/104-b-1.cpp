#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>

#define problem "che"

using namespace std;

typedef long long ll;

const int N = 300500;

ll a[N];
ll d[N];

int main()
{
    assert(freopen(problem".in", "r", stdin) != NULL);
    assert(freopen(problem".out", "w", stdout));

    ll n, r;
    cin >> n >> r;
    for (ll i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    ll k = 0;
    for (ll i = 0; i < n; ++i) {
        for(; k < n && a[k] - a[i] <= r; ++k);
        d[i] = k;
//        cout << d[i] << endl;
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += n - d[i];
    }
    printf("%lld\n", ans);
    return 0;
}
