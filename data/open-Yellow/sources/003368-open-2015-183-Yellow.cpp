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

    if ( p != l && p != r )
    {
        mp.erase( it );
        add( l, p - 1 );
        add( p, p );
        add( p + 1, r );
        return;
    }
    if ( p == 0 )
    {
        mp.erase( it );
        add( 0, 0 );
        add( 1, r );
        return;
    }
    if ( p == n - 1 )
    {
        mp.erase( it );
        add( n - 1, n - 1 );
        add( l, r - 1 );
        return;
    }

    if ( l == r )
    {
        int left, right;
        it++;
        right = it -> first.second;

        it--, it--;
        left = it -> first.first;
        mp.erase( make_pair( left, l - 1 ) );
        mp.erase( make_pair( l, r ) );
        mp.erase( make_pair( r + 1, right ) );

        if ( a[p - 1] == cl && a[p + 1] == cl )
            add( left, right );
        else
        {
            if ( a[p - 1] != cl && a[p + 1] != cl )
            {
                add( left, p - 1 );
                add( p, p );
                add( p + 1, right );
            }
            else
                if ( a[p - 1] == cl )
                {
                    add( left, p );
                    add( p + 1, right );
                }
                else
                {
                    add( left, p - 1 );
                    add( p, right );
                }
        }
        return;
    }

    if ( p == l )
    {
        int left;
        it--;
        left = it -> first.first;
        mp.erase( make_pair( left, l - 1 ) );
        mp.erase( make_pair( l, r ) );
        add( l + 1, r );

        if ( a[l - 1] == cl )
            add( left, p );
        else
        {
            add( left, l - 1 );
            add( p, p );
        }
        return;
    }

    if ( p == r )
    {
        int left, right;
        it++;
        right = it -> first.second;
        mp.erase( make_pair( l, r ) );
        mp.erase( make_pair( r + 1, right ) );
        add( l, r - 1 );

        if ( a[r + 1] == cl )
            add( p, right );
        else
        {
            add( p, p );
            add( r + 1, right );
        }
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

    cin >> q;
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
