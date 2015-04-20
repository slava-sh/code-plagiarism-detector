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
            int x1, x2;
            if (m < 3) x1 = 0;
            else {
                x1 = 1;
                x1 += (m - 3) / 4;
            }
            if (n < 3) x2 = 0;
            else {
                x2 = 1;
                x2 += (n - 3) / 4;
            }
            cout << min (x1, x2);
    }
}
