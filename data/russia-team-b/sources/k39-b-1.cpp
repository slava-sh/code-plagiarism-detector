#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define sc scanf
#define pr printf
#define fi first
#define se second
#define mk make_pair
#define pb push_back

int d[300002];

int main()
{
    //freopen ("in.txt", "r", stdin);freopen ("out.txt", "w", stdout);
    freopen ("che.in", "r", stdin);freopen ("che.out", "w", stdout);
    int mid, i, j, k, l, m, n, r, ans = 0;
    sc ("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        sc ("%d", &d[i]);
    for (i = 1; i <= n; i++)
    {
        l = i + 1; r = n + 1;
        k = d[i] + m + 1;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (d[mid] >= k)
                r = mid;
            else
                l = mid + 1;
        }
        ans += max (0, n - l + 1);
    }
    cout << ans;
}
