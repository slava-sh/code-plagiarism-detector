#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define PROBLEMNAME "dwarfs"

#ifdef LOCAL
# define DBG(fmt, ...) fprintf (stderr, "DBG: " fmt "\n", ## __VA_ARGS__)
#else
# define DBG(...)
#endif // LOCAL

const int maxN = 300500;
set <int> edgesTo[maxN];

void addEdge (int u, int v)
{
    edgesTo[u].insert (v);
    edgesTo[v].insert (u);
}

void deleteEdge (int u, int v)
{
    edgesTo[u].erase (v);
    edgesTo[v].erase (u);
}

int vuPath[maxN];
int pathLength = 0;

bool pathDfs (int vertex, int depth, int needFind, int dfsParent)
{
    vuPath[depth] = vertex;
    if (vertex == needFind)
    {
        pathLength = depth;
        return true;
    }        
    
    for (set <int>::iterator it = edgesTo[vertex].begin(); it != edgesTo[vertex].end(); it++)
    {
        int now = *it;
        if (now == dfsParent) continue;
        
        if (pathDfs (now, depth + 1, needFind, vertex))
        {
            deleteEdge (vertex, now);
            return true;
        }
    }
    
    return false;
}

int depth[maxN];
int prefixMax[maxN], suffixMax[maxN];

void depthDfs (int vertex, int dfsParent)
{
    for (set <int>::iterator it = edgesTo[vertex].begin(); it != edgesTo[vertex].end(); it++)
    {
        int now = *it;
        if (now == dfsParent) continue;
        
        depthDfs (now, vertex);
        depth[vertex] = max (depth[vertex], depth[now] + 1);
    }
}

int main()
{
    assert (freopen (PROBLEMNAME ".in", "r", stdin));
#ifndef LOCAL
    assert (freopen (PROBLEMNAME ".out", "w", stdout));
#endif // LOCAL

    int nVertices;
    scanf ("%d", &nVertices);
    
    for (int i = 0; i < nVertices - 1; i++)
    {
        int u, v;
        scanf ("%d %d", &u, &v);
        u--;
        v--;
        
        addEdge (u, v);
    }
    
    int vStart, uStart;
    scanf ("%d %d", &vStart, &uStart);
    vStart--;
    uStart--;
    
    assert (pathDfs (vStart, 0, uStart, -1));
    
    DBG ("found path of length %d", pathLength);
    for (int i = 0; i <= pathLength; i++)
    {
        DBG ("path vertex %d", vuPath[i] + 1);
        depthDfs (vuPath[i], -1);
        DBG ("depth %d", depth[vuPath[i]]);
    }
    pathLength++;
    
    for (int i = 0; i < pathLength; i++)
    {
        if (i == 0)
            prefixMax[i] = depth[vuPath[i]];
        else
            prefixMax[i] = max (prefixMax[i - 1], depth[vuPath[i]] + i);
    }
    
    for (int i = pathLength - 1; i >= 0; i--)
    {
        if (i == pathLength - 1)
            suffixMax[i] = depth[vuPath[i]];
        else
            suffixMax[i] = max (suffixMax[i + 1], depth[vuPath[i]] + pathLength - i - 1);
    }
    
    for (int i = 0; i < pathLength; i++)
        DBG ("%d: prefix max %d, suffix max %d", vuPath[i] + 1, prefixMax[i], suffixMax[i]);
    
    assert (pathLength > 1);
    
    int answer = 0;
    for (int i = 0; i < pathLength - 1; i++)
        answer = max (min (prefixMax[i], suffixMax[i + 1]), answer);
    
    printf ("%d\n", answer + 1);
    
    return 0;
}
