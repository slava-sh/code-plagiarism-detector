#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

int m, n, x;

int main ()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    cin >> n >> m;
    x = 0;
    if ((m == 1) && (n == 1))
        {
            cout << 0;
            return 0;
        }
    if ((m == 2) || (n == 2))
    {
        cout << 0;
    }
    else
    {
        if ((n == 1) || (m == 1))
        {
            if (n == 1)
            {
                m -= 3;
                x++;
                cout << (x += m / 4);
            }
            if (m == 1)
            {
                n -= 3;
                x++;
                cout << (x += n / 4);
            }
        }
        else
        {
            cout << 1;
        }
    }
    return 0;
}
