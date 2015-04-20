#include <bits/stdc++.h>

#define ll long long
#define fn "sochi"

using namespace std;

const int MXN = 2 * 1e5 + 9;
const int INF = 1e9 + 9;

ll n, d, l, r, ans;
ll a[MXN];

int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);

    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);

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
        cout << a[n];
        return 0;
    }

    ans = l + r - 2 * d;
    for (int i = 1; i <= n; i++)
        if (a[i] >= 3 * d)
            ans += a[i] - 2 * d;

    cout << max(ans, a[n]);
    return 0;
}
