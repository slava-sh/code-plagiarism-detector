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
int stack[maxn], top = 0;
clock_t tt;

void solve()
{
    tt = clock();
    scanf( "%d", &n );
    for ( int i = 0; i < n; i++ )
        scanf( "%d", &a[i] );

    pair < int , int > ans = make_pair( -1, -1 );
    int better = 0;
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < top; j++ )
            if ( a[i] > a[ stack[j] ] )
                continue;
            else
            {
                int cnt = 1;
                for ( int c = stack[j] + 1; c < i; c++ )
                    if ( a[ stack[j] ] > a[c] && a[c] > a[i] )
                        cnt += 2;

                if ( cnt > better )
                    better = cnt, ans = make_pair( stack[j] + 1, i + 1 );
            }

        if ( top == 0 || a[ stack[top - 1] ] < a[i] )
            stack[top++] = i;

        if ( clock() - tt > 1950 )
            break;
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
