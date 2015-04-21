#include <bits/stdc++.h>
#define m (l + r) / 2
#define v1 2 * v + 1, l, m
#define v2 2 * v + 2, m, r
#define N 1000001

using namespace std;

int t[4 * N];

int add(int v, int l, int r, int p)
{
    if (l > p || r <= p)
        return t[v];
    if (r - l == 1)
        return t[v] = 1;
    return t[v] = add(v1, p) + add(v2, p);
}

int gets(int v, int l, int r, int x, int y)
{
    if (l >= y || r <= x)
        return 0;
    if (r <= y && l >= x)
        return t[v];
    return gets(v1, x, y) + gets(v2, x, y);
}

int a[N];
int main()
{
    int n, am, ans = 0, bl, br;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (is_sorted(a, a + n))
    {
        cout << "-1 -1";
        return 0;
    }
    for (int l = 0; l < n; ++l)
    {
        am = 0;
        memset(t, 0, sizeof(t));
        if (l < n - 1 && a[l + 1] > a[l])
            continue;
        for (int r = l + 1; r < n; ++r)
        {
            if (r < n - 1 && a[r + 1] < a[r])
                continue;
            am += a[r] < a[l];
            add(0, 0, n + 1, a[r]);
            if (a[r] > a[l])
                continue;
            if (ans < gets(0, 0, n, a[r] + 1, n + 1) + am)
            {
                ans = gets(0, 0, n, a[r] + 1, n + 1) + am;
                bl = l;
                br = r;
            }
        }
    }
    cout << bl + 1 << ' ' << br + 1;
    return 0;
}
