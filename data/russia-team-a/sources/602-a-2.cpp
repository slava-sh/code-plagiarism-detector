#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>

using namespace std;

#define PROBLEMNAME "binary"

#ifdef LOCAL
# define DBG(fmt, ...) fprintf (stderr, "DBG: " fmt "\n", ## __VA_ARGS__)
#else
# define DBG(...)
#endif // LOCAL

const int maxN = 1500;
vector <int> edgesTo[maxN];

void addEdge (int u, int v)
{
    edgesTo[u].push_back (v);
    edgesTo[v].push_back (u);
}

int nColors = 0;
int color[maxN];

void colorDfs (int v)
{
    color[v] = nColors;
    
    for (unsigned i = 0; i < edgesTo[v].size(); i++)
    {
        int to = edgesTo[v][i];
        if (!color[to])
            colorDfs (to);
    }
}

vector <int> ineqEdgesTo[maxN];

void addIneqEdge (int u, int v)
{
    ineqEdgesTo[u].push_back (v);
    ineqEdgesTo[v].push_back (u);
}

void impossible()
{
    printf ("0\n");
    exit (0);
}

int nXcolors = 0;
int xcolor[maxN];
int parityColor[maxN];

void xcolorDfs (int v, int mustParityColor)
{
    xcolor[v] = nXcolors;
    parityColor[v] = mustParityColor;
    //DBG ("dfs %d", v);
    
    for (unsigned i = 0; i < ineqEdgesTo[v].size(); i++)
    {
        int to = ineqEdgesTo[v][i];
        if (to == 0) continue;
        
        if (!xcolor[to])
            xcolorDfs (to, 1 - mustParityColor);
        else if (parityColor[to] != 1 - mustParityColor)
            impossible();
    }
}

int main()
{
    assert (freopen (PROBLEMNAME ".in", "r", stdin));
#ifndef LOCAL
    assert (freopen (PROBLEMNAME ".out", "w", stdout));
#endif // LOCAL

    int n;
    scanf ("%d", &n);
    
    vector < pair <int, int> > rawIneq;
    
    for (int i = 0; i < n; i++)
    {
        int nowZ;
        scanf ("%d", &nowZ);
        
        if (nowZ >= n)
            impossible();
            
        if (i == 0 && nowZ != 0 && nowZ != -1)
            impossible();
        
        if (i == 0 || nowZ == -1) continue;
        
        for (int j = 0; j < nowZ; j++)
            addEdge (j, i + j);
            
        rawIneq.push_back (make_pair (nowZ, i + nowZ));
    }
        
    for (int i = 0; i < n; i++)
        if (!color[i])
        {
            nColors++;
            colorDfs (i);
        }
        
    for (int i = 0; i < n; i++)
        DBG ("vertex %d color %d", i, color[i]);
    
    for (unsigned i = 0; i < rawIneq.size(); i++)
    {
        int f = color[rawIneq[i].first];
        int t = color[rawIneq[i].second];
        
        if (f == t)
            impossible();
        
        addIneqEdge (f, t);
        DBG ("ineq edge %d => %d", f, t);
    }
    
    for (int i = 1; i <= nColors; i++)
        if (!xcolor[i])
        {
            nXcolors++;
            xcolorDfs (i, 0);
        }        
        
    for (int i = 1; i <= nColors; i++)
        DBG ("xvertex %d xcolor %d", i, xcolor[i]);
        
    const int MODULE = 1000000007;
    
    DBG ("%d xcolors", nXcolors);
        
    int answer = 1;
    for (int i = 0; i < nXcolors; i++)
        answer = (answer * 2) % MODULE;

    printf ("%d\n", answer);

    return 0;
}
