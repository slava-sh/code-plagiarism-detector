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
   for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
            for (int k = 0; k < 4; k++)
                if (Map[i][j] == 'T' && i + dx[k] >= 0 && i + dx[k] < w && j + dy[k] >= 0 && j + dy[k] < h && (Map[i + dx[k]][j + dy[k]] == 'T' || Map[i + dx[k]][j + dy[k]] == 'Z'))
                    Map[i][j] = 'Z';
    int x1 = 10000000, y1 = 10000000, rx2 = 10000000, ry2 = 10000000, x2, y2, nowans = 100000000;
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
    x2 = w - 1;
    y2 = h - 1;
    vector<vector<int> > D(x2 - sx + 2, vector<int>(y2 - sy + 2, 0));
    for (int i = 0; i <= x2 - sx; i++)
        for (int j = 0; j <= y2 - sy; j++)
            D[i + 1][j + 1] = max(D[i][j + 1], D[i + 1][j]) + (Map[sx + i][sy + j] == 'T');
    for (int i = 0; i <= x2 - sx; i++)
        for (int j = 0; j <= y2 - sy; j++)
            if (Map[sx + i][sy + j] == 'Z' && i + j + n - 1 - D[i][j] < nowans)
            {
                nowans = i + j + n - 1 - D[i][j];
                rx2 = sx + i;
                ry2 = sy + j;
            }
    y2 = 0;
    D.clear();
    D.resize(x2 - sx + 2, vector<int>(sy - y2 + 2, 0));
    for (int i = 0; i <= x2 - sx; i++)
        for (int j = 0; j <= sy - y2; j++)
            D[i + 1][j + 1] = max(D[i][j + 1], D[i + 1][j]) + (Map[sx + i][sy - j] == 'T');
    for (int i = 0; i <= x2 - sx; i++)
        for (int j = 0; j <= sy - y2; j++)
            if (Map[sx + i][sy - j] == 'Z' && i + j + n - 1 - D[i][j] < nowans)
            {
                nowans = i + j + n - 1 - D[i][j];
                rx2 = sx + i;
                ry2 = sy - j;
            }
    x2 = 0;
    y2 = h - 1;
    D.clear();
    D.resize(sx - x2 + 2, vector<int>(y2 - sy + 2, 0));
    for (int i = 0; i <= sx - x2; i++)
        for (int j = 0; j <= y2 - sy; j++)
            D[i + 1][j + 1] = max(D[i][j + 1], D[i + 1][j]) + (Map[sx - i][sy + j] == 'T');
    for (int i = 0; i <= sx - x2; i++)
        for (int j = 0; j <= y2 - sy; j++)
            if (Map[sx - i][sy + j] == 'Z' && i + j + n - 1 - D[i][j] < nowans)
            {
                nowans = i + j + n - 1 - D[i][j];
                rx2 = sx - i;
                ry2 = sy + j;
            }
    y2 = 0;
    D.clear();
    D.resize(sx - x2 + 2, vector<int>(sy - y2 + 2, 0));
    for (int i = 0; i <= sx - x2; i++)
        for (int j = 0; j <= sy - y2; j++)
            D[i + 1][j + 1] = max(D[i][j + 1], D[i + 1][j]) + (Map[sx - i][sy - j] == 'T');
    for (int i = 0; i <= sx - x2; i++)
        for (int j = 0; j <= sy - y2; j++)
            if (Map[sx - i][sy - j] == 'Z' && i + j + n - 1 - D[i][j] < nowans)
            {
                nowans = i + j + n - 1 - D[i][j];
                rx2 = sx - i;
                ry2 = sy - j;
            }
    x2 = rx2;
    y2 = ry2;
    int ans1 = abs(x1 - sx) + abs(y1 - sy) + 2 * (n - 1);
    if (ans1 < nowans)
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
        string Ans;
        if (x2 >= sx)
        {
            if (y2 >= sy)
            {
                vector<vector<int> > D(x2 - sx + 2, vector<int>(y2 - sy + 2, 0));
                for (int i = 0; i <= x2 - sx; i++)
                    for (int j = 0; j <= y2 - sy; j++)
                        D[i + 1][j + 1] = max(D[i][j + 1], D[i + 1][j]) + (Map[sx + i][sy + j] == 'T');
                int x = x2 - sx + 1, y = y2 - sy + 1;
                while (x != 1 || y != 1)
                {
                    if (Map[sx + x - 1][sy + y - 1] == 'T')
                    {
                        if (D[x - 1][y] == D[x][y] - 1 && x > 1)
                        {
                            Ans += 'S';
                            x--;
                        }
                        else
                        {
                            Ans += 'E';
                            y--;
                        }
                    }
                    else if (D[x - 1][y] == D[x][y] && x > 1)
                    {
                        Ans += 'S';
                        x--;
                    }
                    else
                    {
                        Ans += 'E';
                        y--;
                    }
                }
                n -= D[x2 - sx + 1][y2 - sy + 1];
            }
            else        ///     x2 >= sx    y2 < sy
            {
                vector<vector<int> > D(x2 - sx + 2, vector<int>(sy - y2 + 2, 0));
                for (int i = 0; i <= x2 - sx; i++)
                    for (int j = 0; j <= sy - y2; j++)
                        D[i + 1][j + 1] = max(D[i][j + 1], D[i + 1][j]) + (Map[sx + i][sy - j] == 'T');
                int x = x2 - sx + 1, y = sy - y2 + 1;
                while (x != 1 || y != 1)
                {
                    if (Map[sx + x - 1][sy - y + 1] == 'T')
                    {
                        if (D[x - 1][y] == D[x][y] - 1 && x > 1)
                        {
                            Ans += 'S';
                            x--;
                        }
                        else
                        {
                            Ans += 'W';
                            y--;
                        }
                    }
                    else if (D[x - 1][y] == D[x][y] && x > 1)
                    {
                        Ans += 'S';
                        x--;
                    }
                    else
                    {
                        Ans += 'W';
                        y--;
                    }
                }
                n -= D[x2 - sx + 1][sy - y2 + 1];
            }
        }
        else
        {
            if (y2 >= sy)   ///     x2 < sx    y2 >= sy
            {
                vector<vector<int> > D(sx - x2 + 2, vector<int>(y2 - sy + 2, 0));
                for (int i = 0; i <= sx - x2; i++)
                    for (int j = 0; j <= y2 - sy; j++)
                        D[i + 1][j + 1] = max(D[i][j + 1], D[i + 1][j]) + (Map[sx - i][sy + j] == 'T');
                int x = sx - x2 + 1, y = y2 - sy + 1;
                while (x != 1 || y != 1)
                {
                    if (Map[sx - x + 1][sy + y - 1] == 'T')
                    {
                        if (D[x - 1][y] == D[x][y] - 1 && x > 1)
                        {
                            Ans += 'N';
                            x--;
                        }
                        else
                        {
                            Ans += 'E';
                            y--;
                        }
                    }
                    else if (D[x - 1][y] == D[x][y] && x > 1)
                    {
                        Ans += 'N';
                        x--;
                    }
                    else
                    {
                        Ans += 'E';
                        y--;
                    }
                }
                n -= D[sx - x2 + 1][y2 - sy + 1];
            }
            else        ///     x2 < sx    y2 < sy
            {
                vector<vector<int> > D(sx - x2 + 2, vector<int>(sy - y2 + 2, 0));
                for (int i = 0; i <= sx - x2; i++)
                    for (int j = 0; j <= sy - y2; j++)
                        D[i + 1][j + 1] = max(D[i][j + 1], D[i + 1][j]) + (Map[sx - i][sy - j] == 'T');
                int x = sx - x2 + 1, y = sy - y2 + 1;
                while (x != 1 || y != 1)
                {
                    if (Map[sx - x + 1][sy - y + 1] == 'T')
                    {
                        if (D[x - 1][y] == D[x][y] - 1 && x > 1)
                        {
                            Ans += 'N';
                            x--;
                        }
                        else
                        {
                            Ans += 'W';
                            y--;
                        }
                    }
                    else if (D[x - 1][y] == D[x][y] && x > 1)
                    {
                        Ans += 'N';
                        x--;
                    }
                    else
                    {
                        Ans += 'W';
                        y--;
                    }
                }
                n -= D[sx - x2 + 1][sy - y2 + 1];
            }
        }
        reverse(Ans.begin(), Ans.end());
        cout << Ans;
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
