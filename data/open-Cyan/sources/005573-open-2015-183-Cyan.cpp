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
vector < Segment > a;
int nm[maxn];

void solve()
{
    int ptr = 0;
    int a_, b_;
    cin >> a_ >> b_;
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        int l;
        cin >> l;
        int x, y;
        cin >> x >> y;
        Point last = Point( x, y );
        while( l-- )
        {
            cin >> x >> y;
            a.push_back( Segment( last, Point ( x, y ) ) );
            nm[ptr++] = i + 1;
            last = Point( x, y );
        }
    }

    for ( int i = 0; i < a.size(); i++ )
        for ( int j = i + 1; j < a.size(); j++ )
            if ( intersect( a[i], a[j] ) )
            {
                cout << "No\n";
                cout << nm[i] << ' ' << nm[j] << '\n';
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
