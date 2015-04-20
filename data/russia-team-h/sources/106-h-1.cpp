#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <queue>

#define x first
#define y second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = (int)5005 + 7;
const int INF = 1e9 + 5;

int n, m;
int id[N];

int pr[N], d[N];
bool b[N];
int a[N][N];

int main()
{
    freopen("secure.in", "r", stdin);
    freopen("secure.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        d[i] = INF;
        cin >> id[i];
        if (id[i] == 1)
        {
            d[i] = 0;
            pr[i] = i;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        x--, y--;
        a[x][y] = a[y][x] = c;
    }

    while (true)
    {
        pii p = mp(INF, -1);
        for (int i = 0; i < n; i++)
            if (!b[i] && d[i] < p.x)
                p = mp(d[i], i);

        if (p.y == -1) break;
        b[p.y] = true;

        for (int i = 0; i < n; i++)
            if (a[p.y][i] && p.x + a[p.y][i] < d[i])
            {
                d[i] = p.x + a[p.y][i];
                pr[i] = pr[p.y];
            }

    }

    int mx = INF;
    pii ans = mp(0, 0);

    for (int i = 0; i < n; i++)
        if (id[i] == 2 && mx > d[i])
        {
            mx = d[i];
            ans = mp(pr[i], i);
        }

    if (mx == INF) cout << -1 << endl;
    else cout << ans.x + 1 << " " << ans.y + 1 << " " << mx << endl;

    return 0;
}
