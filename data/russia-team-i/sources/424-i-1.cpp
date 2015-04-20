#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    freopen("sochi.in","rt",stdin);
    freopen("sochi.out","wt",stdout);
    int n,d,s,x,y;
    s = 0;
    scanf("%d %d",&n,&d);
    int a[n+1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    x = 0;
    y = 0;
    s = a[n];
    if (a[n] > d)
        {
            x = 1;
            y = 1;
        }

    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] < d) break;
        if (i == n - 1)
        {
            if (x == 1 && a[i] - 2 * d > 0)
            {
                s += a[i] - 2 * d;
                if (a[n] - d < 2 * d) y = 0;
                if (a[i] - d < 2 * d) x = 0;
            }
            else break;
        }
        else
            {
                if (x == 1 && a[i] - 2 * d > 0)
                {
                    s = s + a[i] - 2*d;
                    if (a[i] < 3 * d) x = 0;
                }
                else if (y == 1 && a[i] - 2 * d > 0)
                {
                    s = s + a[i] - 2 * d;
                    if (a[i] < 3 * d) y = 0;
                }
                else break;
            }
    }
    cout << s;
    return 0;

}
