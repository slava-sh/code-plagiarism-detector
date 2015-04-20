#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);

    long long a, b, k, t;
    cin >> a >> b;
    k = min(a, b);
    t = max(a, b);
    if(k > 1)
    {
        if(k == 2)
            cout << "0";
        else
            cout << "1";
    }
    else
    {
        if(t > 3)
            cout << (t - 3) / 4ll + 1;
        else if(t == 3)
            cout << 1;
        else
            cout << 0;
    }
    return 0;
}
