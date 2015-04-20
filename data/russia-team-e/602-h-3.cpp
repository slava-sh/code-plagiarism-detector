#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define PROBLEMNAME "secure"

#ifdef LOCAL
# define DBG(fmt, ...) fprintf (stderr, "DBG: " fmt "\n", ## __VA_ARGS__)
#else
# define DBG(...)
#endif // LOCAL

const int maxN = 5500;
int type[maxN];

int nVertices, nEdges;

vector < pair <int, int> > edgesFrom[maxN];
int previous[maxN];

const int INF = 2000000000;
int currentDistance[maxN];

int currentBest = INF;

// cost - vertices
pair <int, pair <int, int> > getAnswerThrough()
{
    // distance - vertex
    set < pair <int, int> > distancesTo;
    
    for (int i = 0; i < nVertices; i++)
    {
        currentDistance[i] = ((type[i] == 1) ? 0 : INF);
        previous[i] = -1;
        distancesTo.insert (make_pair (currentDistance[i], i));
    }
        
    while (!distancesTo.empty())
    {
        pair <int, int> shortestPair = *distancesTo.begin();
        distancesTo.erase (distancesTo.begin());
        int shortestNow = shortestPair.second;
        
        if (currentDistance[shortestNow] == INF)
            break;
                
        if (type[shortestNow] != 0 && type[shortestNow] != 1)
        {
            int now = shortestNow;
            while (type[now] != 1)
                now = previous[now];
            
            return make_pair (currentDistance[shortestNow], make_pair (now, shortestNow));
        }
        
        for (unsigned i = 0; i < edgesFrom[shortestNow].size(); i++)
        {
            pair <int, int> toCostEdge = edgesFrom[shortestNow][i];
            int cost = toCostEdge.second;
            int to = toCostEdge.first;
            
            if (currentDistance[to] > currentDistance[shortestNow] + cost)
            {
                distancesTo.erase (make_pair (currentDistance[to], to));
                currentDistance[to] = currentDistance[shortestNow] + cost;
                previous[to] = shortestNow;
                distancesTo.insert (make_pair (currentDistance[to], to));
            }
        }
    }
    
/*#ifdef LOCAL
    for (int i = 0; i < nVertices; i++)
        DBG ("%d - %d: distance %d", v, i, currentDistance[i]);
#endif*/
    
    return make_pair (-1, make_pair (-1, -1));
}

int main()
{
    assert (freopen (PROBLEMNAME ".in", "r", stdin));
#ifndef LOCAL
    assert (freopen (PROBLEMNAME ".out", "w", stdout));
#endif // LOCAL

    scanf ("%d %d", &nVertices, &nEdges);
    
    for (int i = 0; i < nVertices; i++)
    {
        scanf ("%d", &type[i]);
    }
    
    for (int i = 0; i < nEdges; i++)
    {
        int from, to, cost;
        scanf ("%d %d %d", &from, &to, &cost);
        from--;
        to--;
        
        edgesFrom[from].push_back (make_pair (to, cost));
        edgesFrom[to].push_back (make_pair (from, cost));
    }
    
    pair <int, pair <int, int> > t = getAnswerThrough();
    
    if (t.first == -1)
        printf ("-1\n");
    else
        printf ("%d %d %d\n", t.second.first + 1, t.second.second + 1, t.first);
    
    return 0;
}
