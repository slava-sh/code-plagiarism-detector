#include <bits/stdc++.h>

#define ll long long
#define fn "sochi"

using namespace std;

const int MXN = 2 * 1e5 + 9;
const int INF = 1e9 + 9;

int sum, q, k, n, d, l, r, ans;
int a[MXN], u[MXN], t[MXN];

int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);

    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        u[a[i]]++;
    }

    sort(a + 1, a + n + 1);

    ans = a[n];
    if (n > 1)
        ans = max(ans, a[n] + a[n - 1] - 2 * d);

    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= 3 * d)
        {
            k++;
            sum += a[i];
            t[a[i]]++;
        }
    }

    for (int l = 1; l <= 1000; l++)
    {
        for (int r = 1; r <= 1000; r++)
        {
            if (l < d)
                continue;

            if (r < d)
                continue;

            if (l == r && u[l] < 2)
                continue;

            if (l != r && u[l] * u[r] == 0)
                continue;

            if (l == r)
            {
                if (t[l] == 1)
                    sum -= l, k--;
                else if (t[l] > 1)
                    sum -= 2 * l, k--;
            }
            else
            {
                if (t[l])
                    sum -= l, k--;
                if (t[r])
                    sum -= r, k--;
            }

            ans = max(ans, sum + l + r - 2 * d - 2 * k * d);
        }
    }

    cout << ans;
    return 0;
}
