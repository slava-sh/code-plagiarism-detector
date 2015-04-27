#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;


vector <string> a;
vector <vector <int> > cnt;
int n,m;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
vector <int> can(10,0);


void color(int i, int j, int v=0)
{
    if (a[i][j] != '.')
        throw 4242;
    a[i][j] = 'x';
    cnt[i][j] = 0;
    for(int k = 0; k < 4; k ++)
    {
        int x = dx[k]+i;
        int y = dy[k]+j;
        if (x < 0 || y < 0 || x >= n || y >= m)
            continue;
        if (a[x][y] != '.')
        {
            if (a[x][y] != '#' && a[x][y] != 'x')
                can[a[x][y]-'0'] = false;
            continue;
        }
        if (cnt[x][y] == 1 || v == 0)
        {
            color(x,y,1);
            v ++;
        }
        else
            cnt[x][y] --;
    }
}

void recolor(int i, int j, char v)
{
    if (a[i][j] != 'x')
        return;
    a[i][j] = v;
    for(int k = 0; k < 4; k ++)
    {
        int x = dx[k]+i;
        int y = dy[k]+j;
        if (x < 0 || y < 0 || x >= n || y >= m)
            continue;
        recolor(x,y,v);
    }
}

int main()
{
    cin >> n >> m;
    a.resize(n);
    cnt.assign(n,vector <int> (m,0));
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
        {
            for(int k = 0; k < 4; k ++)
            {
                if (a[i][j] =='#')
                    continue;
                int x = dx[k]+i;
                int y = dy[k]+j;
                if (x < 0 || y < 0 || x >= n || y >= m)
                    continue;
                if (a[x][y] != '#')
                    cnt[i][j] ++;
            }
            if (cnt[i][j] == 0 && a[i][j] =='.')
            {
                cout << -1;
                return 0;
            }
        }

    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
        {
            can.assign(10,1);
            if (a[i][j] == '.')
                color(i,j);
            for (int k = 0; k < 10; k ++)
                if (can[k])
                    recolor(i,j,k + '0');
        }
    for (int i = 0; i < n; i ++)
        cout << a[i] << endl;
    return 0;
}
