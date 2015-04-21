#include <bits/stdc++.h>
using namespace std;

int x = 1, y = 1;
void tr(int dx, int dy)
{
    x+=dx;
    y+=dy;
    char a;
    if (dx==1)
    {
        a = 'R';
    } else if (dx==-1) a = 'L';
    else if (dy==1) a = 'U';
    else if (dy==-1) a = 'D';
    cout << a << "\n";
    cout.flush();
    char r;
    cin >> r;
    if (r=='Y'||r=='E') exit(0);
}

int getmi[7000] = {};

void go(int tx, int ty)
{
    while (tx<x)
        tr(-1, 0);

    while (tx>x)
        tr(1, 0);

    while (ty>y)
        tr(0, 1);

    while (ty<y)
        tr(0, -1);




}

void doit(int ms, int t)
{
    if (t)
    for (int i=1; i<=ms; i++)
    {
        if (i%2) go(i, ms/i); else go(i, getmi[i] + 1);
        getmi[i] = ms / i;
    }
    else
    {

    for (int i=ms; i>=1; i--)
    {
        if ((ms-i+1)%2) go(i, ms/i); else go(i, getmi[i] + 1);
        getmi[i] = ms / i;
    }
    }
}

int main()
{
    for (int i=10, t=1; 1; i=min(i*2, 6000), t++)
        doit(i, t%2);


}
