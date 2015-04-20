 # include <iostream>
 # include <cstdio>
 # include <cstdlib>
 # include <algorithm>

 using namespace std;

 const int N = (int) 1e5;

 typedef long long ll;

 int n, d;
 int a[N];
 ll ans = 0;

 int main () {

    freopen ("che.in", "r", stdin);
    freopen ("che.out", "w", stdout);

    scanf ("%d%d", &n, &d);
    for (int i = 1; i <= n; ++i)
        scanf ("%d", &a[i]);

    sort (a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i) {
        int it = upper_bound (a + 1, a + n + 1, a[i] + d) - a;
        ans += max ((long long)n - it + 1, 0LL);
    }

    cout << ans << endl;
    return 0;
 }
