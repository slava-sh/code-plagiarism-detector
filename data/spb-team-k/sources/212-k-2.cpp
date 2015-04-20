#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int n, m;
int mas[300][300], used[300][300];

bool check(int x, int y)
{
    return ((x >= 0) && (x <= 300) && (y >= 0) && (y <= 300));
}

int main()
{
    freopen("tictactoe.in", "r", stdin);
    freopen("tictactoe.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n + 10; i++)
        for(int j = 0; j < m + 10; j++)
        {
            mas[i][j] = 0;
            used[i][j] = 0;
        }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            char a;
            cin >> a;
            if(a == 'X')
                mas[i][j] = 1;
            else if(a == '0')
                mas[i][j] = 2;
        }
    }
    int col = 0;
    for(int x = 1; x <= n; x++)
    {
        for(int y = 1; y <= m; y++)
        {
            for(int dx = -1; dx < 2; dx++)
            {
                for(int dy = -1; dy < 2; dy++)
                {
                    if((dx != 0) || (dy != 0))
                    {
                        int col1 = 0;
                        int col2 = 0;
                        for(int q = 0; q < 5; q++)
                        {
                            if(check(x + dx * q, y + dy * q))
                            {
                                if(mas[x + dx * q][y + dy * q] == 1)
                                    col1++;
                                else if(mas[x + dx * q][y + dy * q] == 0)
                                    col2++;
                            }
                            else
                                col2++;
                        }
                        if((col1 == 4) && (col2 == 1))
                        {
                            int xx, yy;
                            for(int q = 0; q < 5; q++)
                            {
                                if(check(x + dx * q, y + dy * q))
                                    if(mas[x + dx * q][y + dy * q] == 0)
                                    {
                                        xx = x + dx * q;
                                        yy = y + dy * q;
                                    }
                                else
                                {
                                    xx = x + dx * q;
                                    yy = y + dy * q;
                                }
                            }
                            if(check(xx, yy))
                            {
                                if(used[xx][yy] == 0)
                                    col++;
                                used[xx][yy] = 1;
                            }
                            else
                                col++;
                        }
                    }
                }
            }
        }
    }
    if(col > 0)
    {
        cout << col;
        return 0;
    }

    for(int i = 0; i < n + 10; i++)
        for(int j = 0; j < m + 10; j++)
            used[i][j] = 0;
    col = 0;
    int xxx, yyy;
    for(int x = 1; x <= n; x++)
    {
        for(int y = 1; y <= m; y++)
        {
            for(int dx = -1; dx < 2; dx++)
            {
                for(int dy = -1; dy < 2; dy++)
                {
                    if((dx != 0) || (dy != 0))
                    {
                        int col1 = 0;
                        int col2 = 0;
                        for(int q = 0; q < 5; q++)
                        {
                            if(check(x + dx * q, y + dy * q))
                            {
                                if(mas[x + dx * q][y + dy * q] == 2)
                                    col1++;
                                else if(mas[x + dx * q][y + dy * q] == 0)
                                    col2++;
                            }
                            else
                                col2++;
                        }
                        if((col1 == 4) && (col2 == 1))
                        {
                            int xx, yy;
                            for(int q = 0; q < 5; q++)
                            {
                                if(check(x + dx * q, y + dy * q))
                                    if(mas[x + dx * q][y + dy * q] == 0)
                                    {
                                        xx = x + dx * q;
                                        yy = y + dy * q;
                                    }
                                else
                                {
                                    xx = x + dx * q;
                                    yy = y + dy * q;
                                }
                            }
                            xxx = xx;
                            yyy = yy;
                            if(check(xx, yy))
                            {
                                if(used[xx][yy] == 0)
                                    col++;
                                used[xx][yy] = 1;
                            }
                            else
                                col++;
                        }
                    }
                }
            }
        }
    }
    if(col > 2)
    {
        cout << 0;
    }
    else if(col == 1)
    {
        int qwe = 0;
        mas[xxx][yyy] = 1;
        int col1 = 0, col2 = 0;
        for(int i = 0; i < n + 10; i++)
            for(int j = 0; j < m + 10; j++)
                used[i][j] = 0;
        for(int x = 0; x <= n + 1; x++)
        for(int y = 0; y <= m + 1; y++)
        for(int dx = -1; dx < 2; dx++)
        {
            for(int dy = -1; dy < 2; dy++)
            {
                if((dx != 0) || (dy != 0))
                {
                    int col1 = 0, col2 = 0;
                    int xx, yy;
                    for(int q = 0; q < 5; q++)
                    {
                        if(check(x + dx * q, y + dy * q))
                        {
                            if(mas[x + dx * q][y + dy * q] == 1)
                                col1++;
                            else if(mas[x + dx * q][y + dy * q] == 0)
                            {
                                col2++;
                                xx = x + dx * q;
                                yy = y + dy * q;
                            }
                        }
                        else
                        {
                            col2++;
                            xx = x + dx * q;
                            yy = y + dy * q;
                        }
                    }
                    if((col1 == 4) && (col2 == 1))
                    {
                        if(check(xx, yy))
                        {
                            if(used[xx][yy] == 0)
                                qwe++;
                            used[xx][yy] = 1;
                        }
                        else
                            qwe++;
                    }
                }
            }
        }
        if(qwe > 0)
            cout << 1;
        else
            cout << 0;
    }
    if(col == 0)
    {
        int ans = 0;
        for(int i = 0; i < n + 10; i++)
            for(int j = 0; j < m + 10; j++)
                used[i][j] = 0;
        for(int x = 0; x <= n + 1; x++)
        {
            for(int y = 0; y <= m + 1; y++)
            {
                for(int dx = -1; dx < 2; dx++)
                {
                    for(int dy = -1; dy < 2; dy++)
                    {
                        if((dx != 0) || (dy != 0))
                        {
                            int xx, yy;
                            if(check(x + dx * 4, y + dy * 4))
                            {
                                int col = 0, col2 = 0;
                                for(int q = 0; q < 4; q++)
                                {
                                    if(mas[x + dx * q][y + dy * q] == 1)
                                        col++;
                                    else
                                        if(mas[x + dx * q][y + dy * q] == 0)
                                        {
                                            xx = x + dx * q;
                                            yy = y + dy * q;
                                            col2++;
                                        }
                                }
                                int cnt1, cnt2;
                                if (check(x - dx, y - dy))
                                    cnt1 = mas[x - dx][y - dy];
                                    else
                                        cnt1 = 0;
                                if (check(x + 5 * dx, y + 5 * dy))
                                    cnt2 = mas[x + 5 * dx][y + 5 * dy];
                                    else
                                        cnt2 = 0;
                                if((col == 3) && (col2 == 1) && (cnt1 == 0) && (cnt2 == 0))
                                {
                                    if(used[xx][yy] == 0)
                                        ans++;
                                    used[xx][yy] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << ans;
    }
    return 0;
}
