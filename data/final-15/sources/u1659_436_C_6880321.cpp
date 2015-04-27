#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <numeric>
#include <ctime>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <stack>
#include <string>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char nextchar(){char a[8];scanf("%s",a);return a[0];}
int nextint(){int a;scanf("%d",&a);return a;}
ll nextll(){ll a;scanf("%I64d",&a);return a;}
double nextdouble(){double a;scanf("%lf",&a);return a;}

int n, m;
class level
{
public:
    char g[16][16];
};

int getDiff(const level &a, const level &b)
{
    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a.g[i][j] != b.g[i][j])
                res++;
    return res;
}

class Edge
{
public:
    Edge(int a = 0, int b = 0, int c = 0): a(a), b(b), c(c) {}
    int a, b, c;
};

bool operator<(const Edge &a, const Edge &b)
{
    return a.c < b.c;
}

int parent[1<<10];
int get(int a)
{
    if(a == parent[a]) return a;
    return parent[a] = get(parent[a]);
}

void unite(int a, int b)
{
    a = get(a);
    b = get(b);
    
    if(rand()&1)
        parent[a] = b;
    else
        parent[b] = a;
}

int depth[1<<10];
int wws[1<<10];
int pp[1<<10];
vector<vector<pair<int, int> > > g;

void dfs(int v, int p, int w, int d)
{
    depth[v] = d;
    pp[v] = p;
    wws[v] = w;
    
    for(int i = 0; i < g[v].size(); i++)
    {
        if(g[v][i].first != p)
        {
            dfs(g[v][i].first, v, g[v][i].second, d+1);
        }
    }
    
}

vector<level> ls;
int ret = 0;
vector<pair<int, int> > res;
void solve(int a, int b)
{
    if(wws[a] == n*m)
    {
        res.push_back(make_pair(a+1, 0));
    }
    else
    {
        res.push_back(make_pair(a+1, b+1));
    }
    ret += wws[a];
}

int main()
{
    n = nextint();
    m = nextint();
    int k = nextint();
    int w = nextint();
    
    ls = vector<level> (k);
    for(int i = 0; i < k; i++)
        for(int ii = 0; ii < n; ii++)
            scanf("%s", ls[i].g[ii]);
    
    vector<Edge> es;
    for(int i = 0; i < k; i++)
    {
        for(int j = i+1; j < k; j++)
        {
            es.push_back(Edge(i, j, min(n*m, w*getDiff(ls[i], ls[j]))));
        }
    }
    
    
    sort(es.begin(), es.end());
    
    for(int i = 0; i < (1<<10); i++)
        parent[i] = i;
    
    g = vector<vector<pair<int, int> > > (k);
    for(int i = 0; i < es.size(); i++)
    {
        if(get(es[i].a) != get(es[i].b))
        {
            unite(es[i].a, es[i].b);
            g[es[i].a].push_back(make_pair(es[i].b, es[i].c));
            g[es[i].b].push_back(make_pair(es[i].a, es[i].c));
        }
    }
    
    dfs(0, -1, n*m, 0);
    
    for(int d = 0; d < (1<<10); d++)
    {
        for(int i = 0; i < k; i++)
        {
            if(depth[i] == d)
            {
                solve(i, pp[i]);
            }
        }
    }
    
    cout << ret << endl;
    for(int i = 0; i < res.size(); i++)
        cout << res[i].first << " " << res[i].second << endl;
    
    
    
    
    return 0;
}





























