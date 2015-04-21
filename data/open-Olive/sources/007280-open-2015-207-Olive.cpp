#include <algorithm>
#include <iostream>

using namespace std;

int a[1000000];

int main()
{
    int n, bl, br, ans = 0;
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
        for (int r = l + 1; r < n; ++r)
        {
            int inv1 = 0, inv2 = 0;
            for (int i = l + 1; i < r; ++i)
            {
                inv1 += a[l] > a[i];
                inv1 += a[r] < a[i];
                inv2 += a[l] < a[i];
                inv2 += a[r] > a[i];
            }
            inv1 += a[l] > a[r];
            inv2 += a[l] < a[r];
            if (inv1 - inv2 > ans)
            {
                ans = inv1 - inv2;
                bl = l;
                br = r;
            }
        }
    }
    cout << bl + 1 << ' ' << br + 1;
    return 0;
}
