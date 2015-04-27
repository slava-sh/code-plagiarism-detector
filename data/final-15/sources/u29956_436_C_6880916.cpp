//Krzysztof Pieprzak
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <deque>
#include <stack>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define Size(x) (int)x.size()
#define VAR(v,n) typeof(n)v = (n)
#define FOR(i,a,b) for(VAR(i,a); i < (b); ++i)
#define FORE(i,a,b) for(VAR(i,a); i <= (b); ++i)
#define FORREV(i,a,b) for(VAR(i,b); i >= (a); --i)
#define FORSTEP(i,a,b,step) for(VAR(i,a); i < (b); i += (step))
#define FOREACH(i,c) for(VAR(i,(c).begin()); i != (c).end(); ++i)
#define ALL(x) x.begin(),x.end()
#define CLEAR(t) memset(t, 0, sizeof(t))
#define F first
#define S second
#define MP make_pair
#define PUB push_back
#define POB pop_back
#define pieprzu ios_base::sync_with_stdio(0);

const int    INF = 1000000001;
const double EPS = 10e-9;

const int MAXN = 10;
const int MAXK = 1000;

char lvls[MAXK+5][MAXN+5][MAXN+5];

vpii t[MAXK+5];
vi g[MAXK+5];

bool vis[MAXK+5];

inline int mst(int v)
{
    set<pair<int,pii> > s;
    FOREACH (w, t[v]) s.insert(MP(w->S,MP(w->F,v)));
    vis[v] = 1;

    int ret = 0;

    pair<int,pii> e;
    while (!s.empty())
    {
        e = *(s.begin());s.erase(s.begin());

        if (!vis[e.S.F])
        {
            vis[e.S.F] = 1;

            g[e.S.F].PUB(e.S.S);
            g[e.S.S].PUB(e.S.F);

            ret += e.F;

            FOREACH (w, t[e.S.F])
            {
                if (!vis[w->F])
                {
                    s.insert(MP(w->S,MP(w->F,e.S.F)));
                }
            }
        }
    }

    return ret;
}

void print(int v, int father)
{
    printf("%d %d\n", v+1, father+1);
    vis[v] = 1;

    FOREACH (w, g[v])
    {
        if (*w != father)
        {
            print(*w,v);
        }
    }
}

void rob()
{
    int n,m,k,w;
    scanf("%d %d %d %d", &n, &m, &k, &w);

    int mxDiff = n*m/w;

    FOR (i, 0, k)
    {
        FOR (j, 0, n)
        {
            scanf("%s", lvls[i][j]);
        }
    }

    int diff;
    FOR (i, 0, k)
    {
        FOR (j, i+1, k)
        {
            diff = 0;
            FOR (ii, 0, n)
            {
                FOR (jj, 0, m)
                {
                    if (lvls[i][ii][jj] != lvls[j][ii][jj])
                    {
                        ++diff;
                        if (diff > mxDiff) break;
                    }
                }
                if (diff > mxDiff) break;
            }
            if (diff <= mxDiff)
            {
                t[i].PUB(MP(j,diff));
                t[j].PUB(MP(i,diff));
            }
        }
    }

    int res = 0;
    FOR (i, 0, k)
    {
        if (!vis[i])
        {
            res += n*m+w*mst(i);
        }
    }

    printf("%d\n", res);
    FOR (i, 0, k) vis[i] = 0;
    FOR (i, 0, k)
    {
        if (!vis[i])
        {
            printf("%d 0\n", i+1);
            vis[i] = 1;
            FOREACH (w, g[i]) print(*w,i);
        }
    }
}

int main()
{
    int test = 1;
    //scanf("%d", &test);

    while (test--) rob();

    return 0;
}
