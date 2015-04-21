#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;
vector<vector<pair<int, int> > > G;
queue<pair<pair<int, int>, int> > Order;
set<pair<int, int> > Visited;
vector<int> Dist;

int N, M, D, Q, A, B;
bool Flag;

void bfs()
{
    pair<pair<int, int>, int> Curr = Order.front();
    Order.pop();
    Visited.insert(Curr.first);
    int V = Curr.first.first, T = Curr.first.second, Curr_Dist = Curr.second;
    Dist[V] = min(Dist[V], Curr_Dist);
    if (V == B)
    {
        Flag = 1;
        return;
    }
    for (int i = 0; i < G[V].size(); ++i)
    {
        if (abs(G[V][i].second - T) <= D and (Visited.find(G[V][i]) == Visited.end()))
        {
            Order.push(make_pair(G[V][i], Curr_Dist + 1));
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    scanf("%d%d%d", &N, &M, &D);
    G.resize(N);
    int a, b, t;
    for (int i = 0; i < M; ++i)
    {
        scanf("%d%d%d", &a, &b, &t); --a; --b;
        G[a].push_back(make_pair(b, t));
        G[b].push_back(make_pair(a, t));
    }

    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i)
    {
        scanf("%d%d", &A, &B); --A; --B;
        while (not Order.empty())
        {
            Order.pop();
        }
        Visited.clear();
        Dist.assign(N, 1e9);
        for (int i = 0; i < G[A].size(); ++i)
        {
            Order.push(make_pair(G[A][i], 1));
        }
        Flag = 0;
        while (not Flag and not Order.empty())
        {
            bfs();
        }
        if (not Flag)
        {
            Dist[B] = -1;
        }
        printf("%d\n", Dist[B]);
    }
}

