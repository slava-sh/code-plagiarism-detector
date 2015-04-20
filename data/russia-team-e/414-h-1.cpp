#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int N = (int)1e5 + 10, INF = (int)2e9 + 10;

struct Pt
{
    int x, p;
};
Pt d[N];
int a[N];
vector <pair <int, int> > g[N];
bool used[N];


int main()
{
    freopen("secure.in", "r", stdin);
    freopen("secure.out", "w", stdout);
    int n, m, i, j, k, f, t, cost;
    cin >> n >> m;
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < m; i++)
    {
        scanf("%d%d%d", &f, &t, &cost);
        f--, t--;
        g[f].push_back(make_pair(t, cost));
        g[t].push_back(make_pair(f, cost));
    }
    for(i = 0; i < n; i++)
        d[i].x = INF, d[i].p = -1;
    for(i = 0; i < n; i++)
        if(a[i] == 1)
            d[i].x = 0, d[i].p = i;
    for(i = 0; i < n; i++)
    {
        int mn = INF, v = -1;
        for(j = 0; j < n; j++)
            if(!used[j] && d[j].x < mn)
                mn = d[j].x, v = j;
        if(mn == INF)
            break;
        used[v] = 1;
        for(j = 0; j < (int)g[v].size(); j++)
        {
            int to = g[v][j].first;
            cost = g[v][j].second;
            if(d[to].x > d[v].x + cost)
            {
                d[to].x = d[v].x + cost;
                d[to].p = d[v].p;

            }
        }
    }
    int ans1, ans2, ans = INF;
    for(i = 0; i < n; i++)
        if(a[i] == 2 && d[i].x < ans)
        {
            ans = d[i].x;
            ans1 = d[i].p;
            ans2 = i;
        }
    if(ans == INF)
    {
        cout << -1;
        return 0;
    }
    cout << ans1 + 1 << ' ' << ans2 + 1 << ' ' << ans;
    return 0;
}
/*
6 7
1 0 1 2 2 0
1 3 3
1 2 4
2 3 3
2 4 2
1 6 5
3 5 6
5 6 1
*/
