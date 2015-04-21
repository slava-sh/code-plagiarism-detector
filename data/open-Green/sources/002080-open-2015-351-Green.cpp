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

const int max_n = 1111111, max_k = 11, inf = 1011111111;

int n, k, dp[max_n][max_k];
vector<int> v;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        v.clear();
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                v.push_back(j);
                v.push_back(i / j);
            }
        }
        dp[i][1] = (i + 1) / 2;
        for (int j = 2; j <= k; ++j) {
            dp[i][j] = inf;
            for (int q = 0; q < v.size(); ++q) {
                dp[i][j] = min(dp[i][j], (v[q] + 1) / 2 * dp[i / v[q]][j - 1]);
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}
