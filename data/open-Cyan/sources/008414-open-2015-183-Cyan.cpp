#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

const int maxn = 200200;

struct Point
{
    int x, y;
    Point( int x = 0, int y = 0 ) : x(x), y(y) {};
};

struct Segment
{
    Point s, f;
    Segment( Point s, Point f ) : s(s), f(f) {};
};

long long square( Point a, Point b, Point c )
{
    a.x -= c.x;
    a.y -= c.y;
    b.x -= c.x;
    b.y -= c.y;
    return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

struct Polyline
{
    vector < Point > pt;
};

//bool intersect( Segment s1, Segment s2 )
//{
//    Point a, b, c, d;
//    a = s1.s;
//    b = s1.f;
//    c = s2.s;
//    d = s2.f;
//
//    if ( square( a, b, c ) == 0 || square( a, b, d ) == 0 || square( a, c, d ) == 0 || square( b, c, d ) == 0 )
//        return 0;
//
//    bool x = square( a, b, c ) > 0;
//    bool y = square( a, b, d ) > 0;
//    if ( ( x ^ y ) == 0 )
//        return 0;
//    x = square( c, d, a ) > 0;
//    y = square( c, d, b ) > 0;
//    if ( ( x ^ y ) == 0 )
//        return 0;
//
//    return 1;
//}

int n;
vector < Polyline > pll;

bool p_intersect( int a, int b )
{
    int p1 = 1;
    int up = 0;
    for ( int i = 0; i < pll[a].pt.size(); i++ )
    {
        while( pll[b].pt[p1].x < pll[a].pt[i].x )
            p1++;
        long long x = square( pll[b].pt[p1 - 1], pll[b].pt[p1], pll[a].pt[i] );
        if ( x == 0 )
            continue;
        if ( x < 0 )
            x = -1;
        else
            x = 1;
        if ( up == 0 )
            up = x;
        else
            if ( up != x )
                return 1;
    }
    return 0;
}

bool comp( int a, int b )
{
    if ( pll[a].pt[0].y != pll[b].pt[0].y )
        return pll[a].pt[0].y < pll[b].pt[0].y;
    if ( pll[a].pt.back().y != pll[b].pt.back().y )
        return pll[a].pt.back().y < pll[b].pt.back().y;

    for ( int i = 0; i < 10; i++ )
    {
        int x = rand() % min( pll[a].pt.size(), pll[b].pt.size() );
        if ( pll[a].pt[x].y != pll[b].pt[x].y )
            return pll[a].pt[x].y < pll[b].pt[x].y;
    }
    return rand() % 2;
}

void solve()
{
    int ptr = 0;
    int a_, b_;   cin >> a_ >> b_;
    cin >> n;
    pll.resize( n );
    for ( int i = 0; i < n; i++ )
    {
        int l;
        cin >> l;
        l++;
        while( l-- )
        {
            int x, y;
            cin >> x >> y;
            pll[i].pt.push_back( Point( x, y ) );
        }
    }

    vector < int > order( n );
    for ( int i = 0; i < n; i++ )
        order[i] = i;
    sort( order.begin(), order.end(), comp );

    for ( int i = 0; i < n - 1; i++ )
        if ( p_intersect( order[i], order[i + 1] ) || p_intersect( order[i + 1], order[i] ) )
        {
            cout << "No\n";
            cout << order[i] + 1 << ' ' << order[i + 1] + 1 << '\n';
            return;
        }

    cout << "Yes\n";
}

int main()
{
//    freopen( "input.txt", "r", stdin );
    ios_base::sync_with_stdio( 0 );
    srand( time( NULL ) );
    solve();
    return 0;
}
