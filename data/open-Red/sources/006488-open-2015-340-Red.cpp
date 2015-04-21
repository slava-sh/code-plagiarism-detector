#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <functional>
#include <cassert>
#include <sstream>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct edge {
    int to, d, idx;
} ed;

int n,m,d,x,y,z,Q,ans;
vector< edge > g[200105];
queue< pair< pair<int,int>, pair<int,int> > > q;
int dp[200105];

void bfs(int v) {
    for (int i = 0; i < m+m+5; ++i) dp[i] = 2e9;
    q.push(make_pair(make_pair(0, x), make_pair(-(int)2e9, 2*m)));
    while (!q.empty()) {
        int curp = q.front().first.first;
        int curv = q.front().first.second;
        int curtemp = q.front().second.first;
        int prevedge = q.front().second.second;
        q.pop();
        if (dp[prevedge] <= curp) continue;
        dp[prevedge] = curp;
        if (curv == y) {
            ans = min(ans, curp);
            continue;
        }
        ++curp;
        for (int i = 0; i < g[curv].size(); ++i) {
            if (curtemp == -(int)2e9)
                q.push(make_pair(make_pair(curp, g[curv][i].to), make_pair(g[curv][i].d, g[curv][i].idx)));
            else if (abs(g[curv][i].d - curtemp) <= d)
                q.push(make_pair(make_pair(curp, g[curv][i].to), make_pair(g[curv][i].d, g[curv][i].idx)));
        }
    }
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);

    scanf("%d%d%d",&n,&m,&d);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d",&x,&y,&z);
        --x; --y;
        ed.idx = i*2;
        ed.to = y;
        ed.d = z;
        g[x].push_back(ed);
        ed.idx = i*2+1;
        ed.to = x;
        g[y].push_back(ed);
    }

    scanf("%d",&Q);
    while (Q--) {
        scanf("%d%d",&x,&y);
        --x; --y;
        ans = 2e9;
        bfs(x);
        if (ans >= 2e9) printf("-1\n");
        else printf("%d\n",ans);
    }

    return 0;
}
