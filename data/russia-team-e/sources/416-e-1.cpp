#include <iostream>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;

int n, i, j, f, b, k, m, z, s, qq[25], w;
bool a[1010][100010];
char q[25];

int main ()
{
    freopen ("numbers.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    //ofstream cout("dwarfs.out");
    for (i=1; i<=999; i++)
        for (j=100; j<=99999; j++)
            a[i][j]=false;
    scanf ("%d", &n);
    for (i=1; i<=n; i++)
    {
        scanf ("%d %d", &f, &k);
        for (j=1; j<=k; j++)
        {
            scanf ("%d", &b);
            a[f][b]=true;
        }
    }
    scanf ("%d", &m);
    for (i=1; i<=m; i++)
    {
        bool test=false;
        scanf ("%c", &q[0]);
        for (j=1; j<=11; j++) scanf ("%c", &q[j]);
        for (j=1; j<=11; j++) qq[j]=int(q[j])-'0';
        for (j=1; j<=3; j++)
        {
            f=qq[1];
            if (j>1) f=f*10+qq[2];
            if (j==3) f=f*10+qq[3];
            for (z=3; z<=5; z++)
            {
                s=qq[j+1]*100+qq[j+2]*10+qq[j+3];
                if (z>=4) s=s*10+qq[j+4];
                if (z==5) s=s*10+qq[j+5];
                if (a[f][s] && test==false && qq[j+z+1]!=0)
                {
                    vector <char> lol;
                    printf ("+");
                    printf ("%d(", f);
                    printf ("%d)", s);
                    for (w=j+z+1; w<=11; w++) lol.push_back(q[w]);
                    if (lol.size()%2==0)
                    {
                        printf ("%c%c-%c%c", lol[0], lol[1], lol[2], lol[3]);
                        if (lol.size()==6) printf ("-%c%c", lol[4], lol[5]);
                    }
                    else
                    {
                        printf ("%c%c%c", lol[0], lol[1], lol[2]);
                        if (lol.size()>3) printf ("-%c%c", lol[3], lol[4]);
                        if (lol.size()>5) printf ("-%c%c", lol[5], lol[6]);
                    }
                    printf ("\n");
                    test=true;
                }
            }
        }
        if (test==false)
            printf ("Incorrect\n");
    }
    return 0;
}
