#pragma comment(linker, "/STACK:32000000")
#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdarg.h>
#include <memory.h>
#include <string.h>

using namespace std;

const double pi = 3.1415926535897932384626433832795;
#define ALL(x) x.begin(), x.end()
#define LL long long
#define MP make_pair
#define PB push_back
#define CLR(a,b) memset(a, b, sizeof(a))
template<class T> inline T Sqr(const T &x) { return x*x; }
template<class T> inline T Abs(const T &x) { return x >= 0 ? x : -x; }
#define fo(i, n) for (int i = 0; i < (n); i++)
#define foz(i, a) for (int i = 0; i < (a).size(); i++)

#define infile "b.in"
#define outfile "b.out"

#define maxn 2005

int n, m;
char a[maxn][maxn];
int res[maxn][maxn];

void fail()
{
    printf("-1");
    exit(0);
}

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

bool isolated(int i, int j, int &ni, int &nj)
{
    if (a[i][j] == '#') return false;
    fo(d, 4)
    {
        int ii = i + di[d];
        int jj = j + dj[d];
        if (ii >= 0 && jj >= 0 && ii < n && jj < m && a[ii][jj] != '#') {
            ni = ii;
            nj = jj;
            return false;
        }
    }
    return true;
}

int res2[maxn][maxn];
int f[maxn][maxn];

int getcolors(int i, int j, int tgt)
{
    int mask = 0;
    f[i][j] = true;
    fo(d, 4)
    {
        int ii = i + di[d];
        int jj = j + dj[d];
        if (ii >= 0 && jj >= 0 && ii < n && jj < m)
            if (res[ii][jj] == tgt)
            {
                if (!f[ii][jj]) mask |= getcolors(ii, jj, tgt);
            }
            else
            {
                if (res2[ii][jj] != -1) mask |= 1 << res2[ii][jj];
            }
    }
    return mask;
}

void dfs(int i, int j, int tgt, int col)
{
    res2[i][j] = col;
    fo(d, 4)
    {
        int ii = i + di[d];
        int jj = j + dj[d];
        if (ii >= 0 && jj >= 0 && ii < n && jj < m)
            if (res[ii][jj] == tgt && res2[ii][jj] == -1)
                dfs(ii, jj, tgt, col);
    }
}

void renumber()
{
    fo(i, n) fo(j, m) if (res2[i][j] == -1 && res[i][j] != -1)
    {
        int used = getcolors(i, j, res[i][j]);
        int dig;
        for(dig = 0; dig < 10; dig++) if ((used & (1<<dig)) == 0) break;
        dfs(i, j, res[i][j], dig);
    }
}

void solve() {
    scanf("%d%d", &n, &m);
    fo(i, n) scanf("%s", a[i]);
    int cur = 0;
    CLR(res, -1);
    CLR(res2, -1);
    fo(i, n) fo(j, m) if (a[i][j] != '#')
    {
        int ni, nj;
        if (isolated(i, j, ni, nj)) fail();
        res[i][j] = cur;
        res[ni][nj] = cur;
        a[i][j] = '#';
        a[ni][nj] = '#';

        int x, y;
        fo(d, 4)
        {
            int ii = i + di[d];
            int jj = j + dj[d];
            if (ii >= 0 && jj >= 0 && ii < n && jj < m) if (isolated(ii, jj, x, y))
            {
                a[ii][jj] = '#';
                res[ii][jj] = cur;
            }
        }

        fo(d, 4)
        {
            int ii = ni + di[d];
            int jj = nj + dj[d];
            if (ii >= 0 && jj >= 0 && ii < n && jj < m) if (isolated(ii, jj, x, y))
            {
                a[ii][jj] = '#';
                res[ii][jj] = cur;
            }
        }


        cur++;
    }
    renumber();
    //printf("%d %d\n", n, m);
    fo(i, n)
    {
        fo(j, m) if (res2[i][j] == -1) printf("#"); else printf("%d", res2[i][j]);
        //fo(j, m) if (res[i][j] == -1) printf(" #"); else printf("%2d", res[i][j]);
        printf("\n");
    }
}

int main()
{
  //  freopen(infile, "r", stdin);
  //  freopen(outfile, "w", stdout);
    solve();
    return 0;
}