#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    if(min(n, m) == 1)
        cout << (max(n, m) + 1) / 4;
    else
    {
        long long p = (min(n, m) + 1) / 4;
        if(p > 2)
            p = 2;
        cout << p;
    }
    return 0;
}
