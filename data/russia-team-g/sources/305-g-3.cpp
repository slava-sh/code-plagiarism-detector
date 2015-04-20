#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if(min(n, m) == 1)
        cout << (max(n, m) + 1) / 4;
    else
        cout << (min(n, m) + 1) / 4;
    return 0;
}
