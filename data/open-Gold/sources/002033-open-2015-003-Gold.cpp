#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;
const int maxn = 200100;

ll d[maxn], d2[maxn], a[maxn], b[maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k, c, D;
    cin >> n >> k >> c >> D;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    for (int i = 0; i < k; ++i) {
        d[i] = INF;
    }
    d[0] = D * (b[0] - a[0]);
    for (int i = 1; i < n; ++i) {
        d2[0] = min(d[k - 1] + c + D * (b[i] - a[i]), d[0] + D * (b[i] - b[i - 1]));
        for (int j = 1; j < k; ++j) {
            d2[j] = min(d[j - 1] + D * (b[i] - a[i]), d[j] + D * (b[i] - b[i - 1]));
        }
        for (int j = 0; j < k; ++j) {
            d[j] = d2[j];
        }
    }
    ll ans = INF;
    for (int i = 0; i < k; ++i) ans = min(ans, d[i]);
    cout << ans << endl;

    return 0;
}

