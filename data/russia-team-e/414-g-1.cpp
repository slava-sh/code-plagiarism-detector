#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = (int)3e5 + 10;

int a[N];

int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    int a, b;
    cin >> a >> b;
    a = min(a, b);
    if (a == 1 || a == 2){
            cout << 0 << endl;
            return 0;
    }
    cout << (a - 2) / 4 + 1 << endl;
    return 0;
}
