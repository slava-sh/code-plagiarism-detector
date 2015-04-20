#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, r, a[1000000], ans;

int main()
{
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    cin >> n >> r;
    //cerr << n << r <<"\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll u = 0;

    for (int i = 0; i < n; i++) {
        while (a[u] - a[i] <= r) {
            u++;
            if (u == n) break;
        }
        //cerr << i << " " << u << "\n";
        if (u == n) break;
        ans += n - u;
    }
    cout << ans;

    return 0;
}
