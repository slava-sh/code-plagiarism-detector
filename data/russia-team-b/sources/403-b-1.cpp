#include <iostream>
#include <stdio.h>

using namespace std;

int a[300010];

int main()
{
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);
    int n, r, i, j = 0, ans = 0;
    cin >> n >> r;
    for (i = 0; i < n; i++)
    {
        scanf ("%d", &a[i]);
        while (a[i] - a[j] > r)
        {
            ans += (n-i);
            j++;
        }
    }
    cout << ans;
    return 0;
}
