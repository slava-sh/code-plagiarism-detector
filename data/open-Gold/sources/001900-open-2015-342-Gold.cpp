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
long long dp[3000][3001][2];

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
        for (int j = 0; j <= k; j++) {
            for (int g = 0; g < 2; g++) {
                dp[i][j][g] = INF;
            }
        }
    }
    dp[0][k][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int g = 0; g < 2; g++) {
                //   cout << dp[i][j][g] << endl;
                if (g == 0) {
                    dp[i][k - 1][g + 1] = min(dp[i][k - 1][g + 1], dp[i][j][g] + c);
                    if (j > 0) {
                        dp[i][j - 1][1] = min(dp[i][j - 1][1], dp[i][j][g]);
                    }
                    continue;
                }
                if (i < n - 1) {
                    dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][g]);
                    if (j >= 1) {
                      //  if (j >= 1) {
                            dp[i + 1][j - 1][1] = min(dp[i + 1][j - 1][1], dp[i][j][g]);
                        //}
                    }
                    dp[i + 1][k - 1][1] = min(dp[i + 1][k - 1][1], dp[i][j][g] + c);
                    dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][g] + (a[i + 1] - b[i]) * d);
                }
            }
        }
        for (int j = 0; j <= k; j++) {
            for (int g = 0; g < 2; g++) {
                //   cout << dp[i][j][g] << endl;
                if (g == 0) {
                    dp[i][k - 1][g + 1] = min(dp[i][k - 1][g + 1], dp[i][j][g] + c);
                    if (j > 0) {
                        dp[i][j - 1][1] = min(dp[i][j - 1][1], dp[i][j][g]);
                    }
                    continue;
                }
                if (i < n - 1) {
                    dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][g]);
                    if (j >= 1) {
                      //  if (j >= 1) {
                            dp[i + 1][j - 1][1] = min(dp[i + 1][j - 1][1], dp[i][j][g]);
                        //}
                    }
                    dp[i + 1][k - 1][1] = min(dp[i + 1][k - 1][1], dp[i][j][g] + c);
                    dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][g] + (a[i + 1] - b[i]) * d);
                }
            }
        }
    }
  //  cout << dp[2][0][1] << endl;
    long long sum = INF;
    for (int j = 0; j <= k; j++) {
        sum = min(sum, dp[n - 1][j][1]);
     //cout << dp[n - 1][j][1] << endl;
    }
    cout << ans + sum << endl;
    return 0;
}
