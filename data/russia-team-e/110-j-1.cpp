#include <fstream>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

struct my
{
    int x, y, n;
    my (int X = 0, int Y = 0, int N = 0) : x(X), y(Y), n(N) {}
};

int main()
{
    ifstream cin("travel.in");
    ofstream cout("travel.out");
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int w, h, n, sx, sy;
    cin >> w >> h >> n;
    swap(w, h);
    char Map[w][h];
    vector<vector<int> > Dist(w, vector<int>(h, -1));
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
        {
            cin >> Map[i][j];
            if (Map[i][j] == 'V')
            {
                sx = i;
                sy = j;
            }
        }
    queue<my> Q;
    Q.push(my(sx, sy, 0));
    while (!Q.empty())
    {
        my now = Q.front();
        Q.pop();
        if (Dist[now.x][now.y] == -1)
        {
            Dist[now.x][now.y] = now.n;
            for (int i = 0; i < 4; i++)
                if (now.x + dx[i] >= 0 && now.x + dx[i] < w && now.y + dy[i] >= 0 && now.y + dy[i] < h)
                    Q.push(my(now.x + dx[i], now.y + dy[i], now.n + 1));
        }
    }
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
            for (int k = 0; k < 4; k++)
                if (Map[i][j] == 'T' && i + dx[k] >= 0 && i + dx[k] < w && j + dy[k] >= 0 && j + dy[k] < h && (Map[i + dx[k]][j + dy[k]] == 'T' || Map[i + dx[k]][j + dy[k]] == 'Z'))
                    Map[i][j] = 'Z';
    int x1 = 1000000, y1 = 1000000, x2 = 1000000, y2 = 1000000;
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
        {
            if (Map[i][j] == 'T' && abs(i - sx) + abs(j - sy) < abs(x1 - sx) + abs(y1 - sy))
            {
                x1 = i;
                y1 = j;
            }
            else if (Map[i][j] == 'Z' && abs(i - sx) + abs(j - sy) < abs(x2 - sx) + abs(y2 - sy))
            {
                x2 = i;
                y2 = j;
            }
        }
    int ans1 = abs(x1 - sx) + abs(y1 - sy) + 2 * (n - 1), ans2 = abs(x2 - sx) + abs(y2 - sy) + n - 1;
    if (ans1 < ans2)
    {
        for (int i = 0; i < abs(x1 - sx); i++)
            cout << (x1 < sx ? 'N' : 'S');
        for (int i = 0; i < abs(y1 - sy); i++)
            cout << (y1 < sy ? 'W' : 'E');
        if (x1 < sx)
            for (int i = 0; i < n - 1; i++)
                cout << "SN";
        else if (x1 > sx)
            for (int i = 0; i < n - 1; i++)
                cout << "NS";
        else if (y1 < sy)
            for (int i = 0; i < n - 1; i++)
                cout << "EW";
        else
            for (int i = 0; i < n - 1; i++)
                cout << "WE";
    }
    else
    {
        for (int i = 0; i < abs(x2 - sx); i++)
            cout << (x2 < sx ? 'N' : 'S');
        for (int i = 0; i < abs(y2 - sy); i++)
            cout << (y2 < sy ? 'W' : 'E');
        int num;
        for (int i = 0; i < 4; i++)
            if (x2 + dx[i] >= 0 && x2 + dx[i] < w && y2 + dy[i] >= 0 && y2 + dy[i] < h && Map[x2 + dx[i]][y2 + dy[i]] == 'Z')
                num = i;
        for (int i = 0; i < (n - 1) / 2; i++)
            cout << (num ? (num > 1 ? (num > 2 ? "EW" : "SN") : "WE") : "NS");
        if ((n - 1) & 1)
            cout << (num ? (num > 1 ? (num > 2 ? "E" : "S") : "W") : "N");
    }
    return 0;
}
/*
5 3 6
AAATA
VAATA
AAAAT
*/
