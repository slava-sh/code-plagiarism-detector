#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

const int Q = int(1e9) + 2;
const int W = 20;

bool z;
long long a1, c1, b1, nod, nok, a[W], b[W], x[W], la, lb, lx, ly, a2, b2, p, ans1, ans2, x5, y5;

int main()
{
    freopen("gcm.in", "r", stdin);
    freopen("gcm.out", "w", stdout);
    cin >> a1 >> b1;
    if(a1 > b1)
    {
        c1 = a1;
        a1 = b1;
        b1 = c1;
    }
    a2 = a1;
    b2 = b1;
    while(a2 != 0)
    {
        c1 = b2 % a2;
        b2 = a2;
        a2 = c1;
    }
    a1 = a1 / b2;
    b1 = b1 / b2;
    nod = b2;
    for(int i = 2; i < sqrt(Q); i++)
    {
        a[la] = 1;
        z = 0;
        while((a1 >= i) && ((a1 % i) == 0))
        {
            z = 1;
            a1 = a1 / i;
            a[la] = a[la] * i;
        }
        if (z)
            la++;
    }
    lb = 0;
    for(int i = 2; i < sqrt(Q); i++)
    {
        b[lb] = 1;
        z = 0;
        while((b1 >= i) && ((b1 % i) == 0))
        {
            z = 1;
            b1 = b1 / i;
            b[lb] = b[lb] * i;
        }
        if (z)
            lb++;
    }
    //cout<<la << " " << lb << "\n";
    for(int i = 0; i < la; i++)
    {
        x[i] = a[i];
    }
    for(int i = la; i < (la + lb); i++)
    {
        x[i] = b[i - la];
    }
   /* for(int i = 0; i < (la  + lb); i++)
        cout << x[i] << " ";
    cout << "\n";*/
    p = 1 << (la + lb);
    ans2 = Q;
    //cout << p << " ";
    for(int i = 0; i < p; i++)
    {
        x5 = 1;
        y5 = 1;
        for(int j = 0; j < (la + lb); j++)
        {
            //cout << (i >> j) % 2 <<  " ";
            if((i >> j) % 2)
                x5 *= x[j];
            else
                y5 *= x[j];
        }
        //cout << " ";
        if (abs(x5 - y5) < abs(ans1 - ans2))
        {
            ans1 = x5;
            ans2 = y5;
        }
    }
    cout << min(ans1, ans2) * nod << " " << max(ans1, ans2) * nod;

    return 0;
}
