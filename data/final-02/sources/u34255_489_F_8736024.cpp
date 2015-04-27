#include <iostream>
#include <functional>
#include <algorithm>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstdio>
#include <complex>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;
#define int64 long long
#define mp make_pair

#ifdef _DEBUG
    const int N = 1010;
#else
    const int N = 1010;
#endif

int64 n, m, mod, a[N][N];
int64 dp[N][N];

int64 solve(int i, int j)
{
    if (dp[i][j] != -1) return dp[i][j];
    if (i == 0)
    {
        if (j == 0) dp[i][j] = 1;
        else dp[i][j] = 0;
        return dp[i][j];
    }
    if (j < 2)
    {
        dp[i][j] = 0;
        return dp[i][j];
    }
    int k = 2 * (j - i);
    if (k < 0)
    {
        dp[i][j] = 0;
        return dp[i][j];
    }
    if (k == 0)
    {
        dp[i][j] = ((1ll * j * (j - 1) / 2) * solve(i - 1, j)) % mod;
    }
    else if (k == 1)
    {
        if (j - k >= 2) dp[i][j] = ((1ll * (j - 1) * (j - 2) / 2) * solve(i - 1, j)) % mod;
        dp[i][j] = (dp[i][j] + 1ll * (j - 1) * solve(i - 1, j - 1)) % mod;
    }
    else 
    {
        dp[i][j] = 0;
        if (j - k >= 2) dp[i][j] = ((1ll * (j - k) * (j - k - 1) / 2) * solve(i - 1, j)) % mod;
        if (j - k >= 1) dp[i][j] = (dp[i][j] + (1ll * (j - k) * k) * solve(i - 1, j - 1)) % mod;
        dp[i][j] = (dp[i][j] + (1ll * k * (k - 1) / 2) * solve(i - 1, j - 2)) % mod;
    }
    return dp[i][j];
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m >> mod;
    scanf("\n");
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            scanf("%c", &ch);
            a[i][j] = ch - '0';
        }
        scanf("\n");
    }
    memset(dp, -1, sizeof(dp));
    int n1 = n - m, m1 = n;
    for (int i = 1; i <= m; i++)
    {
        int k = 0;
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 1) k++;
        if (k != 2)
        {
            cout << 0;
            return 0;
        }
    }
    for (int j = 1; j <= n; j++)
    {
        int k = 0;
        for (int i = 1; i <= m; i++)
            if (a[i][j] == 1) k++;
        if (k == 2) m1--;
    }
    cout << solve(n1, m1);
    return 0;
}