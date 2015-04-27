

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <bitset>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, int> pdi;
typedef vector<int> vi;

typedef pair<int, string> pis;

struct Board
{
    int elems[105];
    bool used;
    vector<int> edges;
    Board()
    {
        used = 0;
    }
} boards[1005];

struct Edge
{
    int from, to, dist;
};

int sz;

inline int diff(Board &b1, Board &b2)
{
    int res = 0;
    rep(i, 0, sz)
    {
       if (b1.elems[i] != b2.elems[i])
           res++;
    }
    return res;
}

void run()
{
    int n, m, k, w;
    
    scanf("%d%d%d%d", &n, &m, &k, &w);
    
    sz = n * m;
    
    vector<pii> e1, e2;
    
    rep(i, 0, k)
    {
        rep(j, 0, n*m)
        {
            char cs;
            scanf(" %c", &cs);
            boards[i].elems[j] = cs;
//            boards[i].elems[j] = rand() % 10;
        }
    }
    
    vector<Edge> edges;
    
    edges.push_back({-1, 0, sz});
    
    rep(i, 0, k)
    {
        rep(j, 0, k)
        {
            if (i == j)
                continue;
            int d = diff(boards[i], boards[j]) * w;
//            ed1.push_back(pii(d, ed2.size()));
//            ed2.push_back(pii(i, j));
            boards[i].edges.push_back(edges.size());
            int from = i;
            if (d > sz)
            {
                d = sz;
                from = -1;
            }
            edges.push_back({from, j, d});
        }
    }
    
    priority_queue<pii> krusk;
    krusk.push(pii(-sz, 0));
    
    int res = 0;
    
    vector<pii> ans;
    
    while (!krusk.empty())
    {
        pii tp = krusk.top();
        krusk.pop();
        
        int edgeNum = tp.second;
        Edge &curEdge = edges[edgeNum];
        
        Board &cb = boards[curEdge.to];
        if (cb.used)
            continue;
        cb.used = 1;
        ans.push_back({curEdge.to + 1, curEdge.from + 1});
//        printf("%d %d\n", curEdge.to + 1, curEdge.from + 1);
        
        res += -tp.first;
        
        rep(i, 0, cb.edges.size())
        {
            int en = cb.edges[i];
            Edge &ne = edges[en];
            int to = ne.to;
            if (boards[to].used)
                continue;
            krusk.push(pii(-ne.dist, en));
        }
    }
    
    printf("%d\n", res);
    
    rep(i, 0, ans.size())
    {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    
//    printf("%d\n", maxEaten);
}

//#define prob "settling"


int main()
{
#ifdef LOCAL_DEBUG
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif
    run();
#ifdef LOCAL_DEBUG
    fprintf(stderr,  "\n=============\n");
    fprintf(stderr, "Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}