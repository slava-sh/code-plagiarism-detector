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
    int a, b, c, d;
    cin >> a >> b;
    c = min(a, b);
    d = max(a, b);
     if (c == 1){
            if (d == 1){
                    cout << 0 << endl;
                    return 0;
            }
            cout << (d - 2) / 4 + ((d - 2) % 4 != 0) << endl;
            return 0;
    }
    if (c == 2){
            cout << 0 << endl;
            return 0;
    }
    cout << (c - 2) / 4 + ((c - 2) % 4 != 0) << endl;
    return 0;
}
