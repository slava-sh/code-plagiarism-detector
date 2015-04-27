#pragma comment(linker, "/STACK:10000000")

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define debug(x) {cerr << #x << " = " << x << endl;}
template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = (int)1E9 + 7;
const ld EPS = 1E-9;
const ld PI = 3.1415926535897932384626433832795;

const int NMAX = 1100;

int n, m;
char s[NMAX][NMAX];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool in(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

int flag = 1;
int used[NMAX][NMAX], C[NMAX*NMAX];

int ans[NMAX][NMAX], u1[NMAX][NMAX], u2[NMAX][NMAX];
int cs[20];

void calc(int x, int y, int c, int u[NMAX][NMAX]){
    ans[x][y] = c;
    u[x][y] = true;

    forn(i, 4){
        int nx = x + dx[i], ny = y + dy[i];
        if(in(nx, ny) && s[nx][ny] == '.'){
            if(used[nx][ny] == used[x][y]){
                if(!u[nx][ny])
                    calc(nx, ny, c, u);
            }else{
                if(ans[nx][ny] != -1)
                    cs[ans[nx][ny]] = true;
            }
        }    
    }

}

int main() {
    ///freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    scanf("%d%d", &n, &m);
    gets(s[0]);
    forn(i, n)
        gets(s[i]);

    forn(i, n){
        forn(j, m){
            int cnt = 0;
            forn(k, 4){
                int ni = i + dx[k], nj = j + dy[k];
                if(in(ni, nj) && s[ni][nj] == '.')
                    cnt++;
            }    
            if(cnt == 0 && s[i][j] == '.'){
                puts("-1");
                exit(0);
            }
        }
    }
    
    forn(i, n){
        forn(j, m){
            if(s[i][j] == '.' && used[i][j] == 0){
                bool was = false;
                forn(k, 4){
                    int ni = i + dx[k], nj = j + dy[k];
                    if(in(ni, nj) && s[ni][nj] == '.' && used[ni][nj] == 0){

                        C[flag] = 2;
                        used[i][j] = used[ni][nj] = flag;
                        flag++;

                        was = true;
                        break;
                    }
                }

                if(!was){
                    forn(k, 4){
                        int ni = i + dx[k], nj = j + dy[k];
                        if(in(ni, nj) && s[ni][nj] == '.' && C[used[ni][nj]] != 5){
                            int cflag = used[ni][nj];

                            C[cflag]++;
                            used[i][j] = cflag;

                            was = true;
                            break;
                        }
                    }    
                    assert(was);
                }
            }        
        }
    }

    memset(ans, -1, sizeof ans);
    forn(i, n){
        forn(j, m){
            if(ans[i][j] == -1){
                memset(cs, 0, sizeof cs);
                calc(i, j, -1, u1);
                forn(k, 10)
                    if(!cs[k]){
                        calc(i, j, k, u2);
                        break;
                    }
            }                        
        }
    }

    forn(i, n){
        forn(j, m){
            if(s[i][j] != '.')
                printf("%c", s[i][j]);
            else
                printf("%c", char(ans[i][j]+'0'));
        }
        puts("");
    }

    return 0;
}

