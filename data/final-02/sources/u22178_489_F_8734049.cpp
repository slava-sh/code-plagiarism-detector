#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <list>

using namespace std;

int mark[512];
long long dp[512][512];

int main()
{
    int t, cas;
    int i, j, k, n, m, mod;

    //scanf("%d", &t);
    while(scanf("%d %d %d", &n, &m, &mod)!=EOF)
    {
        for(j = 0; j < n; j ++)mark[j] = 0;
        for(i = 0; i < m; i ++)
        {
            for(j = 0; j < n; j ++)
            {
                int x;
                scanf("%1d", &x);
                mark[j] += x;
            }
        }
        int x, y;
        x = y = 0;
        for(i = 0; i < n; i ++)
        {
            if(mark[i] == 0)x ++;
            if(mark[i] == 1)y ++;
        }

        memset(dp, 0, sizeof(dp));
        dp[x][y] = 1;
        while(m < n)
        {
            m ++;
            for(i = 0; i <= n; i ++)
            {
                for(j = 0; j <= n; j ++)
                {
                    if(dp[i][j] > 0)
                    {
                        if(i > 1)
                        {
                            dp[i-2][j+2] += dp[i][j] * (i * (i-1) / 2);
                            dp[i-2][j+2] %= mod;
                        }
                        if(j > 1)
                        {
                            dp[i][j-2] += dp[i][j] * (j * (j-1) / 2);
                            dp[i][j-2] %= mod;
                        }
                        if(i > 0 && j > 0)
                        {
                            dp[i-1][j] += dp[i][j] * i * j;
                            dp[i-1][j] %= mod;
                        }
                        dp[i][j] = 0;
                    }
                }
            }
        }
        cout << dp[0][0] << endl;
    }
    return 0;
}
