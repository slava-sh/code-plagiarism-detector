 # include <iostream>
 # include <cstdio>
 # include <cstdlib>
 # include <algorithm>

 using namespace std;

 const int N = (int) 1e6;

 int n, d, k, ans;
 int a[N];
 bool used[N];

 int main () {

    freopen ("sochi.in", "r", stdin);
    freopen ("sochi.out", "w", stdout);

    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort (a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i)
        if (a[i] > d + d)
            used[i] = true;

    k = 0;

    for (int i = 1; i <= n && k < 2; ++i)
        if (!used[i] && a[i] > d)
        {
            ++k;
            ans += a[i] - d;
        }

    if (k < 2)
        for (int i = 1; i <= n && k < 2; ++i)
            if (used[i])
            {
                ++k;
                used[i] = false;
                ans += a[i] - d;
            }

    for (int i = 1; i <= n; ++i)
        if (used[i])
            ans += a[i] - d - d;

    cout << ans << "\n";

    return 0;
 }
