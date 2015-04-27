#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

const double PI = acos(-1.0);
const double EPS = 1e-9;
const int INF = 2123123123;
const int MOD = 1e9+7;

typedef long long ll;
typedef pair<int,int> pii;

#define ALL(c) (c).begin(), (c).end()
#define SZ(a) (int)(a).size()
#define RESET(a,x) memset(a,x,sizeof(a))
#define FORIT(it,v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

struct DS {
    int par[1005];
    int rank[1005];
    void init() {
        for (int i = 0; i < 1005; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x) {
        return (x == par[x]) ? x : par[x] = find(par[x]);
    }
    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (rank[px] > rank[py]) par[py] = px;
        else par[px] = py;
        if (rank[px] == rank[py]) ++rank[py];
    }
} d;

int n,m,k,w;
char s[15];
int field[1005][15][15];
int cost[1005][1005], type[1005][1005];
int vis[1005];
priority_queue<pair<int,pair<int,int> > > pq;
int ans;
vector<pair<int,int> > pr;
vector<int> edge[1005];

void DFS(int v, int t) {
    if (vis[v]) return;
    vis[v] = 1;
    //printf("%d %d\n", v+1, t);
    printf("%d %d\n", v+1, t+1);
    for (int i = 0; i < SZ(edge[v]); i++) {
        DFS(edge[v][i], type[v][edge[v][i]]);
    }
    return;
}

int main() {
    scanf("%d%d%d%d", &n,&m,&k,&w);
    int trans = n*m;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++) {
            scanf("%s",s);
            for (int l = 0; l < m; l++) {
                field[i][j][l] = s[l];
            }
        }
    
    for (int i = 0; i < k; i++) {
        for (int j = i+1; j < k; j++) {
            int tmp = 0;
            for (int ii = 0; ii < n; ii++)
                for (int jj = 0; jj < m; jj++)
                    if (field[i][ii][jj] != field[j][ii][jj]) ++tmp;
            cost[i][j] = cost[j][i] = min(w*tmp,trans);
            if (cost[i][j] == trans) type[i][j] = type[j][i] = -1;
            else type[i][j] = i, type[j][i] = j;
            pq.push(MP(-cost[i][j],MP(i,j)));
        }
    }
    d.init();
    while (!pq.empty()) {
        pair<int,pair<int,int> > pp = pq.top();
        //printf("%d %d %d\n", pp.S.F, pp.S.S, pp.F);
        pq.pop();
        int x = pp.S.F, y = pp.S.S;
        //printf("%d %d\n", d.find(x), d.find(y));
        if (d.find(x) != d.find(y)) {
            ans += -pp.F;
            //printf("%d %d %d\n", x, y, type[x][y]);
            d.merge(x,y);
            edge[x].PB(y);
            edge[y].PB(x);
        }
    }
    printf("%d\n", ans+n*m);
    DFS(0,-1);
    return 0;
}
