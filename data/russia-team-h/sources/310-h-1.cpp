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
vector<int> g[5444];
vector<int> w[5444];
int a[5444];
bool vis[5444];

pair<int, int> h[123456];

int main()
{
    freopen("secure.in", "r", stdin);
    freopen("secure.out", "w", stdout);

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
        g[t1].push_back(t2);
        w[t1].push_back(t3);
        g[t2].push_back(t1);
        w[t2].push_back(t3);
    }

    int fb, sb;
    int dbest = INT_MAX;
    for(int s = 0; s < n; ++s)
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

                for(int i = 0; i < g[v].size(); ++i)
                    if(!vis[g[v][i]])
                    {
                        h[hl] = make_pair(-d-w[v][i], g[v][i]);
                        ++hl;
                        push_heap(h, h+hl);
                    }
            }


        }

    if(dbest == INT_MAX)
    {
        cout << "-1\n";
        return 0;
    }

    if(use_s == -1)
        swap(sb, fb);

    cout << sb+1 << " " << fb+1 << " " << dbest << "\n";

    return 0;
}
