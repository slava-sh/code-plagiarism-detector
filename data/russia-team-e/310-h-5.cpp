#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector< pair<int, int> > g[5444];
int a[5444];
bool vis[5444];

pair<int, int> h[123456];

bool dfs(int v, int x)
{
    vis[v] = true;

    if(a[v] == x)
        return true;

    for(int i = 0; i < g[v].size(); ++i)
        if(!vis[g[v][i].first])
            if(dfs(g[v][i].first, x))
                return true;

    return false;
}

int main()
{
    freopen("secure.in", "r", stdin);
    freopen("secure.out", "w", stdout);

    srand(15423);

    int t1, t2, t3;
    scanf("%d%d", &n, &m);

    t2 = 0;
    t3 = 0;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        if(a[i] == 2)
            a[i] = -1;

        if(a[i] == 1)
            ++t2;
        if(a[i] == -1)
            ++t3;
    }

    int use_s;
    if(t3 < t2)
        use_s = -1;
    else
        use_s = 1;
    int use_f = - use_s;

    for(int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &t1, &t2, &t3);
        --t1;
        --t2;
        g[t1].push_back(make_pair(t2, t3));
        g[t2].push_back(make_pair(t1, t3));
    }

    bool fnd = false;
    for(int s = 0; s < n; ++s)
        if(a[s] == use_s)
        {
            for(int i = 0; i < n; ++i)
                vis[i] = false;
            if(dfs(s, use_f))
            {
                fnd = true;
                break;
            }
        }

    if(!fnd)
    {
        cout << "-1\n";
        return 0;
    }

    for(int i = 0; i < n; ++i)
        random_shuffle(g[i].begin(), g[i].end());

    int fb, sb;
    int dbest = INT_MAX;
    for(int s = n-1; s > -1; --s)
        if(a[s] == use_s)
        {
            int hl = 0;

            for(int i = 0; i < n; ++i)
                vis[i] = false;

            h[hl] = make_pair(0, s);
            ++hl;
            push_heap(h, h+hl);

            int v, d;
            while(hl > 0)
            {
                v = h[0].second;
                d = -h[0].first;
                pop_heap(h, h+hl);
                --hl;

                if(vis[v])
                    continue;
                vis[v] = true;

                if(a[v] == use_f)
                {
                    if(d < dbest)
                    {
                        sb = s;
                        fb = v;
                        dbest = d;
                    }
                    break;
                }

                if(a[v] == use_s && v > s)
                    continue;

                if(d > dbest)
                    break;

                for(int i = 0; i < g[v].size(); ++i)
                    if(!vis[g[v][i].first])
                    {
                        h[hl] = make_pair(-d-g[v][i].second, g[v][i].first);
                        ++hl;
                        push_heap(h, h+hl);
                    }
            }


        }

    if(use_s == -1)
        swap(sb, fb);

    cout << sb+1 << " " << fb+1 << " " << dbest << "\n";

    return 0;
}
