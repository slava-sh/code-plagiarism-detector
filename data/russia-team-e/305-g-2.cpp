#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    cout << (min(n, m) + 1) / 4;
    return 0;
}
