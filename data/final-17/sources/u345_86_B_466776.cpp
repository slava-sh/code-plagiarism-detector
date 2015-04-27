#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define X first
#define Y second

using namespace std;

typedef unsigned int uint;
typedef unsigned char byte;
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
typedef pair<ld, ld> ptd;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

const int N = 1000 + 13;

int n, m;
char a[N][N];

int ans[N][N];

int cnt = 0, sz[N * N];
vector<int> g[N * N];

char col[N * N];

inline void paint(int v)
{
    int used[10];
    memset(used, 0, sizeof(used));
    
    forn(i, sz(g[v]))
        if (col[g[v][i]] != -1)
            used[col[g[v][i]] - '0'] = true;
            
    forn(i, 10)
        if (!used[i])
        {
            col[v] = '0' + i;
            
            return;
        }
        
    throw;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    srand(uint(time(NULL)));

    memset(ans, -1, sizeof(ans));
    
    cin >> n >> m;
    
    forn(i, n)
    {
        scanf("%s", a[i]);
        
        /*forn(j, m)
            if (rand() & 1)
                a[i][j] = '.';
            else
                a[i][j] = '.';*/
    }
        
    forn(x, n)
        forn(y, m)
        {
            if (a[x][y] == '#' || ans[x][y] != -1)
                continue;
                
            int d1 = -1, d2 = -1;
            
            forn(k, 4)
            {
                int xx = x + dx[k], yy = y + dy[k];
                
                if (correct(xx, yy, n, m) && a[xx][yy] != '#')
                {
                    if (ans[xx][yy] == -1)
                        d1 = k;
                    else
                    {
                        if (d2 == -1 || sz[ans[xx][yy]] < sz[ans[x + dx[d2]][y + dy[d2]]])
                            d2 = k;
                    }
                }
            }
            
            if (d1 != -1)
            {
                ans[x][y] = ans[x + dx[d1]][y + dy[d1]] = cnt;
                sz[cnt] = 2;
                cnt++;
            }
            else if (d2 != -1)
            {
                ans[x][y] = ans[x + dx[d2]][y + dy[d2]];
                
                if (++sz[ans[x][y]] > 5)
                {
                    puts("-1");
                    
                    return 0;
                }
            }
            else
            {
                puts("-1");
                
                return 0;
            }
        }
        
    forn(x, n)
        forn(y, m)
            if (ans[x][y] != -1)
            {
                forn(k, 4)
                {
                    int xx = x + dx[k], yy = y + dy[k];
                    
                    if (correct(xx, yy, n, m) && ans[xx][yy] != -1 && ans[xx][yy] != ans[x][y])
                        g[ans[x][y]].pb(ans[xx][yy]);
                }
            }
            else
                assert(a[x][y] == '#');
                
    memset(col, -1, sizeof(col));
                
    forn(i, cnt)
        paint(i);
        
    forn(i, n)
    {
        forn(j, m)
            if (ans[i][j] != -1)
                putchar(col[ans[i][j]]);
            else
                putchar('#');
                
        puts("");
    }
    
    return 0;
}
