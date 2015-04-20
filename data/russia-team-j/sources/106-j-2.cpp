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
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = (int)500 + 7;
const int INF = 2e9 + 5;
const int MOD = 1e9 + 7;

const int X[4] = {0, 1, 0, -1};
const int Y[4] = {1, 0, -1, 0};

int n, m, cnt;
char a[N][N];

int d[N][N];
bool b[N][N];
pii pr[N][N];

queue <pii> q;

bool ok(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

string s;
pii t;

void rec(int x, int y)
{
    if (t.x == x && t.y == y)
        return;

    int x2 = pr[x][y].x;
    int y2 = pr[x][y].y;

    char c;

    if (x2 - x == 1)
        s += 'N';
    if (x - x2 == 1)
        s += 'S';

    if (y2 - y == 1)
        s += 'W';
    if (y - y2 == 1)
        s += 'E';

    rec(x2, y2);
}

int main()
{
    //freopen("travel.in", "r", stdin);
    //freopen("travel.out", "w", stdout);

    cin >> m >> n >> cnt;
    gets(a[0]);
    for (int i = 0; i < n; i++)
        gets(a[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 'V')
                t = mp(i, j);

    b[t.x][t.y] = true;
    q.push(t);
    //cout << "T = " << t.x << " " << t.y << endl;
    while (!q.empty())
    {
        pii p = q.front();

        q.pop();

        //cout << p.x << " " << p.y << endl;

        for (int i = 0; i < 4; i++)
        {
            int x1 = p.x + X[i];
            int y1 = p.y + Y[i];

            //cout << x1 << " " << y1 << endl;
            if (!ok(x1, y1)) continue;
            if (abs(x1 - t.x) + abs(y1 - t.y) <= abs(p.x - t.x) + abs(p.y - t.y))
                continue;
            //cout << "TRUE" << endl;

            if (!b[x1][y1])
                q.push(mp(x1, y1));
            b[x1][y1] = true;

            if (d[p.x][p.y] + (a[x1][y1] == 'T') >= d[x1][y1])
            {
                d[x1][y1] = d[p.x][p.y] + (a[x1][y1] == 'T');
                pr[x1][y1] = mp(p.x, p.y);
            }
        }
    }

    int ans = INF;

    /*
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << d[i][j] << ' ';
    cout << endl;
    */

    pii p;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 'T')
            {
                ans = min(ans, abs(i - t.x) + abs(j - t.y) + max(0, cnt - d[i][j]) * 2);

                if (ans == abs(i - t.x) + abs(j - t.y) + max(0, cnt - d[i][j]) * 2)
                    p = mp(i, j);

                bool f = false;
                for (int k = 0; k < 4 && !f; k++)
                {
                    int x1 = i + X[k];
                    int y1 = j + Y[k];

                    if (!ok(x1, y1)) continue;
                    if (a[x1][y1] != 'T') continue;

                    f = true;
                    ans = min(ans, abs(i - t.x) + abs(j - t.y) + max(0, cnt - d[i][j]));

                    if (ans == abs(i - t.x) + abs(j - t.y) + max(0, cnt - d[i][j]))
                        p = mp(i, j);
                }
            }
    rec(p.x, p.y);
    cout << s;

    int id = -1;
    bool w = false;
    for (int i = 0; i < 4; i++)
    {
        int x1 = p.x + X[i];
        int y1 = p.y + Y[i];

        if (!ok(x1, y1)) continue;

        if (!w)
            id = i;

        if (a[x1][y1] == 'T')
            w = true;
    }

    ans -= (int)s.size();


    int f = false;
    while (ans > 0)
    {
        int z = id;
        if (f)
            z = (z + 2) % 4;

        if (z == 0)
            cout << 'E';
        if (z == 1)
            cout << 'S';
        if (z == 2)
            cout << 'W';
        if (z == 3)
            cout << 'N';

        f = !f;
        ans--;
    }

    return 0;
}

/*
3 1 2
TVT

5 3 6
AAATA
VAATA
AAAAT

9
1 2
1 3
3 7
7 9
7 8
4 5
4 6
1 4
3 5

9
1 2
2 3
3 4
4 5
5 6
6 7
5 8
8 9
7 1

8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8

6
1 2
2 3
3 4
4 5
5 6
4 5

*/
