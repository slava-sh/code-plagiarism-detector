#include <iostream>
#include <math.h>
#include <stdio.h>

#define ll long long

using namespace std;

bool isPrime(int x) {
    if (x <= 3)
        return true;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    freopen("gcm.in", "r", stdin);
    freopen("gcm.out", "w", stdout);
    ll a, b;

    cin >> a >> b;

    if (isPrime(a) && isPrime(b)) {
        cout << min(a, b) << ' ' << max(b, a) << endl;
        return 0;
    }

    int cur = (int)sqrt(a * b) + 1;
    while ((a * b) % cur != 0) {
        --cur;
    }

    int cur2 = (a * b) / cur;
    cout << min(cur, cur2) << ' ' << max(cur, cur2) << endl;

    return 0;
}
