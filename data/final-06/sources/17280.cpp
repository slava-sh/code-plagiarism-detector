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

const int N = 30 + 3;

int n, m;
char a[N][N];

int u = 0, used[N][N];
pt neib[N][N];
vector<pt> sq[N][N];

int us[7 + 3], us2[7 + 3][7 + 3];
int ansVal;
int cur[N][N], ans[N][N];

void solve(int x, int y)
{
    if (x == n)
    {
        forn(i, n)
            forn(j, m)
                ans[i][j] = cur[i][j];
                
        ansVal++;
        
        /*forn(i, n)
        {
            forn(j, m)
                cerr << (ans[i][j] == -1? '.': char('0' + ans[i][j]));
                
            cerr << endl;
        }
        
        cerr << endl;
        
        if (ansVal >= 3)
            exit(0);*/
        
        return;
    }
    
    if (y == m)
        return solve(x + 1, 0);
        
    if (a[x][y] == '.' || cur[x][y] != -1)
        return solve(x, y + 1);
        
    int xx = neib[x][y].ft, yy = neib[x][y].sc;
    assert(cur[xx][yy] == -1);
    
    vector< pair<int, pt> > f;
    f.reserve(30);
    
    forn(i, 7)
        forn(j, i + 1)
            forn(k, 2)
            {
                if (us2[i][j])
                    continue;
                    
                if (i == j && k == 1)
                    continue;
                
                int a = i, b = j;
                
                if (k)
                    swap(a, b);
                    
                cur[x][y] = a;
                cur[xx][yy] = b;
                
                bool bad = false;
                
                forn(k, sz(sq[x][y]))
                {
                    int xxx = sq[x][y][k].ft, yyy = sq[x][y][k].sc;
                    
                    if (cur[xxx][yyy] != -1 && cur[xxx][yyy] != cur[x][y])
                        bad = true;
                }
                
                forn(k, sz(sq[xx][yy]))
                {
                    int xxx = sq[xx][yy][k].ft, yyy = sq[xx][yy][k].sc;
                    
                    if (cur[xxx][yyy] != -1 && cur[xxx][yyy] != cur[xx][yy])
                        bad = true;
                }
                
                if (!bad)
                {
                    if (!us[a] || !us[b])
                    {
                        pair<int, pt> cur;
                        cur.sc = mp(a, b);
                        
                        if (!us[a])
                        {
                            if (!us[b])
                                cur.ft = min(a, b);
                            else
                                cur.ft = a;
                        }
                        else
                            cur.ft = b;
                            
                        f.pb(cur);
                    }
                    else
                    {
                        us[i]++, us[j]++;
                        us2[i][j]++;
                        
                        solve(x, y + 1);
                        
                        us2[i][j]--;
                        us[i]--, us[j]--;
                    }
                }
                    
                cur[xx][yy] = -1;
                cur[x][y] = -1;
            }
    
    if (!f.empty())
    {
        int a = min_element(all(f))->sc.ft, b = min_element(all(f))->sc.sc;
            
        cur[x][y] = a;
        cur[xx][yy] = b;
        
        int i = max(a, b), j = min(a, b);
        
        us[i]++, us[j]++;
        us2[i][j]++;
        
        solve(x, y + 1);
        
        us2[i][j]--;
        us[i]--, us[j]--;
            
        cur[xx][yy] = -1;
        cur[x][y] = -1;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    cin >> n >> m;
    
    forn(i, n)
        scanf("%s", a[i]);
        
    forn(x, n)
        forn(y, m)
        {
            int dx[] = { -1, 0, 1, 0 };
            int dy[] = { 0, -1, 0, 1 };
            
            forn(k, 4)
            {
                int xx = x + dx[k], yy = y + dy[k];
                
                if (correct(xx, yy, n, m) && a[xx][yy] == a[x][y])
                    neib[x][y] = mp(xx, yy);
            }
        }
        
    u++;
        
    forn(x, n)
        forn(y, m)
            if (a[x][y] != '.' && used[x][y] != u)
            {
                vector<pt> cur;
                
                int dx[] = { 0, 0, 1, 1 };
                int dy[] = { 0, 1, 0, 1 };
                
                forn(k, 4)
                {
                    int xx = x + dx[k], yy = y + dy[k];
                    
                    assert(correct(xx, yy, n, m) && a[xx][yy] != '.' && used[xx][yy] != u);
                    
                    used[xx][yy] = u;
                    
                    cur.pb(mp(xx, yy));
                }
                
                forn(i, sz(cur))
                    forn(j, sz(cur))
                        if (j != i)
                            sq[cur[i].ft][cur[i].sc].pb(cur[j]);
            }
        
    ansVal = 0;
    memset(ans, -1, sizeof(ans));
    memset(cur, -1, sizeof(cur));
    solve(0, 0);
    
    assert(ansVal > 0);
    
    cout << li(ansVal) * 5040 << endl;
    
    forn(i, n)
    {
        forn(j, m)
            if (ans[i][j] == -1)
                putchar('.');
            else
                putchar('0' + ans[i][j]);
                
        puts("");
    }
    
    return 0;
}
