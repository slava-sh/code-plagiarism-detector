#if 1
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ios>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;

typedef long long LL;
typedef pair<int, int> ii;

#define mp(x, y) make_pair(x, y)
#define sz(v) (int) ((v).size())
#define rep(i, n) for (int i = 0; i < n; i++)
#define repb(i, n) for (int i = n, i >= 0; i--)
#define fori(i, b, e) for (int i = b; i < e; i++)
#define forb(i, b, e) for (int i = b; i >= e; i--)

void solve();
int main()
{
#ifdef __HOME__
    freopen("../1.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    solve();
    return 0;
}

#endif

int R;
vector<ii> head, tail;
int H[300][300];

int Dp(ii u)
{
    if (u.first + u.second > R)
        return 0;
    if (H[u.first][u.second] != -1)
        return H[u.first][u.second];

    int& r = H[u.first][u.second] = 0;

    // head
    int lim = min(u.first, sz(head));
    rep(i, lim)
    {
        ii v(u.first - i - 1 + head[i].first, u.second + head[i].second);
        r = max(r, Dp(v) + 1);
    }

    // tail
    lim = min(u.second, sz(tail));
    rep(i, lim)
    {
        ii v(u.first + tail[i].first, u.second - i - 1 + tail[i].second);
        r = max(r, Dp(v) + 1);
    }
    return r;
}

void dfs(ii u)
{
    H[u.first][u.second] = 1;

    // head
    int lim = min(u.first, sz(head));
    rep(i, lim)
    {
        ii v(u.first - i - 1 + head[i].first, u.second + head[i].second);
        if (v.first + v.second > R)
            continue;
        if (H[v.first][v.second] == 1)
        {
            cout << "Draw\n";
            exit(0);
        }
        if (H[v.first][v.second] == 0)
            dfs(v);
    }

    // tail
    lim = min(u.second, sz(tail));
    rep(i, lim)
    {
        ii v(u.first + tail[i].first, u.second - i - 1 + tail[i].second);
        if (v.first + v.second > R)
            continue;
        if (H[v.first][v.second] == 1)
        {
            cout << "Draw\n";
            exit(0);
        }
        if (H[v.first][v.second] == 0)
            dfs(v);
    }

    H[u.first][u.second] = 2;
}

void solve()
{
    int h, t;
    cin >> h >> t >> R;

    int N;
    cin >> N;
    rep(i, N)
    {
        int a, b;
        cin >> a >> b;
        head.push_back(ii(a, b));
    }

    int M;
    cin >> M;
    rep(i, M)
    {
        int a, b;
        cin >> a >> b;
        tail.push_back(ii(a, b));
    }

    // can win ?
    memset(H, -1, sizeof(H));
    H[h][t] = 0;
    deque<ii> Q;
    Q.push_back(ii(h, t));
    while (!Q.empty())
    {
        ii u = Q.front();
        Q.pop_front();
        int h = H[u.first][u.second] + 1;

        // head
        int lim = min(u.first, sz(head));
        rep(i, lim)
        {
            ii v(u.first - i - 1 + head[i].first, u.second + head[i].second);
            if (v.first + v.second > R)
                continue;
            if (H[v.first][v.second] == -1)
            {
                H[v.first][v.second] = h;
                Q.push_back(v);
            }
        }

        // tail
        lim = min(u.second, sz(tail));
        rep(i, lim)
        {
            ii v(u.first + tail[i].first, u.second - i - 1 + tail[i].second);
            if (v.first + v.second > R)
                continue;
            if (H[v.first][v.second] == -1)
            {
                H[v.first][v.second] = h;
                Q.push_back(v);
            }
        }
    }

    if (H[0][0] != -1)
    {
        cout << "Ivan\n";
        cout << H[0][0] << '\n';
        return;
    }

    // Draw
    memset(H, 0, sizeof(H));
    dfs(mp(h, t));

    // Lose
    memset(H, -1, sizeof(H));
    cout << "Zmey\n";
    cout << Dp(mp(h, t)) << '\n';
}
