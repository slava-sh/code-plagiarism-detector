#include <bits/stdc++.h>

using namespace std;

int x = 0, y = 0;

bool arr[3000][3000];

bool go(char c, int n)
{
    char d;
    bool p = 0;
    for(int i=0;i<n;i++)
    {
        if(c == 'U')
        {
            y--;
        }
        if(c == 'D')
        {
            y++;
        }
        if(c == 'R')
        {
            x++;
        }
        if(c == 'L')
        {
            x--;
        }
        p = arr[x][y];
        arr[x][y] = 1;
        cout << c << endl;
        cin >> d;
        if(d != 'N')
            exit(0);
    }
    return p;
}

void gotox(int nx)
{
    if(nx > x)
    {
        go('R', nx - x);
    }
    else
    {
        go('L', x - nx);
    }
}
void gotoy(int ny)
{
    if(ny > y)
    {
        go('D', ny - y);
    }
    else
    {
        go('U', y - ny);
    }
}

void gotovis(char c)
{
    if(c == 'U')
    {
        while(y && !go('U', 1));
    }
    if(c == 'L')
    {
        while(x && !go('L', 1));
    }
}

void checksq(int s)
{
    gotox(0);
    gotoy(s);
    int t = 1;
    gotovis('U');
    while(t <= s)
    {
        go('R', 1);
        gotovis('U');
        gotoy(s / t);
        t++;
    }
}

int main()
{
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    for(int s=2;s<=2048;s<<=1)
    {
        checksq(s);
    }
    return 0;
}
