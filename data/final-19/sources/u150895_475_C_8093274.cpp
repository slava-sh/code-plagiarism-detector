#include <bits/stdc++.h>

using namespace std;

#define sum( a1, b1, a2, b2 ) ( q[a2][b2] - q[a1 - 1][b2] - q[a2][b1 - 1] + q[a1 - 1][b1 - 1] )

int n,m;
char r[1111][1111];
int q[1111][1111];
int res=1000000000;
 
int dfs( int a, int b, int da, int db ) {
    if( sum( a, (b + 1), (a + da - 1), (b + db) ) == da*db )
        return da + dfs( a, (b + 1), da, db );
    if( sum( (a + 1), b, (a + da), (b + db - 1) ) == da*db )
        return db + dfs( (a + 1), b, da, db );
    return 0;
}
 
int main() {
    scanf( "%d%d\n", &n, &m );
    int flag = 0, pa, pb;
    for( int i = 1; i <= n; i++ )
        gets( r[i] + 1 );
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ ) {
            if( r[i][j] == 'X' ) {
                if( !flag ) {
                    flag = 1;
                    pa = i;
                    pb = j;
                }
            q[i][j] = q[i - 1][j] + q[i][j - 1] - q[i - 1][j - 1] + 1;
            } else 
            q[i][j] = q[i - 1][j] + q[i][j - 1] - q[i - 1][j - 1];
    }
    
    int tmp, da, db;
    for( tmp = pa; r[tmp][pb] == 'X'; tmp++ );
        da = tmp - pa;
    for( int i = pb; r[pa][i] == 'X'; i++ )
        if( dfs( pa, pb, da, (i - pb + 1) ) + da*(i - pb + 1) == q[n][m] )
            res = min( res, da*(i - pb + 1) );
    for( tmp = pb; r[pa][tmp] == 'X'; tmp++ );
        db = tmp - pb;

    for( int i = pa; r[i][pb] == 'X'; i++ )
        if( dfs( pa, pb, (i - pa + 1), db ) + (i - pa + 1)*db == q[n][m] )
            res = min( res,(i - pa + 1)*db );

    if( res <= n*m )
        cout << res << endl;
    else 
        cout << -1 << endl;

    return 0;
}