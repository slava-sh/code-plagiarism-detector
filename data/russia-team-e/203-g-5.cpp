#include <iostream>
#include <cstdio>

using namespace std;

int min (int a, int b) {
    if (a < b) return a;
    else return b;
}

int main () {
    freopen ("prizes.in", "r", stdin);
    freopen ("prizes.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if (n == 1) {
            if (m < 3) cout << 0;
            else {
                m -= 3;
                int x = 1;
                x += m / 4;
                cout << x;
            }
    }
    else if (m == 1) {
            if (n < 3) cout << 0;
            else {
                n -= 3;
                int x = 1;
                x += n / 4;
                cout << x;
            }
    }
    else {
            int x = 0;
            int z = min (n, m);
            int q = min (n, m);
            x += z / 3;
            z %= 3;
            n -= q;
            n += z;
            m -= q;
            m += z;
            cout << x;
    }
}
