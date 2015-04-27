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

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl

#define SORT(c) sort(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())

#define oo (1<<30)

typedef long long ll;

string M[510];
int C[3];
int n, m; 
ll mod;
ll dp[510][510];

ll go(int a, int b) {
    ll &res = dp[a][b];
    if (res != -1) return res;

    if (a == 0 && b == 0) return res = 1;

    res = 0;
    if (a >= 2) {
        res += (((ll(a)*ll(a-1)/2)%mod)*(go(a-2, b+2)))%mod;
        res %= mod;
    }
    if (b >= 2) {
        res += (((ll(b)*ll(b-1)/2)%mod)*(go(a, b-2)))%mod;
        res %= mod;
    }
    if (a >= 1 && b >= 1) {
        res += (((ll(a)*ll(b))%mod)*(go(a-1, b)))%mod;
        res %= mod;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> mod;

    REP(i, m) {
        cin >> M[i];
    }

    CLR(C, 0);

    REP(i, n) {
        int cnt = 0;
        REP(j, m) {
            cnt += M[j][i]-'0';
        }
        C[cnt]++;
    }

    CLR(dp, -1);
    ll res = go(C[0], C[1]);

    cout << res << "\n";

    return 0;
}



