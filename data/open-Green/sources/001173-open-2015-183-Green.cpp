#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

const int maxn = 100100;

long long rec( long long n, int k )
{
    if ( k == 1 )
        return ( n + 1 ) / 2;

    long long x = sqrt( n + 0.1 );
    long long ans = ( n + 1 ) / 2;

    for ( long long i = 2; i <= x; i++ )
        if ( n % i == 0 )
            ans = min( ans, ( i + 1 ) / 2ll * rec( n / i , k - 1 ) );

    return ans;
}

long long n, k;

void solve()
{
    cin >> n >> k;
    cout << rec( n, k ) << '\n';
}

int main()
{
//    freopen( "input.txt", "r", stdin );
    ios_base::sync_with_stdio( 0 );
    srand( time( NULL ) );
    solve();
    return 0;
}
