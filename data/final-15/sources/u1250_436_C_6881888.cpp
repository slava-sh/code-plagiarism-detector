//Coder: Balajiganapathi
//#define TRACE
#define DEBUG

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

// Basic macros
#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fr(i,n)     re(i,0,n)
#define repv(i,f,t) for(int i = f; i >= t; --i)
#define rev(i,f,t)  repv(i,f - 1,t)
#define frv(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

const int oo = 2000000009;
const double eps = 1e-9;

#ifdef TRACE
    #define trace1(x)                cerr << #x << ": " << x << endl;
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

    #define trace1(x)
    #define trace2(x, y)
    #define trace3(x, y, z)
    #define trace4(a, b, c, d)
    #define trace5(a, b, c, d, e)
    #define trace6(a, b, c, d, e, f)

#endif

int n, m, k, w;

const int mxk = 1003, mx = 11;
char g[mxk][mx][mx];

list<int> adj[mxk];
int tot, vis[mxk], b[mxk];
int cost[mxk][mxk];
vector<pi> ans;

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &w);
    fr(i, k) fr(j, n) scanf("%s", g[i][j]);

    fr(i, k) {
        fr(j, k) if(i != j) {
            int diff = 0;
            fr(ii, n) fr(jj, m) diff += (g[i][ii][jj] != g[j][ii][jj]);
            diff *= w;
            cost[i + 1][j + 1] = diff;
        }
        cost[i][0] = cost[0][i] = n * m;
    }

    tot = 0;

    priority_queue<pi> pq;
    fr(i, k) pq.push(mp(-n * m, i + 1));
    fr(i, k) b[i + 1] = 0;
    while(!pq.empty()) {
        pi cur = pq.top(); pq.pop();
        if(vis[cur.se]) continue;
        vis[cur.se] = 1;
        tot += -cur.st;
        ans.pu(mp(cur.se, b[cur.se]));
        rep(i, 1, k) if(!vis[i] && cost[cur.se][i] < cost[b[i]][i]) {
            b[i] = cur.se;
            pq.push(mp(-cost[cur.se][i], i));
        }
    }


    printf("%d\n", tot);
    fr(i, sz(ans)) printf("%d %d\n", ans[i].st, ans[i].se);

	return 0;
}
