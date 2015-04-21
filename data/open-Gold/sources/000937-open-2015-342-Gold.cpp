#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <queue>


#define INF 1000000000000LL


using namespace std;

int n, k;
long long a[200000], b[200000];
long long c, d;
long long dp[3000][3001];

int main() {
    cin >> n >> k >> c >> d;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int a1, b1;
        scanf("%d %d", &a1, &b1);
        a[i] = a1;
        b[i] = b1;
        ans += (b[i] - a[i]) * d;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][k] = c;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (a[i + 1] - b[i]) * d);
            dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j]);
            if (j == 1) {
                dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + c);
            }
        }
    }
    long long sum = INF;
    for (int j = 0; j <= k; j++) {
        sum = min(sum, dp[n - 1][j]);
    }
    cout << ans + sum << endl;
    return 0;
}
