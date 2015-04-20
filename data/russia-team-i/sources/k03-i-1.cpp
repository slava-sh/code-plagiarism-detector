#include <bits/stdc++.h>

#define ll long long
#define fn "sochi"

using namespace std;

const int MXN = 1e5 + 9;
const int INF = 1e9 + 9;

int n, d, l, r, ans;
int a[MXN];

int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);

    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

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
        printf("%d", a[n]);
        return 0;
    }

    ans = l + r - 2 * d;
    for (int i = 1; i <= n; i++)
        if (a[i] >= 3 * d)
            ans += a[i] - 2 * d;

    printf("%d", max(ans, a[n]));

    return 0;
}
