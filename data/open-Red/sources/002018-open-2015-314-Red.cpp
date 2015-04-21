/**
 * “¿Ÿ»Ã
**/

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <memory.h>
#include <stack>
#include <queue>
#include <deque>
#include <assert.h>


using namespace std;

vector<pair<int, int>> g[100001];
vector<int> con[100001];
pair<int, pair<int, int>> q[500000];
vector<bool> used[100001];
int color[100001];

int n, m, d;

int get_left(int ver, int tem)
{
    int l = 0, r = g[ver].size();
    while(l != r)
    {
        int m = (l + r) / 2;
        if(g[ver][m].second < tem)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int get_right(int ver, int tem)
{
    int l = 0, r = g[ver].size();
    while(l != r)
    {
        int m = (l + r) / 2;
        if(g[ver][m].second <= tem)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int bfs(int a, int b)
{
    int l = 0, r = 0;
    for(int i = 0; i < (int)g[a].size(); ++i)
    {
        q[r] = {1, g[a][i]};
        ++r;
        used[a][i] = true;
    }

    while(l != r)
    {
        auto p = q[l];
        ++l;
        int len = p.first, ver = p.second.first, tem = p.second.second;
        if(ver == b)
            return len;
        int low = get_left(ver, tem - d);
        int up = get_right(ver, tem + d);
        for(; low != up; ++low)
        {
            if(used[g[ver][low].first][con[ver][low]])
                continue;
            used[g[ver][low].first][con[ver][low]] = true;
            q[r] = {len + 1, g[ver][low]};
            ++r;
        }
        if(r > 100000)
        {
            cout << "jewhfoefn" << endl;
            exit(0);
        }
    }
    return -1;
}

void dfs(int v, int c)
{
    color[v] = c;
    for(auto i : g[v])
    {
        if(color[i.first] == 0)
            dfs(i.first, c);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> n >> m >> d;
    for(int i = 0; i < m; ++i)
    {
        int a, b, t;
        cin >> a >> b >> t;
        con[a].push_back(g[b].size());
        con[b].push_back(g[a].size());
        g[a].push_back({b, t});
        g[b].push_back({a, t});
    }
    memset(color, 0, sizeof(color));
    int c = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(color[i] == 0)
        {
            dfs(i, c);
            ++c;
        }
    }
    int z;
    cin >> z;
    for(int i = 0; i < z; ++i)
    {
        for(int j = 1; j <= n; ++j)
            used[j].assign(g[j].size(), false);
        int a, b;
        cin >> a >> b;
        if(color[a] != color[b])
        {
            cout << -1 << endl;
        }
        else
            cout << bfs(a, b) << endl;
    }
    return 0;
}
