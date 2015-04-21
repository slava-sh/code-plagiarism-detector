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


using namespace std;

vector<pair<int, int>> g[100001];
pair<int, pair<int, int>> q[500000];

int n, m, d;

int bfs(int a, int b)
{
    set<pair<int, int>> used;
    int l = 0, r = 0;
    for(auto i : g[a])
    {
        q[r] = {1, i};
        ++r;
        used.insert(i);
    }

    while(l != r)
    {
        auto p = q[l];
        ++l;
        int len = p.first, ver = p.second.first, tem = p.second.second;
        if(ver == b)
            return len;
        for(auto i : g[ver])
        {
            if(used.find(i) != used.end())
                continue;
            if(abs(tem - i.second) > d)
                continue;
            used.insert(i);
            q[r] = {len + 1, i};
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
        g[a].push_back({b, t});
        g[b].push_back({a, t});
    }
    int z;
    cin >> z;
    for(int i = 0; i < z; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << bfs(a, b) << endl;
    }
    return 0;
}
