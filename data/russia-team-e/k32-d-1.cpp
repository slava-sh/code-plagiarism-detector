 # include <iostream>
 # include <cstdio>
 # include <cstdlib>
 # include <algorithm>

 using namespace std;

 const int N = 1 << 20;

 int ans, a[N], n, k, L = 1, R = (int)1e9;

 bool check (int x) {
    int r = a[1];
    for (int tt = 2; tt <= n; ++tt) {
        r += x;
        r = max (r, a[tt]);
        if (r > k) return false;
    }
    return (r <= k);
 }

 int main () {

    freopen ("fence.in", "r", stdin);
    freopen ("fence.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        R = min (R, a[i]);
    }

    sort (a + 1, a + n + 1);

    while (L <= R) {
        int m = (L + R) >> 1;
        if (check (m)) {
            L = m + 1;
            ans = m;
        }
        else R = m - 1;
    }
    cout << ans << endl;
 }
