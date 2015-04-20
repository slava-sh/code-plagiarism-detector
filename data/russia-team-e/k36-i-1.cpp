#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    freopen ("sochi.in", "r", stdin);
    freopen ("sochi.out", "w", stdout);

    int n, d;
    int n1 = 0, n2 = 0;
    int a1[100001];
    int a2[100001];
    long long ans = 0;

    cin >> n >> d;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(a <= 2 * d)
            continue;
        if(a >= 3 * d)
        {
            a1[n1] = a;
            n1++;
        }
        else
        {
            a2[n2] = a;
            n2++;
        }
    }
    int max1, max2;
    if(n2 == 2)
    {
        max1 = a2[0];
        max2 = a2[1];

        ans = ans + max1 - d + max2 - d;

        for(int i = 0; i < n1; i++)
            ans = ans + (ans = ans + max1 - d + max2 - d;

        for(int i = 0; i < n1; i++)
            ans = ans + (a1[i] - 2 * d);a1[i] - 2 * d);
    }
    else if(n2 == 1)
    {
        max1 = a2[0];

        if(n1 == 0)
            ans = max1;
        else
        {
            ans = ans + max1 - d + a1[0] - d;
            for(int i = 1; i < n1; i++)
                ans = ans + (a1[i] - 2 * d);
        }
    }
    else if(n2 == 0)
    {
        if(n1 == 1)
            ans = a1[0];
        else
        {
            ans = a1[0] - d + a1[1] - d;
            for(int i = 2; i < n1; i++)
                ans = ans + (a1[i] - 2 * d);
        }
    }
    else
    {
        int imax = 0;
        for(int i = 1; i < n2; i++)
            if(a2[i] > a2[imax])
                imax = i;
        max1 = a2[imax];
        a2[imax] = 0;
        imax = 0;
        for(int i = 1; i < n2; i++)
            if(a2[i] > a2[imax])
                imax = i;
        max2 = a2[imax];

        ans = ans + max1 - d + max2 - d;
        for(int i = 0; i < n1; i++)
            ans = ans + (a1[i] - 2 * d);
    }

    cout << ans << endl;

    return 0;
}
