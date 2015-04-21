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

const int maxn = 200100;
const int INF = 1E9;

vector < int > gr[maxn];
vector < pair < int , int > > tmp[maxn];
int n, m, d, q;

struct edge
{
    int a, b, c;
    edge( int a = 0 , int b = 0, int c = 0 ): a(a), b(b), c(c) {};
};

edge ed[maxn];

void bfs( int v , int fin )
{
    queue < int > q;
    vector < int > d( m + 100, INF );
    for ( int i = 0; i < tmp[v].size(); i++ )
        {
            q.push( tmp[v][i].first );
            d[ tmp[v][i].first ] = 0;
        }

    int ans = INF;
    while( !q.empty() )
    {
        int v = q.front();
        q.pop();

        if ( ed[v].a == fin || ed[v].b == fin )
                ans = min( ans , d[v] );

        for ( int i = 0; i < gr[v].size(); i++ )
        {
            int to = gr[v][i];
            if ( d[to] < d[v] + 1 )
                continue;

            d[to] = d[v] + 1;
            q.push( to );

        }
    }

    if ( ans == INF )
        cout << "-1\n";
    else
        cout << ans + 1 << '\n';
}

void solve()
{
    cin >> n >> m >> d;
    for ( int i = 0; i < m; i++ )
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        ed[i] = edge( x, y, z );
        tmp[x].push_back( make_pair( i, z ) );
        tmp[y].push_back( make_pair( i, z ) );
    }

    for ( int i = 0; i < m; i++ )
    {
        int x = ed[i].a;
        int y = ed[i].b;
        for ( int j = 0; j < tmp[x].size(); j++ )
            if ( tmp[x][j].first != i && abs( tmp[x][j].second - ed[i].c ) <= d )
            {
                gr[i].push_back( tmp[x][j].first );
                gr[ tmp[x][j].first ].push_back( i );
            }

        for ( int j = 0; j < tmp[y].size(); j++ )
            if ( tmp[y][j].first != i && abs( tmp[y][j].second - ed[i].c ) <= d )
            {
                gr[i].push_back( tmp[y][j].first );
                gr[ tmp[y][j].first ].push_back( i );
            }
    }

    cin >> q;
    while( q-- )
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        bfs( a, b );
    }
}

int main()
{
//    freopen( "i.txt", "r", stdin );
    ios_base::sync_with_stdio( 0 );
    srand( time( NULL ) );
    solve();
    return 0;
}

