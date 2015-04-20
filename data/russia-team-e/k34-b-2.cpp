#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>

typedef
    long long ll;

using namespace std;
ll n, r, k;
ll a[300060];

ll Bin(ll x)
{
    ll l, r, m;
    l = x;
    r = n + 1;
    while (r - l > 1)
    {
        m = (l + r) / 2;
        if (a[m] - a[x] > k)
            r = m;
        else
            l = m;
    }
    if (r == n + 1)
        return -1;
    else
        return r;
}
int main() {
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    ll g = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i < n; i++)
    {
        ll y = Bin(i);
        if (y != - 1)
        g += (n - y + 1);
    }
    printf("%lld", g);
    return 0;
}

