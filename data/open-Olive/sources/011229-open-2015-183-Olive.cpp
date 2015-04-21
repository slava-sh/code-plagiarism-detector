#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

const int maxn = 15001;
const int INF = 2E9;

int n, a[maxn];
short cnt[maxn][maxn];

void solve()
{
    scanf( "%d", &n );
    for ( int i = 0; i < n; i++ )
        scanf( "%d", &a[i] );

    for ( int i = 0; i < n; i++ )
    {
        cnt[i][0] = a[0] > a[i] ? 1 : 0;
        for ( int j = 1; j < n; j++ )
            {
                cnt[i][j] = cnt[i][j - 1];
                if ( a[i] < a[j] )
                    cnt[i][j]++;
            }
    }

    long long better = 0;
    pair < int , int > ans = make_pair( -1, -1 );
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < i; j++ )
        {
            if ( a[j] < a[i] )
                continue;

            int x = cnt[i][i] - 1 - cnt[j][i];
            x = 2 * x + 1;
            if ( x > better )
                better = x, ans = make_pair( i + 1, j + 1 );
        }

    printf( "%d %d\n", ans.first, ans.second );
}

int main()
{
//    freopen( "input.txt", "r", stdin );
    ios_base::sync_with_stdio( 0 );
    srand( time( NULL ) );
    solve();
    return 0;
}
