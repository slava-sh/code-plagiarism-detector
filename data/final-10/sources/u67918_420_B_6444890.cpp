// In the Name Of God

#include <iostream>
#include <fstream>

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <istream>
#include <queue>
#include <stack>

#define inf (int)(~0u/2)
#define ll_inf (int)1 << 62
//#define int long long
#define float long double
#define eps (1e-8)
#define for2(i, a, b) for ( int (i) = (a); (i)<(b); (i)++ )
#define mp make_pair
#define f1 first
#define f2 second
#define pb push_back
#define pii pair<int,int>
#define vpii vector <pii>
#define vi vector<int>
#define sz(a) (int) a.size( )
#define fillArr(n, a) for2(i, 0, n) cin >> a[i];
#define print(a) cout << #a << endl;
#define umax(a,b) a = max ( a, b )
#define umin(a,b) a = min ( a, b )
#define all(k) k.begin ( ), k.end( )
#define rall(k) k.rbegin ( ), k.rend( )
#define clean(k) memset( k, 0, sizeof(k) )
using namespace std;

const int maxn = 400000+10;
int sum = 0;
int next1[maxn];
int start[maxn];
vector <pair<int, int>> q;
bool is[maxn];
vector <int> ans;
int action[maxn];
int end1[maxn];
vector <int> t[maxn];
vector <int> ns, ne;
bool first[maxn];
bool alive[maxn];
int maxD;
int main ( ){
    ios::sync_with_stdio ( false );
    int n, m;
    cin >> n >> m;
    for2 ( i, 0, maxn ) next1[i] = i;
    int num = 0;
    for2 ( i, 1, m+1 ){
        char c;
        int x;
        cin >> c >> x;
        t[x].pb ( i );
        if ( !action[x] && c == '-' )
            ns.pb ( x ), first[x] = 1, maxD = i, num++;
        if ( c == '+' ) end1[x] = 1, num++;
        else end1[x] = 0, num--;
        action[x] = 1;
        if ( num )
            alive[i] = 1;
    }
    for2 ( i, 1, maxD )
        alive[i] = 1;
    num = count_if ( end1+1, end1+n+1, []( int a ){ return a; } );
    for2 ( i, 1, n+1 ){
        int ind = 0;
        if ( !action[i] ) continue;
        if ( first[i] )
            ind++;
        if ( !first[i] && sz(ns) )
            is[i] = 1;
        if ( !end1[i] && num )
            is[i] = 1;
        for2 ( j, ind, sz(t[i]) ){
            if ( (j == 0 && t[i][j] > 1 ) )
                is[i] = 1;
            else if ( j && t[i][j] - 1 > t[i][j-1] )
                is[i] = 1;
            if ( j && alive[t[i][j-1]] )
                is[i] = 1;
            j ++;
        }
        if ( !end1[i] && t[i].back ( ) < m )
            is[i] = 1;
    }
    for2 ( i, 1, n+1 )
        if ( !is[i] ) ans.pb ( i );
    cout << sz(ans) << "\n";
    for2 ( i, 0, sz(ans) )
        cout << ans[i] << " ";
}
