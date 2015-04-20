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
    if (n > 1 && a[n] >= 2 * d && a[n - 1] >= 2 * d)
        ans = max(ans, a[n] + a[n - 1] - 2 * d);

    l = r = -1;
    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i] >= 2 * d)
        {
            l = a[i];
            r = a[i + 1];

            a[i] = a[i + 1] = 0;
            break;
        }
    }

    if (l == -1)
    {
        cout << ans;
        return 0;
    }

    int res = l + r - 2 * d;
    for (int i = 1; i <= n; i++)
        if (a[i] >= 3 * d)
            res += a[i] - 2 * d;

    cout << max(ans, res);
    return 0;
}
