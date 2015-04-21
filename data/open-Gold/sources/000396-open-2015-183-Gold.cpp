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

const int maxn = 200200;
const long long INF = 1E9;

int n, c, k, d, delta[maxn];
pair < int , int > a[maxn];

void solve()
{
    cin >> n >> k >> c >> d;
    for ( int i = 0; i < n; i++ )
        cin >> a[i].first >> a[i].second;

    for ( int i = 1; i < n; i++ )
        delta[i - 1] = a[i].first - a[i - 1].second;

    long long ans = 0;
    for ( int i = 0; i < n; i++ )
        ans += a[i].second - a[i].first;
    ans *= 1ll * d;

    if ( n == 1 )
    {
        cout << ans << '\n';
        return;
    }

    sort( delta, delta + n - 1 );
    long long add = 1ll * INF * INF;

    long long pref = 0;
    for ( int i = 0; i < n; i++ )
    {
        long long nw = 1ll * ( n - i - 1 ) / k * c + pref * d;
        add = min( add, nw );
        pref += ( i == n - 1 ) ? 0 : delta[i];
    }

    cout << ans + add << '\n';
}

int main()
{
//    freopen( "input.txt", "r", stdin );
    ios_base::sync_with_stdio( 0 );
    srand( time( NULL ) );
    solve();
    return 0;
}
