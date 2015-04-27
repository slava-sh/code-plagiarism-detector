#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#define F cin
#define G cout

const int N = 510;
int M = 0;

int n,m,dp[N][N],a[N];
string ss;

int main()
{
    ios::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        ifstream F("p.in");
    #endif

    F>>n>>m>>M;
    for (int i=1;i<=n;++i)
        a[i] = 2;
    for (int i=1;i<=m;++i)
    {
        F>>ss;
        int co = 0;
        for (int j=0;j<int(ss.size());++j)
            if ( ss[j] == '1' )
            {
                a[j+1]--;
                ++co;
                if ( a[j+1] < 0 )
                {
                    G<<"0\n";
                    return 0;
                }
            }
        if ( co > 2 )
        {
            G<<"0\n";
            return 0;
        }
    }
    m = n-m;
    dp[0][0] = 1;
    int ones = 0;
    for (int i=1;i<=n;++i)
    {
        ones += a[i];
        for (int j=0;j<=m;++j) // linii cu suma 1
        {
            int k = (ones - j) / 2; // linii cu suma 2
            int l = m - j - k; // linii cu suma 0

            if ( k + j > m ) continue;
            if ( k * 2 + j != ones ) continue;

            if ( a[i] == 0 )
                dp[i][j] = dp[i-1][j];
            if ( a[i] == 1 )
            {
                if ( j-1 >= 0 ) dp[i][j] = ( 1LL * dp[i-1][j-1] * (l+1) ) % M; // pun un 1 peste 0 - acum avem cu un 0 mai putin
                dp[i][j] = ( dp[i][j] + 1LL * dp[i-1][j+1] * (j+1) ) % M; // pun un 2 peste 1 - acum avem cu un 1 mai putin
            }
            if ( a[i] == 2 )
            {
                dp[i][j] = (1LL * dp[i-1][j] * (l+1) * j)%M; // 1 , 0
                if ( j-2 >= 0 ) dp[i][j] = ( dp[i][j] + ( 1LL * dp[i-1][j-2] * ( 1LL * (l+2) * (l+1) / 2 ) % M ) %M ) %M; // 0 , 0
                //dp[i][j] = ( dp[i][j]+ 1LL * dp[i-1][j] * (l+1) ) % M; // 0
                dp[i][j] = ( dp[i][j]+ (1LL * dp[i-1][j+2] * ((1LL * (j+2) * (j+1) / 2)%M)) %M ) % M  ; // 1 , 1
            }
        }
    }
    G<<dp[n][0]<<'\n';
}

