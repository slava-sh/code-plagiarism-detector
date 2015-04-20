#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstddef>
#include <queue>

#define INF 1<<30
#define mp make_pair
#define pb push_back

using namespace std;

const int N = 111111;

int n, m;
int a[N];
int f[N];

vector< vector< pair<int, int> > > v;

int aS;
int bS;
int g;
int d[N], prev[N];

int main()
{
    #define TASKNAME "secure"

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        freopen(TASKNAME".in", "r", stdin);
        freopen(TASKNAME".out", "w", stdout);
    #endif // DEUBG

    scanf("%d%d", &n, &m);

    g = n+2;
    aS = n;
    bS = n+1;

    v.resize(g);

    for(int i = 0; i<n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i<n; i++)
    {
        if (a[i] == 1)
        {
            v[aS].pb(mp(i, 0));
            v[i].pb(mp(aS, 0));
        }
        if (a[i] == 2)
        {
            v[bS].pb(mp(i, 0));
            v[i].pb(mp(bS, 0));
        }
    }

    for(int i = 0; i<m; i++)
    {
        int s, t, c;
        scanf("%d%d%d", &s, &t, &c);
        s--;
        t--;
        v[s].pb(mp(t, c));
        v[t].pb(mp(s, c));
    }

    for(int i = 0; i<g; i++)
    {
        d[i] = INF;
        prev[i] = -1;
    }

    d[aS] = 0;

    priority_queue< pair<int, int> > pq;
    pq.push(mp(0, aS));

    while(!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int cur = p.second;

        if (f[cur])
            continue;

        if (d[cur] != p.first)
            continue;

        f[cur] = true;

        for(int i = 0; i<v[cur].size(); i++)
        {
            int target = v[cur][i].first;
            int cost = v[cur][i].second;
            if (d[target] > d[cur] + cost)
            {
                d[target] = d[cur] + cost;
                prev[target] = cur;
                pq.push(mp(d[target], target));
            }
        }
    }

    if (d[bS] == INF)
    {
        printf("-1");
        return 0;
    }

    vector<int> path;

    int cur = prev[bS];

    while (cur != -1)
    {
        path.pb(cur);
        cur = prev[cur];
    }

    printf("%d %d %d", path[path.size()-2] + 1, path[0] + 1, d[bS]);

    return 0;
}
