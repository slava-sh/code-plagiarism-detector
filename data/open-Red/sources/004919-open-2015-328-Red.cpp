#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

struct hz{
    int v, t, dis;
} q[100500];

vector <vector < pair<int, int> > > g(100500);
int dis[100500];
const int inf = (int)1e8;

int main()
{
//    freopen("input.txt", "r", stdin);
    int n, m, test, d;
    scanf("%d%d%d", &n, &m, &d);
    for(int i = 0; i < m; ++i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    scanf("%d", &test);
    for(int t = 0; t < test; t++){
        int a, b;
        scanf("%d%d", &a, &b);
        int sz = 0, cur = 0;
        for(int i = 1; i <= n; i++)
            dis[i] = inf;
        map < pair<int, int>, char > mp;
        dis[a] = 0;
        q[sz++] = {a, -1, 0};
        while(cur < sz){
            int v = q[cur].v;
            int t = q[cur++].t;
            for(int i = 0; i < g[v].size(); ++i){
                int to = g[v][i].first;
                if(to == a)
                    continue;
                if( (abs(g[v][i].second - t) <= d || v == a) && !mp[make_pair(to, g[v][i].second)]){
                    q[sz++] = {to, g[v][i].second, q[cur-1].dis + 1};
                    mp[make_pair(to, g[v][i].second)] = true;
                    dis[to] = min(dis[to], q[cur-1].dis+1);
                }
            }
        }
        if(dis[b] == inf)
            printf("%d\n", -1);
        else
            printf("%d\n", dis[b]);
    }
    return 0;
}
