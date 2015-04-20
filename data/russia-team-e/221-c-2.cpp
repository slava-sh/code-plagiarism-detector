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

const int N = 222222;

vector< vector<int> > v;
int d1[N];
int d2[N];
int d[N];
int f[N];
int n;
int a, b;

void dfs(int a, int dist, int *d)
{
    d[a] = dist;
    for(int i = 0; i<v[a].size(); i++)
    {
        if (d[v[a][i]] > d[a] + 1)
            dfs(v[a][i], dist + 1, d);
    }
}

int main()
{
    #define TASKNAME "dwarfs"

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        freopen(TASKNAME".in", "r", stdin);
        freopen(TASKNAME".out", "w", stdout);
    #endif // DEUBG

    scanf("%d", &n);
    v.resize(n);

    for(int i = 0; i<n-1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        v[x].pb(y);
        v[y].pb(x);
    }

    scanf("%d%d", &a, &b);
    a--, b--;

    for(int i = 0; i<n; i++)
        d1[i] = d2[i] = INF;

    dfs(a, 1, d1);
    dfs(b, 1, d2);

    int res = 0;

    for(int i = 0; i<n; i++)
    {
        d[i] = min(d1[i], d2[i]);
        f[d[i]]++;
    }

    for(int i = 0; i<n; i++)
    {
        if (f[d[i]] == 1)
        {
            printf("%d", res);
            return 0;
        }
        if (f[d[i]] >= 2)
            res = max(res, f[d[i]]);
    }

    printf("%d", res);


    return 0;
}
