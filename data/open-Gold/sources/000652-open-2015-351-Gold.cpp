#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 3033;
const long long inf = 1111111111111111111LL;

int n, k, l[max_n], r[max_n];
long long d, c, dp[max_n][max_n];

int main() {
    cin >> n >> k >> c >> d;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
    }
    for (int i = 0; i <= k; ++i) {
        dp[0][i] = inf;
    }
    dp[0][k - 1] = (r[0] - l[0]) * d;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j + 1 < k; ++j) {
            dp[i][j] = min(dp[i - 1][j] + (l[i] - r[i - 1]) * d, dp[i - 1][j + 1]) + (r[i] - l[i]) * d;
        }
        dp[i][k - 1] = min(dp[i - 1][k - 1] + (l[i] - r[i - 1]) * d, dp[i - 1][0] + c) + (r[i] - l[i]) * d;
        /*for (int j = 0; j < k; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;*/
    }
    long long ans = inf;
    for (int i = 0; i < k; ++i) {
        ans = min(ans, dp[n - 1][i]);
    }
    cout << ans << endl;
    return 0;
}
