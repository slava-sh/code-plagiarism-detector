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
        cout << a << ' ' << b << endl;
        return 0;
    }

    int cur = (int)sqrt(a * b) + 1;
    while ((a * b) % cur != 0) {
        --cur;
    }

    cout << cur << ' ' << (a * b) / cur << endl;

    return 0;
}
