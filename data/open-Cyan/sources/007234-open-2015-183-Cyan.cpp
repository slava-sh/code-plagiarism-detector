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
    return a.x * b.y - a.y * b.x;
}

struct Polyline
{
    vector < Point > pt;
//    int l, r, m;
//    int upper( Point x )
//    {
//        l = 0, r = pt.size() - 1;
//        while( l < r )
//        {
//            m = ( l + r ) >> 1;
//            if ( pt[m].x <= x.x )
//                l = m + 1;
//            else
//                r = m;
//            long long sq = square( pt[l - 1], pt[l], x );
//            if ( sq == 0 )
//                return 0;
//            if ( sq < 0 )
//                return -1;
//            if ( sq > 0 )
//                return 1;
//        }
//    }
};

bool intersect( Segment s1, Segment s2 )
{
    Point a, b, c, d;
    a = s1.s;
    b = s1.f;
    c = s2.s;
    d = s2.f;

    if ( square( a, b, c ) == 0 || square( a, b, d ) == 0 || square( a, c, d ) == 0 || square( b, c, d ) == 0 )
        return 0;

    bool x = square( a, b, c ) > 0;
    bool y = square( a, b, d ) > 0;
    if ( ( x ^ y ) == 0 )
        return 0;
    x = square( c, d, a ) > 0;
    y = square( c, d, b ) > 0;
    if ( ( x ^ y ) == 0 )
        return 0;

    return 1;
}


int n;
vector < Polyline > pll;
int nm[maxn];

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

    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < n; j++ )
            if ( i != j )
            if ( p_intersect( i, j ) )
            {
                cout << "No\n";
                cout << i + 1 << ' ' << j + 1 << '\n';
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
