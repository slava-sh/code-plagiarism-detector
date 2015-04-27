#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
#define sz(A) (int((A).size()))

const int maxn = 1100;
char table[maxn][maxn];
char chtable[maxn][maxn];
int n, m;

bool good(int sx, int sy, int fx, int fy)
{
    if (sx == fx || sy == fy)
        return 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            chtable[i][j] = '.';

    for (int i = sx; i < fx; i++)
        for (int j = sy; j < fy; j++)
            chtable[i][j] = 'X';

    while (true)
    {
        bool flag1 = (fx < n && table[fx][sy] == 'X');
        bool flag2 = (fy < m && table[sx][fy] == 'X');

        if (flag1 && flag2)
            return 0;
        else if (flag1)
        {
            for (int i = sy; i < fy; i++)
                chtable[fx][i] = 'X';
            fx++;
            sx++;
        }
        else if (flag2)
        {
            for (int i = sx; i < fx; i++)
                chtable[i][fy] = 'X';
            fy++;
            sy++;
        }
        else
            break;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (chtable[i][j] != table[i][j])
                return 0;
    return 1;
}

int main()
{
    cin >> n >> m;
    int sx = -1, sy = -1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];

            if (table[i][j] == 'X' && sx == -1)
                sx = i, sy = j;
        }
    int fx = sx, fy = sy;

    while (fx < n && table[fx][sy] == 'X')
        fx++;

    while (fy < m && table[sx][fy] == 'X')
        fy++;

    int len1 = 1, len2 = 1;

    if (fx < n)
    {
        while (table[fx][fy - len2] == 'X')
            len2++;
    }
    if (fy < m)
    {
        while (table[fx - len1][fy] == 'X')
            len1++;
    }
    len1--, len2--;
    vector <int> vars;

    if (good(sx, sy, fx, sy + len2))
        vars.push_back((fx - sx) * len2);
    if (good(sx, sy, sx + len1, fy))
        vars.push_back(len1 * (fy - sy));
    if (good(sx, sy, sx + 1, fy))
        vars.push_back(fy - sy);
    if (good(sx, sy, fx, sy + 1))
        vars.push_back(fx - sx);
    cout << (vars.empty() ? -1 : *min_element(vars.begin(), vars.end())) << '\n';
}
