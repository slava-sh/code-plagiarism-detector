#include <bits/stdc++.h>

#define ll long long
#define fn "sochi"

using namespace std;

const int MXN = 2 * 1e5 + 9;
const int INF = 1e9 + 9;

int n, d, l, r, ans;
int a[MXN];

int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);

    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    ans = a[n];
    if (n > 1)
        ans = max(ans, a[n] + a[n - 1] - 2 * d);

    if (a[1] >= d && a[2] >= d)
    {
        int res = a[1] + a[2] - 2 * d;
        for (int i = 3; i <= n; i++)
            if (a[i] >= 3 * d)
                res += a[i] - 2 * d;

        ans = max(ans, res);
    }

    cout << ans;
    return 0;
}
