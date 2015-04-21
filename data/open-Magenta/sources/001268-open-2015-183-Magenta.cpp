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

void solve()
{
    while( 1 )
    {
        if ( rand() % 3 == 0 )
            cout << "R\n";
        else
            cout << "U\n";

        char c;
        cin >> c;
        if ( c != 'N' )
            return;
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

