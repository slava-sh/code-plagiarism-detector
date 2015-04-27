//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : Codeforces
// Problem Name : 
// Time Limit   : .000s
// Description  : 
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define inpFile(f) freopen(f, "r", stdin)
#define outFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF 500000000
#define maxN 100010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, m, a[maxN];
vii v;
map<int, int> idx;

bool cmp(int a, int b) { return a > b; }

void result(int res) {
    printf("%d\n", res);
    if (!res) return;
    int ans[res][4], x = 0, y = 0, s = 0;
    for (int i = 0; i < v.size(); i++) {
        v[i].ff = min(res, v[i].ff);
        while (v[i].ff--) {
            ans[x++][y] = v[i].ss;
            if (x == res) {
                x = 0;
                y++;
            }
            if (y >= 3) break;
        }
    }
    REP(i, res) {
        sort(ans[i], ans[i] + 3, cmp);
        printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
    }
}

bool accept(int k) {
    if (k == 0) return true;
    int counter = 0, s = 0;
    for (int i = 0; i < v.size() && counter < 3; i++) {
        int val = min(k, v[i].ff);
        if ((val + s) % k <= s) counter++;
        s = (s + val) % k;
    }
    return counter >= 3;
}

void solve() {
    sort(all(v));
    int L = 0, R = n / 3, res = 0;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (accept(mid))
            res = mid, L = mid + 1;
        else
            R = mid - 1;
    }
    result(res);
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    scanf("%d", &n);
    v.clear(); m = 0;
    REP(i, n) {
        scanf("%d", &a[i]);
        int id = idx[a[i]];
        if (id == 0) {
            id = idx[a[i]] = ++m;
            v.pb(ii(0, a[i]));
        }
        v[id - 1].ff++;
    }
  //  REP(i, v.size()) printf("%d %d\n", v[i].ff, v[i].ss); puts("");
    solve();
    return 0;
}

// lamphanviet@gmail.com - 2011

