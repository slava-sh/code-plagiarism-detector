#include <iostream>
#include <cstdio>
using namespace std;

int a[10000000];

int main()
{
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int l, r, q;
    for(int i = 0; i < n; i++)
    {
        l = i + 1;
        r = n - 1;
        while(r - l > 1)
        {
            q = (r + l) / 2;
            if((a[q] - a[i]) > k)
                r = q;
            else
                l = q;
        }
        if(a[l] - a[i] > k)
            ans += n - l;
        else
        if(a[r] - a[i] > k)
            ans += (n) - r;
    }
    cout << ans;
    return 0;
}
