#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <iostream>
#include <cmath>
#include <sstream>
#include <complex>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:128000000")

typedef long long int64;
typedef unsigned long long uint64;

#define y1 _dsfkjdsfksdj
#define y0 _sfsdkfdop

typedef unsigned uint;
typedef vector<int64> vi64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int64,int64> pii64;
typedef pair<int,pii> piii;
typedef pair<pii,pii> piiii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef pair<int,string> pis;

int n, m, k, w;
vector < vector<string> > a;
int d[1 << 10][1 << 10];
piii r[1 << 20];
int l;
vvi g;
int p[1 << 10];
int was[1 << 10];

int get_parent(int v)
{
    if (p[v] == v) return v;
    return p[v] = get_parent(p[v]);
}

inline void unite(int u, int v)
{
    if (get_parent(u) > get_parent(v))
        swap(u, v);

    p[p[v]] = p[u];
    p[v] = p[u];
}

inline void read_field(vector<string> &A)
{
    string s = "";
    char c;
    A.resize(n);
    for (int i = 0; i < n; ++i)
    {
        s = "";
        for (int j = 0; j < m; ++j)
        {
            scanf("\n%c", &c);
            s += c;
        }
        A[i] = s;
    }
}

inline int get_dist(vector <string> &A, vector <string> &B)
{
    int res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (A[i][j] != B[i][j])
                ++res;
        }
    return res;
}

inline void init()
{
    memset(d, 0, sizeof d);
    scanf("%d%d%d%d", &n, &m, &k, &w);
    a.resize(k);
    for (int i = 0; i < k; ++i)
        read_field(a[i]);
}

void dfs(int x, int p)
{
    if (x == p)
    {
        printf("%d %d\n", x + 1, 0);
    } else {
        printf("%d %d\n", x + 1, p + 1);
    }
    was[x] = 1;
    int K = (int)g[x].size();
    for (int i = 0; i < K; ++i)
    {
        int y = g[x][i];
        if (y == p) continue;
        if (was[y]) continue;
        dfs(y, x);
    }
}

int main()
{   
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    
    init();

    for (int i = 0; i < k; ++i)
        for (int j = i + 1; j < k; ++j)
        {
            d[i][j] = d[j][i] = get_dist(a[i], a[j]) * w;
        }

    l = 0;
    int cost = n * m;
    for (int i = 0; i < k; ++i)
        for (int j = i + 1; j < k; ++j)
            if (d[i][j] < cost)
            {
                r[l++] = piii(d[i][j], pii(i, j));
            }
    
    for (int i = 0; i < k; ++i)
        p[i] = i;

    sort(r, r + l);

    g.resize(k);
    int cnt = 0;
    int res = 0;
    for (int i = 0; i < l; ++i)
    {
        int x = r[i].second.first;
        int y = r[i].second.second;
        if (get_parent(x) == get_parent(y)) continue;
        unite(x, y);
        g[x].push_back(y);
        g[y].push_back(x);
        res += r[i].first;
        ++cnt;
    }

    res += (k - cnt) * cost;

    printf("%d\n", res);
    memset(was, 0, sizeof was);

    for (int i = 0; i < k; ++i)
    {
        if (was[i]) continue;
        dfs(i, i);
    }

    return 0;
}