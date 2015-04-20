#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int a[100100];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    int i,n,k, x,sum = 0,l,r,p;
    bool pr = false;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if (n == 1)
    {
        cout << a[0];
        return 0;
    }
    x = min((k - a[0]) / (n - 1), a[0]);
    l = 0;
    r = x + 1;
    while (r - l > 1)
    {
        p = (l + r) / 2;
        sum = a[0];
        for  (i = 1; i < n && sum <= k; i++)
            sum += max(a[i] - sum, p);
        if (sum <= k)
            l = p;
        if (sum > k)
            r = p;
    }
    cout << l;
    return 0;
}
