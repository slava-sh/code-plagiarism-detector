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

int n, m, d;

int bfs(int a, int b)
{
    queue<pair<int, pair<int, int>>> q; //{length, {vertex, temp}}
    set<pair<int, int>> used;
    for(auto i : g[a])
    {
        q.push({1, i});
        used.insert(i);
    }

    while(not q.empty())
    {
        auto p = q.front();
        q.pop();
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
            q.push({len + 1, i});
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
