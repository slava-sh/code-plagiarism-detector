#include <iostream>
#include <cstdio>

using namespace std;

int min (int a, int b) {
    if (a < b) return a;
    else return b;
}

int main () {
    //freopen ("prizes.in", "r", stdin);
    //freopen ("prizes.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if (n == 1) {
            if (m < 3) cout << 0;
            else {
                m  -= 3;
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
        int ans = 0;
        int t = min (n, m) - 3;
        if (t <= 0) t = 0;
        else ans = 1;
        ans += t / 4;
        cout << ans;
    }
}
