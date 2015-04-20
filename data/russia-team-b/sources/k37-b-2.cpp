#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n, a[300001];

int bs(int x)
{
    int l = 0;
    int r = n, mid;
    while(r - l > 1)
    {
        mid = (l + r) / 2;
        if (a[mid] < x)
            l = mid;
        else
            r = mid;
        //cout << l << " " << r << endl;
    }
    if (a[l] >= x)
        return l;
    if (a[r] >= x)
        return r;
    return -1;
}

int main()
{
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    int r;
    cin >> n >> r;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int el = 0;
    long long ans = 0;
    for(int i = 0; i < n; i++)
        {
            el = bs(a[i] + r + 1);
            if (el != -1)
                ans += n - el;
        }

    cout << ans;

    return 0;
}
