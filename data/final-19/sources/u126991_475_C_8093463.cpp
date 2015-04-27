#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

#define LL long long
#define mod 1000000007
#define REP(i,a,b) for (int i = a; i <= b; ++i)
#define FOR(i,a,b) for (int i = a; i < b; ++i)

#define mxn 1005

char s[1005][1005], t[1005][1005];

int cal(int sx, int sy, int n, int m, int lenx, int leny) {
    //cout << sx << " " << sy << " " << lenx << " " << leny << endl;
    memset(s, '.', sizeof(s));
    FOR(i, 0, lenx) FOR(j, 0, leny) s[sx + i][sy + j] = 'X';
    while (true) {
        //cout << sx << " " << sy << " " << t[sx + lenx][sy] << endl;
        if (sx + lenx < n && t[sx + lenx][sy] == 'X') {
            FOR(i, 0, leny) s[sx + lenx][sy + i] = 'X';
            ++sx;
            continue;
        }
        if (sy + leny < m && t[sx][sy + leny] == 'X') {
            FOR(i, 0, lenx) s[sx + i][sy + leny] = 'X';
            ++sy;
            continue;
        }
        break;
    }
    FOR(i, 0, n) FOR(j, 0, m) if (s[i][j] != t[i][j]) return 0x3f3f3f3f;
    return lenx * leny;
}

int solve(int n, int m) {
    int sx = -1, sy = -1;
    FOR(i, 0, n) {
        FOR(j, 0, m) if (t[i][j] == 'X') {
            sx = i, sy = j;
            break;
        }
        if (sx != -1) break;
    }
    int lenx = 1, leny = 1;
    while (sx + lenx < n && t[sx + lenx][sy] == 'X') ++lenx;
    while (sy + leny < m && t[sx][sy + leny] == 'X') ++leny;
    if (n - sx == lenx) return cal(sx, sy, n, m, lenx, 1);
    int ll = 0;
    while (ll < m && t[sx + lenx][ll] == '.') ++ll;
    if (ll == m) return cal(sx, sy, n, m, lenx, 1);
    return cal(sx, sy, n, m, lenx, sy + leny - ll);
}

int main()
{
    int n, m;
    cin >> n >> m;
    FOR(i, 0, n) scanf("%s", t[i]);
    int ans = solve(n, m);
    FOR(i, 0, n) FOR(j, 0, m) s[j][i] = t[i][j];
    swap(n, m);
    FOR(i, 0, n) FOR(j, 0, m) t[i][j] = s[i][j];
    ans = min(ans, solve(n, m));
    if (ans == 0x3f3f3f3f) ans = -1;
    printf("%d\n", ans);
    return 0;
}