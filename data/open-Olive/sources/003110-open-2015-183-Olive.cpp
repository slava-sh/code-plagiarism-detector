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

const int maxn = 1001001;
const int INF = 2E9;

int n, a[maxn];

void solve()
{
    cin >> n;
    for ( int i = 0; i < n; i++ )
        cin >> a[i];

    pair < int , int > ans = make_pair( -1, -1 );
    int better = 0;
    for ( int i = 0; i < n; i++ )
        for ( int j = i + 1; j < n; j++ )
        {
            if ( a[i] < a[j] )
                continue;
            int cnt = 1;
            for ( int c = i + 1; c < j; c++ )
                if ( a[i] > a[c] && a[c] > a[j] )
                    cnt += 2;

            if ( cnt > better )
                better = cnt, ans = make_pair( i + 1, j + 1 );
        }

    cout << ans.first << ' ' << ans.second << '\n';
}

int main()
{
//    freopen( "input.txt", "r", stdin );
    ios_base::sync_with_stdio( 0 );
    srand( time( NULL ) );
    solve();
    return 0;
}
