#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int inf = 1e4;
int a[100001];

int main()
{
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    int i,n, sum = 0, d,mx1 = -1, mx2 = -1,max1 = -1,max2 = -1,pos1 = -1,pos2 = -1,kol = 0;
    cin >> n >> d;
    for (i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] <= 2 * d)
        {
            if (a[i] > max1)
                max1 = a[i];
            a[i] = inf;
            kol++;
        }
        if (a[i] > 2 * d && a[i] <= 3 * d)
        {
            if (a[i] >= mx1)
            {
                if (pos2 >= 0)
                {
                    a[pos2] = inf;
                    kol++;
                }
                if (a[i] > max1)
                    max1 = a[i];
                mx2 = mx1;
                pos2 = pos1;
                pos1 = i;
                mx1 = a[i];
            }
            else
            if (a[i] > mx2)
            {
                if (pos2 >= 0)
                {
                    a[pos2] = inf;
                    kol++;
                }
                if (a[i] > max1)
                    max1 = a[i];
                mx2 = a[i];
                pos2 = i;
            }
        }
    }
    if (kol == n)
    {
        cout << max1;
        return 0;
    }
    cout << pos1 << pos2;
    if (pos2 >= 0)
        sum = a[pos1] + a[pos2] - 2 * d;
    //else
      //  sum -= 2 * d;
    if (pos2 == -1 && pos1 >= 0)
        sum = a[pos1];
    if (pos1 == -1)
        sum = 2 * d;
    for (i = 0; i < n; i++)
        if (a[i] != inf && a[i] > 3 * d)
            sum += a[i] - 2 * d;
    cout << sum;
    //for (i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
