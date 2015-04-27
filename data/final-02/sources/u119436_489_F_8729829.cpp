#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <sstream>
using namespace std;

#define DB(x) cerr<<#x<<"="<<x<<" "
#define DBN(x) cerr<<#x<<"="<<x<<"\n"
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define sqr(x) ((x)*(x))
#define sz(x) ((int)(x).size())
#define clr(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define mp make_pair

#define lson x+x,l,y
#define rson x+x+1,y+1,r

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<long long, long long> PLL;

#define INF 1000000000
#define EPS (double)1e-9
#define MOD 1000000007
#define PI 3.14159265358979328462
int dp[555][555];
int n, m, mod;
int cnt[555];

int dfs(int c2, int c1, int sh) {
    if (dp[c2][c1] != -1) return dp[c2][c1];
    // if (!(sh >= (c2+1))) return 0;
    int res = 0;
    // c2,c2
    if (c2 >= 2) {
        res += (1LL*(1LL*c2*(c2-1)/2)%mod* dfs(c2-2, c1+2, sh-1)) % mod;
        res %= mod;
    }
    // c2,c1
    if (c1 >= 1 && c2 >= 1) {
        res += (1LL*(1LL*c2*c1)%mod * dfs(c2-1, c1, sh-1)) % mod;
        res %= mod;
    }
    // c1,c1
    if (c1 >= 2) {
        res += (1LL*(1LL*c1*(c1-1)/2)%mod * dfs(c2, c1-2, sh-1)) % mod;
        res %= mod;
    }
    // DB(c2);DB(c1);DB(sh);DBN(res);
    dp[c2][c1] = res;
    return res;
}

int main(int argc, char *argv[])
{
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    cin >> n >> m >> mod;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        for (int i = 0; i < sz(s); i++)
            if (s[i] == '1') cnt[i]++;
    }
    
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
        if (cnt[i] == 0) c2++;
        else if (cnt[i] == 1) c1++;

    cout << dfs(c2, c1, n-m) << endl;
    
    return 0;
}

