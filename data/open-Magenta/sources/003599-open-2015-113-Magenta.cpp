#include <bits/stdc++.h>

using namespace std;

int x = 0, y = 0;

void go(char c, int n)
{
    char d;
    if(c == 'U')
    {
        y-= n;
    }
    if(c == 'D')
    {
        y+= n;
    }
    if(c == 'R')
    {
        x+= n;
    }
    if(c == 'L')
    {
        x-= n;
    }
    for(int i=0;i<n;i++)
    {
        cout << c << endl;
        cin >> d;
        if(d != 'N')
            exit(0);
    }
}

void gotoxy(int nx, int ny)
{
    if(nx > x)
    {
        go('R', nx - x);
    }
    else
    {
        go('L', x - nx);
    }
    if(ny > y)
    {
        go('D', ny - y);
    }
    else
    {
        go('U', y - ny);
    }
}

void checksq(int s)
{
    gotoxy(0, 0);
    int t = 1;
    while(t <= s)
    {
        go('D', s / t);
        go('U', s / t);
        go('R', 1);
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
