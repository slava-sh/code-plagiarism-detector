#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int a[N], n, k, t, dt;

int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int l = 0;
    int r = a[0] + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        bool b = 1;
        t = a[0];
        for (int i = 1; i < n; i++) {
            if (t + m < a[i])
                dt = a[i] - t;
            else
                dt = m;
            if (t + dt > k)
                dt -= ((t + dt) - k);
            if (dt < m) {
                b = 0;
                break;
            }
            t += dt;
        }
        if (b)
            l = m;
        else
            r = m;
    }
    cout << l;
    return 0;
}
