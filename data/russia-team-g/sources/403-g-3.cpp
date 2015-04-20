#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    int m,n;
    cin >> n >> m;
    if (n > m) swap(n, m);
    if (n == 1) cout << (m + 1) / 4;
    else cout << (min(n, m) + 1) / 4;
    return 0;
}
