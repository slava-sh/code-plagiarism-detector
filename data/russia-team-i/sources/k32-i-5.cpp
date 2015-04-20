 # include <iostream>
 # include <cstdio>
 # include <cstdlib>
 # include <algorithm>
 # include <set>

 using namespace std;

 const int N = (int) 1e6;

 int cur, n, d, a[N], L, R;

 int main () {

   freopen ("sochi.in", "r", stdin);
   freopen ("sochi.out", "w", stdout);

    cin >> n >> d;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort (a + 1, a + n + 1);

    R = a[n];
    cur = a[n];

    for (int i = n - 1; i >= 1; --i) {
        int len1 = min (L, R), len2 = max (L, R);
        if (len1 - d >= d && (a[i] - d) + (cur - d) > cur) {
            if (len1 == L)
                L = a[i] - d;
            else R = a[i] - d;
            cur = (a[i] - d) + (cur - d);
        }
        else if (len2 - d >= d && (a[i] - d) + (cur - d) > cur) {
            if (len2 == L)
                L = a[i] - d;
            else R = a[i] - d;
            cur = (a[i] - d) + (cur - d);
        }
    }

    cout << cur << endl;

    return 0;
 }
