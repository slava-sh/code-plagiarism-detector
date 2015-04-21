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

const int maxn = 100100;
const int INF = 2E9;

int n, q, a[maxn];
map < pair < int , int > , bool > mp;

void add( int l, int r )
{
    pair < int , int > x = make_pair( l, r );
    mp[x] = 1;
}

void process( int p, int cl )
{
    map < pair < int , int > , bool > :: iterator it = mp.upper_bound( make_pair( p, INF ) );
    it--;
    pair < int , int > x = it -> first;
    if ( cl == a[x.first] )
        return;

    int l = x.first, r = x.second;
    a[p] = cl;

    if ( p > l && p < r )
    {
        mp.erase( it );
        add( l, p - 1 );
        add( p, p );
        add( p + 1, r );
        return;
    }
    if ( p == 0 )
    {
        if ( p == r )
        {
            if ( a[p + 1] == cl )
            {
                it++;
                int right = it -> first.second;
                mp.erase( it );
                mp.erase( make_pair( 0 , 0 ) );
                add( 0, right );
            }
            return;
        }

        mp.erase( it );
        add( 0, 0 );
        add( 1, r );
        return;
    }
    if ( p == n - 1 )
    {
        if ( p == l )
        {
            if ( a[p - 1] == cl )
            {
                it--;
                int left = it -> first.first;
                mp.erase( it );
                mp.erase( make_pair( n - 1, n - 1 ) );
                add( left, n - 1 );
            }
            return;
        }

        mp.erase( it );
        add( n - 1, n - 1 );
        add( l, r - 1 );
        return;
    }

    if ( l == r )
    {
        if ( a[p - 1] != cl && a[p + 1] != cl )
            return;
        if ( a[p + 1] == cl && a[p - 1] == cl )
        {
            int left, right;
            it++;
            right = it -> first.second;

            it--, it--;
            left = it -> first.first;
            mp.erase( make_pair( left, l - 1 ) );
            mp.erase( make_pair( l, r ) );
            mp.erase( make_pair( r + 1, right ) );
            add( left, right );
            return;
        }
        if ( a[p - 1] == cl )
        {
            it--;
            int left = it -> first.first;
            mp.erase( it );
            mp.erase( make_pair( p, p ) );
            add( left, p );
            return;
        }
        if ( a[p + 1] == cl )
        {
            it++;
            int right = it -> first.second;
            mp.erase( it );
            mp.erase( make_pair( p, p ) );
            add( p, right );
            return;
        }
    }

    if ( p == l )
    {
        if ( a[p - 1] != cl )
        {
            mp.erase( it );
            add( p, p );
            add( p + 1, r );
            return;
        }

        int left;
        it--;
        left = it -> first.first;
        mp.erase( it );
        mp.erase( make_pair( l, r ) );
        add( left, p );
        add( p + 1, r );
        return;
    }

    if ( p == r )
    {
        if ( a[p + 1] != cl )
        {
            mp.erase( it );
            add( p, p );
            add( l, p - 1 );
            return;
        }

        int right;
        it++;
        right = it -> first.second;
        mp.erase( it );
        mp.erase( make_pair( l, r ) );
        add( l, r - 1 );
        add( p, right );
    }
}

void show()
{
    map < pair < int , int > , bool > :: iterator it;
    for ( it = mp.begin(); it != mp.end(); it++ )
        cout << " ( " << it -> first.first << " , " << it -> first.second << " );";
    cout << '\n';
}

void solve()
{
    cin >> n;
    for ( int i = 0; i < n; i++ )
        cin >> a[i];

    cin >> q;
    if ( n == 1 )
    {
        for ( int i = 0; i < q; i++ )
            cout << "1\n";
        return;
    }

    a[n] = INF;
    int last = 0;
    for ( int i = 1; i <= n; i++ )
        if ( a[i] != a[i - 1] )
        {
            add( last, i - 1 );
            last = i;
        }
//    show();

    while( q-- )
    {
        int x, y;
        cin >> x >> y;
        x--;
        process( x, y );
        cout << mp.size() << '\n';
//        show();
    }
}

int main()
{
//    freopen( "input.txt", "r", stdin );
    ios_base::sync_with_stdio( 0 );
    srand( time( NULL ) );
    solve();
    return 0;
}
