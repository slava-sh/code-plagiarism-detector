#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define forn(i,a,b) for( int i = (a); i < (b); i++ )
#define repe(i,n) for( i = 0; i < (n); i++ )
#define rep(i,n) forn(i,0,n)

const int MXN = 110;
const int inf = 1e9;
const ll linf = 1e18;

//int dp [MXN][MXN];

map< pair<ll,int> , ll> dp;

ll dfs( ll n, int k ){
    if(k==1) return (n+1)/2;
    ll t = dp[mp(n,k)];
    if(t) return t;
    bool fnd = false;
    ll res = linf;
    for( ll i = 2; i*i <= n; i++ ){
        if(n%i) continue;
        fnd = true;
        ll q = n/i;
        res = min(res, dfs(i,k-1) * (q+1)/2 );
        res = min(res, dfs(q,k-1) * (i+1)/2 );
    }

    if(!fnd) return (n+1)/2;

    return dp[mp(n,k)] = res;
}

int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("qq.out", "w", stdout);

   // rep(i,MXN) rep(j,MXN) dp[i][j] = inf;

//    printf("qq$$$$$$$$$$$$$$$44");
/*
    printf("  ");
    forn(i,1,10) printf("%3d", i);
    printf("\n");

    forn(i,1,100){
        printf("%2d", i);
        forn(j,1,11){
            if(j==1){
                dp[i][j] = (i+1)/2;
            }
            else{
                forn(d,1,i+1){
                    if(i%d) continue;
                    dp[i][j] = min(dp[i][j], dp[d][j-1]*((i/d+1)/2) );
                }

            }
            printf("%3d", dp[i][j]);
        }
        printf("\n");
    }
*/
    printf("\n");
    ll n;
    int k;
    cin>>n>>k;
    cout << dfs(n,k);


    return 0;
}
