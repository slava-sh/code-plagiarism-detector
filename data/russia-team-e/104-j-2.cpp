#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cmath>

#define problem "travel"

using namespace std;

const int MAXN = 502;

struct pr {
    int x, y;

    pr (int _x = 0, int _y = 0) : x(_x), y(_y) { }
};

int gr[MAXN][MAXN];
int dp[MAXN][MAXN];

const int INF = int(1e9);

void recnt(pr pos, int x, int y, int n, int m)
{
    for (int i = pos.x; i && i <= n; i += x)
    {
        for (int j = pos.y; j && j <= m; j += y)
        {
//            if (i == pos.x && j == pos.y) continue;
            dp[i + x][j] = max(dp[i + x][j], dp[i][j] + gr[i + x][j]);
            dp[i][j + y] = max(dp[i][j + y], dp[i][j] + gr[i][j + y]);
        }
    }
}

void tr_upd(pr st, pr pos, int & ans, pr & res, int k)
{
    if (dp[pos.x][pos.y] == k) {
        if (abs(pos.x - st.x) + abs(pos.y - st.y) < ans) {
            ans = abs(pos.x - st.x) + abs(pos.y - st.y);
            res = pos;
        }
        return;
    }

    if (gr[pos.x + 1][pos.y] || gr[pos.x - 1][pos.y] || gr[pos.x][pos.y + 1] || gr[pos.x][pos.y - 1]) {
        if (abs(pos.x - st.x) + abs(pos.y - st.y) + (k - dp[pos.x][pos.y]) < ans) {
            ans = abs(pos.x - st.x) + abs(pos.y - st.y) + (k - dp[pos.x][pos.y]);
            res = pos;
        }
    } else {
        if (abs(pos.x - st.x) + abs(pos.y - st.y) + (k - dp[pos.x][pos.y]) * 2 < ans) {
            ans = abs(pos.x - st.x) + abs(pos.y - st.y) + (k - dp[pos.x][pos.y]) * 2;
            res = pos;
        }
    }
}

void get_ans(pr cur, pr st)
{
    if (cur.x == st.x && cur.y == st.y) return;

    int dx = abs(st.x - cur.x), dy = abs(st.y - cur.y);

    int cans = -INF; pr nxt;
    if (abs(st.x - cur.x + 1) < dx && dp[cur.x - 1][cur.y] > cans) {
        cans = dp[cur.x - 1][cur.y];
        nxt = cur; nxt.x -= 1;
    }
    if (abs(st.x - cur.x - 1) < dx && dp[cur.x + 1][cur.y] > cans) {
        cans = dp[cur.x + 1][cur.y];
        nxt = cur; nxt.x += 1;
    }
    if (abs(st.y - cur.y - 1) < dy && dp[cur.x][cur.y + 1] > cans) {
        cans = dp[cur.x][cur.y + 1];
        nxt = cur; nxt.y += 1;
    }
    if (abs(st.y - cur.y + 1) < dy && dp[cur.x][cur.y - 1] > cans) {
        cans = dp[cur.x][cur.y - 1];
        nxt = cur; nxt.y -= 1;
    }
//    cout << nxt.x << " " << nxt.y << endl;
    get_ans(nxt, st);

    dx = nxt.x - cur.x, dy = nxt.y - cur.y;
    if (dx < 0) {
        cout << 'S';
    }
    if (dx > 0) {
        cout << 'N';
    }
    if (dy < 0) {
        cout << 'E';
    }
    if (dy > 0) {
        cout << 'W';
    }
}

int main()
{
    assert(freopen(problem".in", "r", stdin) != NULL);
    assert(freopen(problem".out", "w", stdout));

    int n, m, k;
    cin >> m >> n >> k;

    pr start;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char tmp;
            cin >> tmp;
            dp[i][j] = 0;
            if (tmp == 'T') {
                gr[i][j] = 1;
                continue;
            }

            if (tmp == 'V') start = pr(i, j);
            gr[i][j] = 0;
        }

    for (int i = 0; i <= n + 1; i++)
        dp[i][0] = INF, dp[i][m + 1] = INF;

    for (int i = 0; i <= m + 1; i++)
        dp[0][i] = INF, dp[n + 1][i] = INF;

//    cout << start.x << " " << start.y << endl;

    recnt(start, -1, 1, n, m);
    recnt(start, 1, -1, n, m);
    recnt(start, 1, 1, n, m);
    recnt(start, -1, -1, n, m);

    pr pos;
    int ans = INF;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!gr[i][j] || dp[i][j] > k) continue;
            tr_upd(start, pr(i, j), ans, pos, k);
        }
    }
//    cout << endl;
//    cout << pos.x << " " << pos.y << endl;
//    cout << start.x << " " << start.y << endl;
//    cout << endl;

    get_ans(pos, start);

    k -= dp[pos.x][pos.y];

    if (pos.x - 1 && gr[pos.x - 1][pos.y]) {
        while (k > 1) {
            k -= 2;
            cout << "NS";
        }
        if (k) cout << "N";
        return 0;
    }
    if (pos.x + 1 <= n && gr[pos.x + 1][pos.y]) {
        while (k > 1) {
            k -= 2;
            cout << "SN";
        }
        if (k) cout << "S";
        return 0;
    }
    if (pos.y - 1 && gr[pos.x][pos.y - 1]) {
        while (k > 1) {
            k -= 2;
            cout << "WE";
        }
        if (k) cout << "W";
        return 0;
    }
    if (pos.y + 1 <= m && gr[pos.x][pos.y + 1]) {
        while (k > 1) {
            k -= 2;
            cout << "EW";
        }
        if (k) cout << "E";
        return 0;
    }

    if (pos.x - 1) {
        for (int i = 0; i < k; i++)
            cout << "NS";
        return 0;
    }
    if (pos.x + 1 <= n) {
        for (int i = 0; i < k; i++)
            cout << "SN";
        return 0;
    }
    if (pos.y - 1) {
        for (int i = 0; i < k; i++)
            cout << "WE";
        return 0;
    }
    if (pos.y + 1 <= m) {
        for (int i = 0; i < k; i++)
            cout << "EW";
        return 0;
    }

    return 0;
}
