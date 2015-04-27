#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>
#include <string.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define pi 3.1415926535897932

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

#define NMAX 1005

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
char a[NMAX][NMAX];
int used[NMAX][NMAX];
int ITER = 0;

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
bool one(int x, int y)
{
    if (!valid(x, y) || a[x][y] != '.') return false;

    forn(k, 4)
    {
        if (valid(x + dx[k], y + dy[k]) && a[x + dx[k]][y + dy[k]] == '.') return false;
    }
    return true;
}

int dfs_mask(int x, int y)
{
    if (!valid(x, y) || a[x][y] == '#' || a[x][y] == '.' || used[x][y] == ITER) return 0;
    used[x][y] = ITER;
    if (a[x][y] >= '0' && a[x][y] <= '9') return (1 << int(a[x][y] - '0'));

    int mask = 0;
    forn(i, 4)
    {
        mask |= dfs_mask(x + dx[i], y + dy[i]);
    }
    return mask;
}

void dfs_color(int x, int y, char c)
{
    if (!valid(x, y) || a[x][y] != '*') return;
    a[x][y] = c;

    forn(i, 4) dfs_color(x + dx[i], y + dy[i], c);
}
int main()
{
 
    
    scanf("%d %d\n", &n, &m);
    forn(i, n)
    {
        forn(j, m)
        {
            scanf("%c", &a[i][j]);
        }
        scanf("\n");
    }

    forn(i, n)
    {
        forn(j, m)
        {
            if (a[i][j] != '.') continue;

            if (one(i, j))
            {
                cout << -1 << endl;
                return 0;
            }

            if (i < n - 1 && a[i + 1][j] == '.')
            {
                a[i][j] = '*';
                a[i + 1][j] = '*';
                if (one(i, j + 1)) a[i][j + 1] = '*';
                if (one(i + 1, j - 1)) a[i + 1][j - 1] = '*';
                if (one(i + 1, j + 1)) a[i + 1][j + 1] = '*';
                if (one(i + 2, j)) a[i + 2][j] = '*';
            }
            else
            {
                assert(j < m - 1 && a[i][j + 1] == '.');
                a[i][j] = '*';
                a[i][j + 1] = '*';
                if (one(i, j + 2)) a[i][j + 2] = '*';
                if (one(i + 1, j)) a[i + 1][j] = '*';
                if (one(i + 1, j + 1)) a[i + 1][j + 1] = '*';
            }

            ITER++;
            int mask = dfs_mask(i, j);
            forn(c, 10)
            {
                if (!(mask & (1 << c)))
                {
                    dfs_color(i, j, '0' + c);
                    break;
                }
            }
        }
    }

    forn(i, n)
    {
        forn(j, m)
        {
            printf("%c", a[i][j]);
        }        
        printf("\n");
    }
    return 0;
}