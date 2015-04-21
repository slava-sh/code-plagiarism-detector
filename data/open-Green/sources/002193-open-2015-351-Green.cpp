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

int fun(int i, int j) {
    if (j == 1) {
        return (i + 1) / 2;
    }
    if (dp[i][j]) {
        return dp[i][j];
    }
    int res = inf;
    for (int d = 1; d * d <= i; ++d) {
        int x = (d + 1) / 2;
        if (x >= res) {
            dp[i][j] = res;
            return res;
        }
        if (i % d == 0) {
            res = min(res, x * fun(i / d, j - 1));
        }
    }
    dp[i][j] = res;
    //cout << i << " " << j << " - " << res << endl;
    return res;
}

int main() {
    cin >> n >> k;
    cout << fun(n, k) << endl;
    return 0;
}
