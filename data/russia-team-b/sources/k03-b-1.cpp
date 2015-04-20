#include <bits/stdc++.h>

#define ll long long
#define fn "che"

using namespace std;

const int MXN = 300 * 1000 + 9;
const int INF = 1000 * 1000 * 1000 + 9;

ll ans;

int x, n, k;
int a[MXN];

int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 2; i <= n; i++)
    {
        int l = 1,
            r = i;

        int t = a[i] - k - 1;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            if (a[m] > t)
                r = m;
            else
                l = m;
        }
        int ind = 0;
        if (a[l] <= t)
            ind = l;
        else if (a[r] <= t)
            ind = r;

        ans += ind;
    }
    cout << ans;
    return 0;
}
