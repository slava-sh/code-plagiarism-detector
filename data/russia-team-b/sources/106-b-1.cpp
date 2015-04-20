#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <string>

using namespace std;

typedef long long ll;
const int N = (int)(3e5) + 7;

int a[N];

int main()
{
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        int j = upper_bound(a, a + n, a[i] + r) - a;
        res += (ll)(n - j);
    }
    cout << res << endl;
    return 0;
}
