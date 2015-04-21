/**
 * �����
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


using namespace std;

vector<pair<int, int>> g[100001];
vector<int> con[100001];
pair<int, pair<int, int>> q[500000];
vector<bool> used[100001];

int n, m, d;

int bfs(int a, int b)
{
    int l = 0, r = 0;
    for(int i = 0; i < g[a].size(); ++i)
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
        for(int i = 0; i < g[ver].size(); ++i)
        {
            if(used[g[ver][i].first][con[ver][i]])
                continue;
            if(abs(tem - g[ver][i].second) > d)
                continue;
            used[g[ver][i].first][con[ver][i]] = true;
            q[r] = {len + 1, g[ver][i]};
            ++r;
        }
    }
    return -1;
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
    int z;
    cin >> z;
    for(int i = 0; i < z; ++i)
    {
        for(int j = 1; j <= n; ++j)
            used[j].assign(g[j].size(), false);
        int a, b;
        cin >> a >> b;
        cout << bfs(a, b) << endl;
    }
    return 0;
}