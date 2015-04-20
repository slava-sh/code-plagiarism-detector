#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    int m,n;
    cin >> n >> m;
    cout << (max(n, m) + 1) / 4;
    return 0;
}
