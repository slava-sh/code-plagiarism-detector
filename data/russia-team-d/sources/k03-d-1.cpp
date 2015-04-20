#include <bits/stdc++.h>

#define ll long long
#define fn "fence"

using namespace std;

const int MXN = 1e5 + 9;
const int INF = 1e9 + 9;

int n, k;
int a[MXN];

bool canPaint(int x)
{
    int p = 0;
    for (int i = 1; i <= n; i++)
    {
        if (k - p < x)
            return false;

        p = p + x + max(0, a[i] - x - p);
    }
    return true;
}

int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    sort(a + 1, a + n + 1);

    int l = 0,
        r = a[1] + 1;

    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (canPaint(m))
            l = m;
        else
            r = m;
    }
    cout << l;
    return 0;
}
