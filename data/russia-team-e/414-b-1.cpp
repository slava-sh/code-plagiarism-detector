#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = (int)3e5 + 10;

int a[N];

int main()
{
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    int n, i, j, k, dist, l, r, mid;
    long long ans = 0;
    cin >> n >> dist;
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for(i = 0; i < n; i++)
    {
        l = i, r = n;
        while(r - l > 1)
        {
            mid = (l + r) / 2;
            if(abs(a[mid] - a[i]) <= dist)
                l = mid;
            else
                r = mid;
        }
        //cout << l << endl;
        ans += 1ll * (n - l - 1);
    }
    cout << ans;
    return 0;
}
