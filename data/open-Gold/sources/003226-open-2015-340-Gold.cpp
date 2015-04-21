#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <functional>
#include <cassert>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n,k,c,d;
int a[200105],b[200105];
ll dp[5005][5005]; ///idx/used_bulb

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);

    scanf("%d%d%d%d",&n,&k,&c,&d);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d",&a[i],&b[i]);
    a[0] = b[0] = a[1];
    for (int i = 0; i < 5005; ++i)
        for (int j = 0; j < 5005; ++j)
            dp[i][j] = 1e18;
    dp[0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = min(dp[i][j], dp[i-1][j] + ll(b[i] - b[i-1]) * ll(d));
            if (j == 1) {
                dp[i][j] = min(dp[i][j], dp[i-1][k] + c + ll(b[i] - a[i]) * ll(d));
            } else {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + ll(b[i] - a[i]) * ll(d));
            }
        }
    }
    ll ans = 9e18;
    for (int i = 0; i <= k + 5; ++i) ans = min(ans, dp[n][i]);
    cout << ans;

    return 0;
}
