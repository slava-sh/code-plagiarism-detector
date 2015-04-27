#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <cstring>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>

#include <iostream>
#include <sstream>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-8;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 1100;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, m, ans[MAXN][MAXN];
vector<pair<int, int> > p[MAXN * MAXN];
char a[MAXN][MAXN];

inline bool valid(int x, int y) {
    return (0 <= x && x < n) && (0 <= y && y < m);
}

int used[13], cu = 0;

inline void paint(vector<pair<int, int> > &l) {
    cu++;
    forn(i, l.size()) {
        int x = l[i].first, y = l[i].second;
        forn(j, 4) {
            int xx = x + dx[j], yy = y + dy[j];
            if (valid(xx, yy) && ('0' <= a[xx][yy] && a[xx][yy] <= '9'))
                used[a[xx][yy] - '0'] = cu;
        }
    }

    int cur = -1;
    forn(i, 10)
        if (used[i] != cu)
            cur = i;

    forn(i, l.size())
        a[l[i].first][l[i].second] = cur + '0';
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    cin >> n >> m;
    forn(i, n)
        scanf(" %s", a[i]);

    int num = 0;
    vector<pair<int, int> > l;
    memset(ans, 255, sizeof ans);
    forn(i, n)
        forn(j, m) {
            if (ans[i][j] != -1 || a[i][j] != '.') continue;

            bool ok = false;
            forn(k, 4) {
                int x = i + dx[k], y = j + dy[k];
                if (valid(x, y) && a[x][y] == '.' && ans[x][y] == -1) {
                    ans[i][j] = ans[x][y] = num++;
                    ok = true;
                    break;
                }
            }

            if (!ok)
                l.pb(mp(i, j));
        }

    forn(i, l.size()) {
        bool ok = false;
        int x = l[i].first, y = l[i].second;
        forn(j, 4) {
            int xx = x + dx[j], yy = y + dy[j];
            if (valid(xx, yy) && a[xx][yy] == '.') {
                ok = true;
                ans[x][y] = ans[xx][yy];
                break;
            }
        }

        if (!ok) {
            cout << "-1" << endl;
            return 0;
        }
    }

    forn(i, n)
        forn(j, m)
            if (ans[i][j] != -1)
                p[ans[i][j]].pb(mp(i, j));

    forn(i, num)
        paint(p[i]);

    forn(i, n) {
        forn(j, m)
            printf("%c", a[i][j]);

        printf("\n");
    }

    return 0;
}
