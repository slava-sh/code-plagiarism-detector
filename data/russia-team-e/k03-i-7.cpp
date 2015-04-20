#include <bits/stdc++.h>

#define ll long long
#define fn "sochi"

using namespace std;

const int MXN = 1e6 + 9;
const int INF = 1e9 + 9;

int sum,  ans, n , d;
int a[MXN], u[MXN], t[MXN];

int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);

    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        u[a[i]]++;
        ans = max(ans, a[i]);
        if (a[i] >= 3 * d) {
            sum += a[i] - d  - d;
        }
    }
    for (int i = d; i <= 1000; i++) {
        if (u[i] == 0) {
            continue;
        }
        for (int j = i; j <= 1000; j++) {
            if (u[j] == 0 || (i == j && u[i] < 2)) {
                continue;
            }
            ans = max(i - d + j - d, ans);

            int tmp = i - d + j - d + sum;
            if (i >= 3 * d) {
                tmp -= i - d - d;
            }
            if (j >= 3 * d) {
                tmp -= j - d - d;
            }
            ans = max(tmp, ans);
        }
    }
    cout << ans;
    return 0;
}
