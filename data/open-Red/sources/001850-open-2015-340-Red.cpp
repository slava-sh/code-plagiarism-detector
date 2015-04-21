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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n,m,d,x,y,z,Q;
vector< pair<int,int> > g[200105];
queue< pair<int, pair<int,int> > > q;
map<int,int> dp[200105];

void bfs(int v) {
    for (int i = 0; i < n; ++i) dp[i].clear();
    q.push(make_pair(0, make_pair(-(int)2e9, v)));
    while (!q.empty()) {
        int curp = q.front().first;
        int curtemp = q.front().second.first;
        int curv = q.front().second.second;
        q.pop();
        if (dp[curv][curtemp] && dp[curv][curtemp] <= curp+1) continue;
        dp[curv][curtemp] = curp+1;
        ++curp;
        for (int i = 0; i < g[curv].size(); ++i) {
            if (curtemp == -(int)2e9) {
                q.push(make_pair(curp, make_pair(g[curv][i].second, g[curv][i].first)));
            } else {
                if (abs(g[curv][i].second - curtemp) <= d)
                    q.push(make_pair(curp, make_pair(g[curv][i].second, g[curv][i].first)));
            }
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
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }

    scanf("%d",&Q);
    while (Q--) {
        scanf("%d%d",&x,&y);
        --x; --y;
        bfs(x);
        if (dp[y].size() == 0) printf("-1\n");
        else {
            int ans = 2e9;
            for (map<int,int>::iterator it = dp[y].begin(); it != dp[y].end(); ++it)
                ans = min(ans, it->second);
            printf("%d\n",ans-1);
        }
    }

    return 0;
}
