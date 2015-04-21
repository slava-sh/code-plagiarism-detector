#include <bits/stdc++.h>
#define m (l + r) / 2
#define v1 2 * v + 1, l, m
#define v2 2 * v + 2, m, r
#define N 1000001

using namespace std;

int t[4 * N];
int z[4 * N];

int add(int v, int l, int r, int p)
{
    if (z[v])
        z[2 * v + 1] = z[2 * v + 2] = 1, t[v] = z[v] = 0;
    if (l > p || r <= p)
        return t[v];
    if (r - l == 1)
        return t[v] = 1;
    return t[v] = add(v1, p) + add(v2, p);
}

int gets(int v, int l, int r, int x, int y)
{
    if (z[v])
        z[2 * v + 1] = z[2 * v + 2] = 1, t[v] = z[v] = 0;
    if (l >= y || r <= x)
        return 0;
    if (r <= y && l >= x)
        return t[v];
    return gets(v1, x, y) + gets(v2, x, y);
}

int a[N];
int main()
{
    int n, am, ans = -1000000000, bl = -2, br = -2, debug;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
//    if (is_sorted(a, a + n))
//    {
//        cout << "-1 -1";
//        return 0;
//    }
    for (int l = 0; l < n; ++l)
    {
        am = 0;
        z[0] = 1;
//        memset(t, 0, sizeof(t));
        if (l < n - 1 && a[l + 1] > a[l])
            continue;
        for (int r = l + 1; r < n; ++r)
        {
            am += a[r] < a[l];
            add(0, 0, n + 1, a[r]);
            if (r < n - 1 && a[r + 1] < a[r])
                continue;
            if (a[r] > a[l])
                continue;
            if (ans < ((debug = gets(0, 0, n, a[r] + 1, n + 1)) + am - r + l))
            {
                ans = debug + am - r + l;
                bl = l;
                br = r;
            }
        }
    }
    cout << bl + 1 << ' ' << br + 1;
    return 0;
}
