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
#include <limits>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef vector <int> vi;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define forn(i, a, b) for(int i = (a); i < (b); ++i)
#define ford(i, a, b) for(int i = (a); i >= (b); --i)
#define fore(i, a, b) forn(i, a, b + 1)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define fill(a, v) memset(a, v, sizeof(a))
#define sz(a) ((int)a.size())

#define gl(x) cin >> x
#define gi(x) scanf("%d", &x)
#define pls(x) cout << x << " "
#define pln(x) cout << x << "\n"
#define pis(x) printf("%d ", x)
#define pin(x) printf("%d\n", x)
#define pnl printf("\n")
#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << x << " "
#define dbs(x) cerr << x << " "

#define foreach(c, it) for(__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)

int mod;

const int maxN = 505;

map < pair <pii, int>, int> memo;

inline int choose2(int n) {
    return ((ll)n * (n - 1) / 2) % mod;
}

inline int mul(int a, int b) {
    return (ll)a * b % mod;
}

int go(int numOnes, int numTwos, int rem) {
    if(rem == 0) {
        return 1;
    }
    pair <pii, int> p = mp(mp(numOnes, numTwos), rem);
    if(memo.count(p)) return memo[p];
    int & ret = memo[p] = 0;
    if(numOnes >= 2) {
        ret += mul(choose2(numOnes), go(numOnes - 2, numTwos, rem - 1));
        if(ret >= mod) ret -= mod;
    }
    if(numTwos >= 2) {
        ret += mul(choose2(numTwos), go(numOnes + 2, numTwos - 2, rem - 1));
        if(ret >= mod) ret -= mod;
    }
    if(numOnes >= 1 and numTwos >= 1) {
        ret += mul(mul(numOnes, numTwos), go(numOnes, numTwos - 1, rem - 1));
        if(ret >= mod) ret -= mod;
    }


    return ret; 
}

int main() {
    int n, m;
    gi(n), gi(m), gi(mod);
    vi colReq(n, 2);
    rep(i, m) {
        string str;
        cin >> str;
        rep(j, n) {
            colReq[j] -= (str[j] - '0');
        }
    }

    int numOnes = 0, numTwos = 0;
    rep(i, n) {
        numOnes += colReq[i] == 1;
        numTwos += colReq[i] == 2;
    }
    pin(go(numOnes, numTwos, n - m));
    return 0;
}