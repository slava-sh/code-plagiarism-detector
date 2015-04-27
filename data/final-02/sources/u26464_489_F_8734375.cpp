/* Divanshu Garg */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <complex>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) ((a)>(b)?(a):(b))
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Relevant code begins here */

/* Input from file or online */

void input() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}

/* Input opener ends */

int n,m; int mod;
int colsum[505];
int csum[505];
ill dp[505][2];

int main() {
    input();
    cin >> n >> m >> mod;
    F(i,0,505) colsum[i] = 2;
    F(i,0,m) {
        string s;
        cin >> s;
        F(j,0,n) if ( s[j] == '1' ) colsum[j]--;
    }
    csum[0] = colsum[0]; F(i,1,n) csum[i] = csum[i-1]+ colsum[i];

    int now = 0, nxt = 1;
    F(j,0,n+1) dp[j][nxt] = 0;
    dp[0][nxt] = 1;
    FD(col,n-1,0) {
        F(row1,0,n+1) {
                
                int totalRows = n-m;
                int totalUsed = (col?csum[col-1]:0);
                int row0 = (totalUsed - row1)/2;
                int row2 = totalRows - row1-row0;

                ill &res = dp[row1][now];
                res = 0;
                if ( colsum[col] == 0 ) {
                    res = dp[row1][nxt];
                } else if ( colsum[col] == 1 ) {
                    if ( row2 ) res += row2*dp[row1+1][nxt];
                    if ( row1 ) res += row1*dp[row1-1][nxt];
                } else {
                    if ( row1 > 1 ) res += ((row1*(row1-1))/2)*dp[row1-2][nxt];
                    if ( row2 > 1 ) res += ((row2*(row2-1))/2)*dp[row1+2][nxt];
                    if ( row1 && row2 ) res += row1*row2*dp[row1][nxt];
                }
                res %= mod;
            
        }
        swap(now,nxt);
    }
    cout << dp[0][nxt] << endl;
    
    return 0;
}