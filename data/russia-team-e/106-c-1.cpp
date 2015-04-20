#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <queue>

#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = (int)2e5 + 7;
const int INF = 2e9 + 5;
const int MOD = 1e9 + 7;

vector<int> a[N];
int lca[21][N], timmer = 1, tin[N], tout[N];
int h[N], k[N], s, f;

void dfs(int v, int p, int g = 0)
{
    tin[v] = timmer++;
    lca[0][v] = p;
    h[v] = g;
    for (int i = 1; i < 20; ++i)
        lca[i][v] = lca[i - 1][lca[i - 1][v]];
    for (int i = 0; i < a[v].size(); ++i)
        if (a[v][i] != p)
            dfs(a[v][i], v, g + 1);
    tout[v] = timmer++;
}

bool ok(int x, int y)
{
    return tin[x] >= tin[y] && tout[x] <= tout[y];
}

void rec(int v, int p = -1)
{
    bool flag = 0;
    for (int i = 0; i < a[v].size(); ++i)
        if (a[v][i] != p)
        {
            flag = 1;
            rec(a[v][i], v);
        }
    if (!flag)
        k[v] = 0;
    else
        for (int i = 0; i < a[v].size(); ++i)
            if (a[v][i] != p)
            {
                if (ok(f, a[v][i]))
                    k[v] = max(k[v], k[a[v][i]] - 1);
                else
                    k[v] = max(k[v], k[a[v][i]] + 1);
            }
}

int get_lca(int x, int y)
{
    int v = y;
    for (int i = 19; i > -1; --i)
    {
        if (!ok(x, lca[i][v]))
            v = lca[i][v];
    }
    return v;
}

int main()
{
    freopen("dwarfs.in", "r", stdin);
    freopen("dwarfs.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        k[i] = -INF;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        a[x].pb(y);
        a[y].pb(x);
    }
    cin >> s >> f;
    --s;
    --f;
    dfs(s, s);
    rec(s);
    int maxi = 1;
    for (int i = 0; i < n; ++i)
        if (i != s && i != f)
        {
            if (tin[i] >= tin[f] && tout[i] <= tout[f])
                continue;
            int x = get_lca(i, f);
            maxi = max(maxi, min(max((h[f] - h[x]) + 1 + k[x], h[f] - h[x] + 1), h[i] + 1));
        }
    cout << maxi << endl;
    return 0;
}

/*

9
1 2
1 3
3 7
7 9
7 8
4 5
4 6
1 4
3 5

9
1 2
2 3
3 4
4 5
5 6
6 7
5 8
8 9
7 1

8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8

6
1 2
2 3
3 4
4 5
5 6
4 5

*/
