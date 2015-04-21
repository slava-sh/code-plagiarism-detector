/**
 * EASY.
**/

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <memory.h>
#include <stack>
#include <queue>
#include <deque>
#include <assert.h>


using namespace std;

long long dp[3001][3001];

int main()
{
    const long long INF = 1e+18;
    for(int i = 0; i < 3001; ++i)
        for(int j = 0; j < 3001; ++j)
            dp[i][j] = INF;
    freopen("input.txt", "r", stdin);
    long long n, k, c, d;
    cin >> n >> k >> c >> d;
    dp[0][0] = 0;
    long long last = -1;
    for(int i = 1; i <= n; ++i)
    {
        long long a, b;
        cin >> a >> b;
        long long cost = (b - a) * d;
        long long dist = (a - last) * d;
        if(last == -1)
            dist = 0;
        last = b;
        for(int j = 1; j <= k; ++j)
        {
            dp[i][j] = min(dp[i - 1][j - 1] + cost, dp[i - 1][j] + cost + dist);
            dp[i][j] = min(dp[i][j], INF);
        }
        dp[i][0] = dp[i][k] + c;
        dp[i][0] = min(dp[i][0], INF);
    }
    /*for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= k; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    long long minn = dp[n][0];
    for(int j = 1; j <= k; ++j)
    {
        minn = min(minn, dp[n][j]);
    }
    cout << minn << endl;
    return 0;
}
