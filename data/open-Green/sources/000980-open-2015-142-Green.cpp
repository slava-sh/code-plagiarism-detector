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
#include <unordered_map>

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

const int MXN = 100;
const int MXK = 11;
const int inf = 1e9;
const ll linf = 1e18;

//int dp [MXN][MXN];

int lowdp [MXN][MXK];

unordered_map< ll , ll> dp [MXK];

ll dfs( ll n, int k ){
    if(n<MXN) return lowdp[n][k];
    if(k==1) return (n+1)/2;
    ll t = dp[k][n];
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

    return dp[k][n] = res;
}

int main()
{
    freopen("input.txt", "r", stdin);    freopen("output.txt", "w", stdout);

   // rep(i,MXN) rep(j,MXN) dp[i][j] = inf;

//    printf("qq$$$$$$$$$$$$$$$44");
/*
    printf("  ");
    forn(i,1,10) printf("%3d", i);
    printf("\n");
*/
    forn(i,1,MXN){
//        printf("%2d", i);
        forn(j,1,MXK){
            lowdp[i][j] = inf;
            if(j==1){
                lowdp[i][j] = (i+1)/2;
                continue;
            }
            bool fnd = false;
            for( int d = 2; d*d <= i; d++ ){
                if(i%d) continue;
                fnd = true;
                int q = i/d;
                lowdp[i][j] = min(lowdp[i][j], lowdp[d][j-1] * (q+1)/2 );
                lowdp[i][j] = min(lowdp[i][j], lowdp[q][j-1] * (d+1)/2 );
            }

            if(!fnd) lowdp[i][j] = (i+1)/2;

        }
        //printf("\n");
    }

    //printf("\n");
    ll n;
    int k;
    cin>>n>>k;
    cout << dfs(n,k);


    return 0;
}
