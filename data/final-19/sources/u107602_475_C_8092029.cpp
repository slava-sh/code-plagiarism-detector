#include <iostream>
using namespace std;

int grid[1234][1234];


int sum(int i, int j, int h, int w)
{
    return grid[i + h - 1][j + w - 1] - grid[i - 1][j + w - 1] 
        - grid[i + h - 1][j - 1] + grid[i - 1][j - 1];
}

int check(int x, int y, int i, int j)
{
    if(sum(i, j, x, y) != x * y)
        return -1;

    int dx = 0;
    int dy = 0;

    while(sum(i + x - 1 + dx + 1, j, 1, 1))
        dx++;
    while(sum(i, j + y - 1 + dy + 1, 1, 1))
        dy++;
    if(dx && dy)
        return -1;

    if(sum(i + dx, j + dy, x, y) != x * y)
        return -1;

    int ret = 0;
    if(dx || dy)
    {
        ret = check(x, y, i + dx, j + dy) ;
        if(ret == -1)
            return -1;
        ret += (x + dx) * (y + dy) - x * y;
    }
    else
        ret = x * y;

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    int sx = 0, sy;
    int total = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
        {
            char c;
            cin >> c;
            if(c == 'X')
            {
                grid[i][j] = 1;
                total++;
                if(!sx)
                {
                    sx = i;
                    sy = j;
                }
            }
        }
    for(int i = 0; i < 1234; i++)
        for(int j = 1; j < 1234; j++)
            grid[i][j] += grid[i][j - 1];
    for(int i = 1; i < 1234; i++)
        for(int j = 0; j < 1234; j++)
            grid[i][j] += grid[i - 1][j];

    int x = 1;
    int y = 1;
    while(sum(sx, sy, x + 1, 1) == (x + 1))
        x++;
    while(sum(sx, sy, 1, y + 1) == y + 1)
        y++;

    int ans = -1;
    for(int i = 1; i <= x; i++)
    {
        int ret = check(i, y, sx, sy);
        if(ret != -1 && ret == total)
            if(ans == -1 || ans > i * y)
                ans = i * y;
    }
    for(int j = 1; j <= y; j++)
    {
        int ret = check(x, j, sx, sy);
        if(ret != -1 && ret == total)
            if(ans == -1 || ans > x * j)
                ans = x * j;
    }
    cout << ans << '\n';


    return 0;
}
