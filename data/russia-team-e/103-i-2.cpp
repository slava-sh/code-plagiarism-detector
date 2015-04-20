#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, d;
int a[100000];
long long ans;

int main() {
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    cin >> n >> d;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);

    int cur = 0;
    while(cur < n && a[cur] < 3 * d)
        ++cur;

    if (cur > 0 && a[cur - 1] >= 2 * d)
        --cur;
    if (cur > 0 && a[cur - 1] >= 2 * d)
        --cur;

    ans = a[cur];

    for (int i = cur + 1; i < n; ++i)
        ans += a[i] - 2 * d;

    cout << max(ans, (long long)a[n - 1]);

    return 0;
}
