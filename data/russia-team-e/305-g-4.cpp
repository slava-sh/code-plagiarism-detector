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
        printf("%lld", (max(n, m) + 1) / 4);
    else
        printf("%lld", (min(n, m) + 1) / 4);
    return 0;
}
