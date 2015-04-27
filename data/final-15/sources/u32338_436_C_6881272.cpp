#pragma warning( disable : 4996)
#pragma comment(linker, "/STACK:666000000")

#define bublic public

#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <time.h>
#include <vector>
#include <stack>

#define nextLine() {for(int c=getchar(); c!='\n' && c!=EOF; c=getchar());}
#define sqr(a) ((a)*(a))
#define has(mask,i) (((mask) & (1<<(i))) == 0 ? false : true)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#define TASK "file"

using namespace std;

#define mp(x, y) make_pair(x, y)
#define pb(_o_) push_back(_o_)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double ldb;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#ifndef ONLINE_JUDGE
typedef vector<int> vc;
typedef vector<vc> vvc;
#else
typedef vector<char> vc;
typedef vector<char> vvc;
#endif

typedef list<int> li;

const int inf = (1 << 30) - 1;
const ldb eps = 1e-9;
const ldb pi = fabs(atan2(0.0, -1.0));

#ifndef ONLINE_JUDGE
#define parr(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<a[i][j]<<" ";puts("");}puts("");
#else
#define parr(a,n,m) for(int i=0;i<2;i++)i++;
#endif

void ML(const bool v)
{
    if (v)
        return;
    int *ass;
    for (;;)
    {
        ass = new int[2500000];
        for (int i = 0; i < 2500000; i++)
            ass[i] = rand();
    }
}

void TL(const bool v)
{
    if (v)
        return;
    int *ass;
        ass = new int[250];
    for (;;)
    {
        for (int i = 0; i < 250; i++)
            ass[i] = rand();
    }
}

void PE(const bool v)
{
    if (v)
        return;
    puts("ass 1 2 3 4 5 6 fuck");
    exit(0);
}

int h, w, n, cost;

char s[1010][11][11];

bool LoAd()
{
    if (4 != scanf("%d%d%d%d\n", &h, &w, &n, &cost))
        return false;

    for (int i = 0; i < n; i++)
        for (int x = 0; x < h; x++)
            gets(s[i][x]);
    return true;
}

int a[1010][1010];
bool added[1010];
int dist[1010];
int from[1010];

void relax(const int id)
{
    added[id] = true;
    for (int i = 0; i < n; i++)
        if (dist[i] > a[id][i])
        {
            dist[i] = a[id][i];
            from[i] = id;
        }
}

vector<pii> ans;

void SoLvE()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int x = 0; x < h; x++)
                for (int y = 0; y < w; y++)
                    if (s[i][x][y] != s[j][x][y])
                        a[i][j] += cost;
    
    LL res = 0;
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    for (int i = 0; i < n; i++) if (!added[i])
    {
        res += h * w;
        relax(i);
        ans.push_back(mp(i + 1, 0));
        for (;;)
        {
            int id = -1;
            for (int j = 0; j < n; j++)
                if (!added[j] && dist[j] < h * w)
                    if (-1 == id || dist[j] < dist[id])
                        id = j;
            if (-1 == id)
                break;
            else
            {
                res += dist[id];
                ans.push_back(mp(id + 1, from[id] + 1));
                relax(id);
            }
        }
    }
    cout << res << endl;
    for (int i = 0; i < n; i++)
        printf("%d %d\n", ans[i].first, ans[i].second);

}

int main()
{
    srand( (int) time(NULL));
#ifndef ONLINE_JUDGE
    freopen(TASK".in","r",stdin);   freopen(TASK".out","w",stdout);
#endif
    while (LoAd())
    {
        SoLvE();
#ifdef ONLINE_JUDGE
        break;
#endif
        memset(a, 0, sizeof(a));
        memset(added, false, sizeof(added));
        ans.clear();
        puts("");
    }
    return 0;
}